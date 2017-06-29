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
      getGFX(icon_clok);
      display.drawBitmap(8, 0, gfxBuffer, 16, 16, 1);
      getGFX(icon_stat);
      display.drawBitmap(8, 16, gfxBuffer, 16, 16, 1);
      getGFX(icon_food);
      display.drawBitmap(8, 32, gfxBuffer, 16, 16, 1);
      getGFX(icon_game);
      display.drawBitmap(8, 48, gfxBuffer, 16, 16, 1);
      getGFX(icon_meds);
      display.drawBitmap(104, 0, gfxBuffer, 16, 16, 1);
      getGFX(icon_conf);
      display.drawBitmap(104, 16, gfxBuffer, 16, 16, 1);
      getGFX(icon_poop);
      display.drawBitmap(104, 32, gfxBuffer, 16, 16, 1);
      getGFX(icon_sick);
      display.drawBitmap(104, 48, gfxBuffer, 16, 16, 1);
      
      //draw ocCursor
      display.fillRect(0, 0, 8, 64, 0);
      display.fillRect(121, 0, 8, 64, 0);
      display.drawChar((ocCursor / 4) * 121, ((ocCursor * 16) % 64) + 4, int(16 + (ocCursor / 4)), 1, 0, 1);
      /* Cursor debugging
        if (debug) {
        Serial.print(int((ocCursor / 4) * 120));
        Serial.print(F(", "));
        Serial.print(int((ocCursor * 16) % 64));
        Serial.print(F(", "));
        Serial.println(int(16 + (ocCursor / 4)));
        } */
      break;
    case clockM: //Clock Menu
      // if (debugMode)
      //   Serial.println(F("Drawing clock"));
      display.fillRect(0, 0, 128, 64, 0);
      // Master Clock
      display.setCursor(16, 0);
      display.setTextColor(1);
      display.setTextSize(2);
      if ((hnow + clockOFFSETh) % 24 < 10)
        display.print(F("0"));
      display.print((hnow + clockOFFSETh) % 24);
      display.print(F(":"));
      if ((mnow + clockOFFSETm) % 60 < 10)
        display.print(F("0"));
      display.print((mnow + clockOFFSETm) % 60);
      display.print(F(":"));
      if ((snow + clockOFFSETs) % 60 < 10)
        display.print(F("0"));
      display.print((snow + clockOFFSETs) % 60);
      // Lifetime clock
      display.setTextColor(1);
      display.setTextSize(1);
      display.setCursor(0, 16);
      display.print(F("Lifespan: "));
      if (hnow < 10)
        display.print(F("0"));
      display.print(hnow);
      display.print(F(":"));
      if (mnow < 10)
        display.print(F("0"));
      display.print(mnow);
      display.print(F(":"));
      if (snow < 10)
        display.print(F("0"));
      display.print(snow);
      // Other Stats
      display.setTextSize(1);
      display.setCursor(0, 24);
      display.print(F("Heartbeats: "));
      display.print(heartbeats);
      display.setCursor(0, 32);
      display.print(F("BPM: "));
      display.print((1 / ((baseHRT_speed * metabolism) / 1000)) * 60);
      display.setCursor(0, 40);
      display.print(F("Days Alive: "));
      if (dnow < 10)
        display.print(F("0"));
      display.print(dnow);
      break;
    case statsM:
      //if (debugMode)
      //  Serial.println(F("Drawing stats"));
      display.fillRect(0, 0, 128, 64, 0); // Erase screen

      // Draw bar outlines
      if (ocCursor <= 1) {
        display.drawRect(0, 24, 128, 5, 1);
        display.drawRect(0, 39, 128, 5, 1);
        display.drawRect(0, 54, 128, 5, 1);
      }

      display.setTextColor(1);
      display.setTextSize(2);

      display.setCursor(0, 0);
      if (ocCursor == 0) {
        display.print(F("Stats"));
      }
      else if (ocCursor == 1) {
        display.print(F("Traits"));
      }
      else {
        display.print(F("BioSpecs"));
      }
      display.setTextSize(1);
      //
      display.setCursor(0, 16);
      if (ocCursor == 0) {
        display.print(F("Hunger: "));
        display.setCursor(88, 16);
        display.print(hunger);
        display.drawLine(2, 26, map(hunger, 0, 255, 3, 127), 26, 1);
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
        display.print(happiness);
        display.drawLine(2, 41, map(happiness, 0, 255, 3, 127), 41, 1);
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
        display.print(boredom);
        display.drawLine(2, 56, map(boredom, 0, 255, 3, 127), 56, 1);
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
      display.fillRect(0, 0, 128, 64, 0); //Erase Screen
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
      display.fillRect(0, 0, 128, 64, 0); //Erase Screen
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
      break;
    case playM:
      display.fillRect(0, 0, 128, 64, 0); //Erase Screen
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
      // if (debugMode)
      //   Serial.println(F("Drawing clock"));
      display.fillRect(0, 0, 128, 64, 0);
      display.setTextColor(1);
      display.setTextSize(2);
      display.setCursor(0, 0);
      display.print(F("Clock Set"));
      display.setCursor(16, 32);
      if ((hnow + clockOFFSETh) % 24 < 10)
        display.print(F("0"));
      display.print((hnow + clockOFFSETh) % 24);
      display.print(F(":"));
      if ((mnow + clockOFFSETm) % 60 < 10)
        display.print(F("0"));
      display.print((mnow + clockOFFSETm) % 60);
      display.print(F(":"));
      if ((snow + clockOFFSETs) % 60 < 10)
        display.print(F("0"));
      display.print((snow + clockOFFSETs) % 60);
      display.setCursor(28 + (32 * ocCursor), 48);
      display.print(F("*"));
      break;
    default:
      break;
  }
  display.display();
}
