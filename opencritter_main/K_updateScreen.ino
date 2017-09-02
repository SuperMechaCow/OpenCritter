
/*
   THIS is the function that actually handles drawing the screen.

   Do not use this for anything other than drawing to the screen.
   Use the appropirate menu/minigame/animation for changing variables or other actions.

*/

void updateScreen()
{
  switch (selMenu)
  {
    case mainM: // Main Menu
      //if (debugMode)
      //  Serial.println(F("Drawing main menu"));
      //draw icons
      //      getGFX(icon_clok); //all of the "getGFX()" are from older EEPROM-reading versions
      display.drawBitmap(8, 0, gfx_icon_clok, 16, 16, 1);
      //      getGFX(icon_stat);
      display.drawBitmap(8, 16, gfx_icon_stat, 16, 16, 1);
      //      getGFX(icon_food);
      display.drawBitmap(8, 32, gfx_icon_food, 16, 16, 1);
      //      getGFX(icon_game);
      display.drawBitmap(8, 48, gfx_icon_game, 16, 16, 1);
      //      getGFX(icon_meds);
      display.drawBitmap(104, 0, gfx_icon_meds, 16, 16, 1);
      //      getGFX(icon_conf);
      display.drawBitmap(104, 16, gfx_icon_conf, 16, 16, 1);
      //      getGFX(icon_poop);
      display.drawBitmap(104, 32, gfx_icon_poop, 16, 16, 1);
      //      getGFX(icon_sick);
      if (Alert)
        display.drawBitmap(104, 48, gfx_icon_sick, 16, 16, 1); //Show alert icon
      else
        display.fillRect(104, 48, 16, 16, 0); //Erase icon region

      //draw ocCursor
      display.fillRect(0, 0, 8, 64, 0);
      display.fillRect(121, 0, 8, 64, 0);
      display.drawChar((ocCursor / 4) * 121, ((ocCursor * 16) % 64) + 4, int(16 + (ocCursor / 4)), 1, 0, 1);

      //draw illnesses
      display.fillRect(32, 0, 64, 16, 0);
      for (byte i = 0; i < sickCount; i++) {
        display.drawBitmap(32 + (i * 16), 0, gfx_icon_sick, 16, 16, 1);
      }

      //draw poops
      display.fillRect(32, 48, 64, 16, 0);
      for (byte i = 0; i < poopCount; i++) {
        display.drawBitmap(32 + (i * 16), 48, gfx_icon_poop, 16, 16, 1);
      }

      break;

    case clockM: //Clock Menu
      display.clearDisplay();
      // Master Clock
      display.setCursor(16, 0);
      display.setTextColor(1);
      display.setTextSize(2);
      if (!hour12) {
        if (hnow % 24 < 10)
          display.print(F("0"));
        display.print(hnow % 24);
      }
      else {
        if (hnow % 12 == 0) {
          display.print(12);
        }
        else {
          if (hnow % 12 < 10)
            display.print(F("0"));
          display.print(hnow % 12);
        }
      }
      display.print(F(":"));
      if (mnow % 60 < 10)
        display.print(F("0"));
      display.print(mnow % 60);
      display.print(F(":"));
      if (snow % 60 < 10)
        display.print(F("0"));
      display.print(snow % 60);
      if (hour12) {
        if (hnow > 11)
          display.print(F("*"));
      }

      // Lifetime clock
      display.setTextColor(1);
      display.setTextSize(1);
      display.setCursor(0, 16);

      //This part needs rewritten
      display.print(F("Lifespan: "));
      display.print(millis() / 1000);

      // Other Stats
      display.setTextSize(1);
      display.setCursor(0, 24);
      display.print(F("Heartbeats: "));
      display.print(heartbeats);
      display.setCursor(0, 32);
      display.print(F("BPM: "));
      updateBPM();
      display.print(hrtBPM);
      display.setCursor(0, 40);
      display.print(F("Days Alive: "));
      if (dnow < 10)
        display.print(F("0"));
      display.print(dnow);
      break;
    case statsM:
      display.clearDisplay(); // Erase screen

      // Draw bar outlines
      if (ocCursor <= 1) {
        display.drawRect(0, 24, 128, 5, 1);
        display.drawRect(0, 39, 128, 5, 1);
        display.drawRect(0, 54, 128, 5, 1);
      }

      //Sickness threshold bar
      byte sickt;
      sickt = map(sick_thresh, 0, 255, 66, 127);
      //Outer box
      display.drawRect(64, 6, 63, 5, 1);
      //Current stats average
      display.drawLine(66, 8, map(((hun + hap + bor) / 3), 0, 255, 66, 127), 8, 1);
      //Stats threshold marker
      display.drawLine(sickt, 5, sickt, 11, 1);

      display.setTextColor(1);
      display.setTextSize(2);

      display.setCursor(0, 0);
      if (ocCursor == 0) {
        display.print(F("Stats"));
      }
      else if (ocCursor == 1) {
        display.fillRect(64, 5, 63, 7, 0);
        display.print(F("Traits"));
      }
      else {
        display.fillRect(64, 5, 63, 7, 0);
        display.print(F("BioSpecs"));
      }
      display.setTextSize(1);
      //
      display.setCursor(0, 16);
      if (ocCursor == 0) {
        display.print(F("Hunger: "));
        display.setCursor(88, 16);
        display.print(hun);
        display.drawLine(2, 26, map(hun, 0, 255, 3, 127), 26, 1);
      }
      else if (ocCursor == 1) {
        display.print(F("Ath: "));
        display.setCursor(88, 16);
        display.print(Ath);
        display.drawLine(2, 26, map(Ath, 0, 100, 3, 127), 26, 1);
      }
      else {
        display.print(F("Weight: "));
        switch (breed) {
          case egg:
            display.print(weight + egg_w);
            break;
          case wibbur:
            display.print(weight + wibbur_w);
            break;
          case snek:
            display.print(weight + snek_w);
            break;
          case tribbur:
            display.print(weight + tribbur_w);
            break;
        }
      }
      //
      display.setCursor(0, 31);
      if (ocCursor == 0) {
        display.print(F("Happiness: "));
        display.setCursor(88, 31);
        display.print(hap);
        display.drawLine(2, 41, map(hap, 0, 255, 3, 127), 41, 1);
      }
      else if (ocCursor == 1) {
        display.print(F("Dis: "));
        display.setCursor(88, 31);
        display.print(Dis);
        display.drawLine(2, 41, map(Dis, 0, 100, 3, 127), 41, 1);
      }
      else {
        display.print(F("Metabolism: "));
        display.print(metabolism);
      }
      //
      display.setCursor(0, 46);
      if (ocCursor == 0) {
        display.print(F("Boredom: "));
        display.setCursor(88, 46);
        display.print(bor);
        display.drawLine(2, 56, map(bor, 0, 255, 3, 127), 56, 1);
      }
      else if (ocCursor == 1) {
        display.print(F("Int: "));
        display.setCursor(88, 46);
        display.print(Int);
        display.drawLine(2, 56, map(Int, 0, 100, 3, 127), 56, 1);
      }
      else {
        display.print(F("Breed: "));
        switch (breed) {
          case egg:
            display.print(F("Egg"));
            break;
          case wibbur:
            display.print(F("Wibbur"));
            break;
          case snek:
            display.print(F("SNEK!!"));
            break;
          case tribbur:
            display.print(F("Tribbur"));
            break;
          default:
            display.print(F("Unknown!"));
            break;
        }
      }
      break;
    case foodM:
      display.clearDisplay(); //Erase Screen
      display.setTextColor(1);
      display.setTextSize(1);
      // x = 0, y = cursor * 8 pixels per row + skip 16 pixels, character number 16 (right arrow), foreground, background, size
      display.drawChar(0, (ocCursor * 8) + 16, 16, 1, 0, 1);
      display.setCursor(8, 16);
      display.print(F("Hunger Food"));
      display.setCursor(8, 24);
      display.print(F("Happy Food"));
      display.setCursor(8, 32);
      display.print(F("Boredom Food"));
      break;
    case confM:
      display.clearDisplay(); //Erase Screen
      display.setTextColor(1);
      display.setTextSize(2);
      display.setCursor(0, 0);
      display.print(F("Config"));
      display.setTextSize(1);
      // x = 0, y = cursor * 8 pixels per row + skip 16 pixels, character number 16 (right arrow), foreground, background, size
      display.drawChar(0, (ocCursor * 8) + 16, 16, 1, 0, 1);
      display.setCursor(8, 16);
      display.print(F("Beeper Mute: "));
      display.print(beepMute);
      display.setCursor(8, 24);
      display.print(F("Beeper Mute: "));
      display.print(buzzMute);
      display.setCursor(8, 32);
      display.print(F("Set Clock"));
      display.setCursor(8, 40);
      display.print(F("12-hour mode: "));
      display.print(hour12);
      break;
    case playM:
      display.clearDisplay(); //Erase Screen
      display.setTextColor(1);
      display.setTextSize(2);
      display.setCursor(0, 0);
      display.print(F("Games"));
      display.setTextColor(1);
      display.setTextSize(1);
      // x = 0, y = cursor * 8 pixels per row + skip 16 pixels, character number 16 (right arrow), foreground, background, size
      display.drawChar(0, (ocCursor * 8) + 16, 16, 1, 0, 1);
      display.setCursor(8, 16);
      display.print(F("High or Low"));
      display.setCursor(8, 24);
      display.print(F("BitShifter"));
      break;
    case c_clockset: //Clock set menu
      display.clearDisplay();
      display.setTextColor(1);
      display.setTextSize(2);
      display.setCursor(0, 0);
      display.print(F("Clock Set"));
      display.setCursor(16, 32);
      if (!hour12) {
        if (hnow % 24 < 10)
          display.print(F("0"));
        display.print(hnow % 24);
      }
      else {
        if (hnow % 12 == 0) {
          display.print(12);
        }
        else {
          if (hnow % 12 < 10)
            display.print(F("0"));
          display.print(hnow % 12);
        }
      }
      display.print(F(":"));
      if (mnow % 60 < 10)
        display.print(F("0"));
      display.print(mnow % 60);
      display.print(F(":"));
      if (snow % 60 < 10)
        display.print(F("0"));
      display.print(snow % 60);
      if (hour12) {
        if (hnow > 11)
          display.print(F("*"));
      }
      display.setCursor(28 + (32 * ocCursor), 48);
      display.print(F("*"));
      break;
    default:
      break;
  }
  display.display();
}