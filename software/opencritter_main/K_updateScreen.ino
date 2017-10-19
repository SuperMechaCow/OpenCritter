/*
   THIS is the function that actually handles drawing the screen.

   Do not use this for anything other than drawing to the screen.
   Use the appropirate menu/minigame/animation for changing variables or other actions.

*/

void updateScreen()
{
  switch (selMenu) //selMenu is the
  {
    /*========================================================================================================================*/
    case mainM: // Main Menu
      /*
          This section draws the main menu screen
      */

      //draw icons and both sides of the screen
      display.drawBitmap(8, 0, gfx_icon_clok, 16, 16, 1);       //Left top icon
      display.drawBitmap(8, 16, gfx_icon_stat, 16, 16, 1);      //Left middle upper icon
      display.drawBitmap(8, 32, gfx_icon_food, 16, 16, 1);      //Left middle lower icon
      display.drawBitmap(8, 48, gfx_icon_game, 16, 16, 1);      //Left bottom icon
      display.drawBitmap(104, 0, gfx_icon_pack, 16, 16, 1);     //Right top icon
      display.drawBitmap(104, 16, gfx_icon_conf, 16, 16, 1);    //Right middle upper icon
      display.drawBitmap(104, 32, gfx_icon_poop, 16, 16, 1);    //Right middle lower icon
      if (Alert == true)                                        //If Alert is active, then we draw the right bottom icon, too
        display.drawBitmap(104, 48, gfx_icon_sick, 16, 16, 1);  //Show alert icon
      else                                                      //If Alert is not active
        display.fillRect(104, 48, 16, 16, 0);                   //Erase icon region

      //draw ocCursor
      display.fillRect(0, 0, 8, 64, 0);                         //Erase the left side of the cursor region
      display.fillRect(121, 0, 8, 64, 0);                       //Erase the right side of the cursor region
      //Draw the cursor. This calculation is a little confusing, but it reads the location of the cursor and draws it up, down, left, right accordingly
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

      if (Inventory[inv_meds_slot][inv_owned] > Inventory[inv_meds_slot][inv_acked]) {
        display.fillRect(16, 38, 96, 20, 0);
        display.drawRect(16, 38, 96, 20, 1);
        display.drawBitmap(26, 40, gfx_icon_meds, 16, 16, 1);
        display.setTextColor(1);
        display.setTextSize(1);
        display.setCursor(44, 44);
        display.print(F("+"));
        display.print(Inventory[inv_meds_slot][inv_owned] - Inventory[inv_meds_slot][inv_acked]);
        display.print(F(" Meds!"));
      }
      else if (Inventory[inv_soda_slot][inv_owned] > Inventory[inv_soda_slot][inv_acked]) {
        display.fillRect(16, 38, 96, 20, 0);
        display.drawRect(16, 38, 96, 20, 1);
        display.drawBitmap(26, 40, gfx_icon_soda, 16, 16, 1);
        display.setTextColor(1);
        display.setTextSize(1);
        display.setCursor(44, 44);
        display.print(F("+"));
        display.print(Inventory[inv_soda_slot][inv_owned] - Inventory[inv_soda_slot][inv_acked]);
        display.print(F(" Soda!"));
      }

      break;

    /*========================================================================================================================*/
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
      display.print(F("Breed: "));
      display.print(breed);
      display.setCursor(0, 24);

      //This part needs rewritten
      display.print(F("Lifespan: "));
      display.print(millis() / 1000);

      // Other Stats
      display.setTextSize(1);
      display.setCursor(0, 32);
      display.print(F("Heartbeats: "));
      display.print(heartbeats);
      display.setCursor(0, 40);
      display.print(F("BPM: "));
      updateBPM();
      display.print(hrtBPM);
      display.setCursor(0, 48);
      display.print(F("Metabolism: "));
      display.print(metabolism);
      display.setCursor(0, 56);
      display.print(F("Days Alive: "));
      if (dnow < 10)
        display.print(F("0"));
      display.print(dnow);
      break;

    /*========================================================================================================================*/
    case statsM:
      display.clearDisplay(); // Erase screen
      display.setTextColor(1);
      display.setTextSize(2);
      display.setCursor(0, 0);


      switch (ocCursor) {
        case 0:
          display.fillRect(64, 5, 63, 7, 0);
          display.print(F("Stats"));
          display.setTextSize(1);
          //First Slot <------------------------------------|
          display.setCursor(0, 16);
          display.print(F("Energy: "));
          display.setCursor(88, 16);
          display.print(Energy);
          display.drawRect(0, 24, 128, 5, 1);
          display.drawLine(2, 26, map(Energy, 0, max_energy, 3, 127), 26, 1);
          //Second Slot <------------------------------------|
          display.setCursor(0, 32);
          display.print(F("Health: "));
          display.setCursor(70, 32);
          display.print(getHealth());
          display.print(F(" ("));
          display.print(sick_thresh);
          display.print(F(")"));
          display.drawRect(0, 40, 128, 5, 1);
          display.drawLine(2, 42, map(getHealth(), 0, max_health, 3, 127), 42, 1);
          //Sickness threshold bar
          display.drawLine(map(sick_thresh, 0, 255, 3, 127), 39, map(sick_thresh, 0, 255, 3, 127), 45, 1);
          //Third Slot <------------------------------------|
          display.setCursor(0, 48);
          display.print(F("Power: "));
          display.setCursor(88, 48);
          display.print(getPower());
          //Outer box
          display.drawRect(0, 56, 128, 5, 1);
          //Current power average
          display.drawLine(2, 58, map(getPower(), 0, max_power, 3, 127), 58, 1);
          break;
        case 1:
          display.fillRect(64, 5, 63, 7, 0);
          display.print(F("Energy"));
          display.setTextSize(1);
          //The old mini-bar
          display.drawRect(74, 6, 54, 5, 1);
          display.drawLine(76, 8, map(Energy, 0, 255, 76, 126), 8, 1);
          //First Slot <------------------------------------|
          display.setCursor(0, 16);
          display.print(F("Weight: "));
          display.setCursor(88, 16);
          switch (lifestage) {
            case egged:
              display.print(weight + egg_w);
              break;
            case baby:
              display.print(weight + baby_w);
              break;
            case teen:
              display.print(weight + teen_w);
              break;
            case adult:
              display.print(weight + adult_w);
              break;
            case senior:
              display.print(weight + senior_w);
              break;
          }
          display.drawRect(0, 24, 128, 5, 1); //Meter outline
          display.drawLine(2, 26, map(weight, 0, 10, 3, 127), 26, 1); //Meter value
          display.drawLine(64, 23, 64, 29, 1);
          //Second Slot <------------------------------------|
          display.setCursor(0, 32);
          display.print(F("Metabolism: "));
          display.setCursor(88, 32);
          display.print(metabolism);
          display.drawRect(0, 40, 128, 5, 1);
          display.drawLine(2, 42, map(metabolism, 1, max_metabolism, 127, 3), 42, 1);
          break;
        case 2:
          display.fillRect(64, 5, 63, 7, 0);
          display.print(F("Health"));
          display.setTextSize(1);
          //The old mini-bar
          display.drawRect(74, 6, 54, 5, 1);
          display.drawLine(76, 8, map(getHealth(), 0, max_health, 76, 126), 8, 1);
          //First Slot <------------------------------------|
          display.setCursor(0, 16);
          display.print(F("Hunger: "));
          display.setCursor(88, 16);
          display.print(hun);
          display.drawRect(0, 24, 128, 5, 1); //Meter outline
          display.drawLine(2, 26, map(hun, 0, max_health, 3, 127), 26, 1); //Meter value
          //Second Slot <------------------------------------|
          display.setCursor(0, 32);
          display.print(F("Happiness: "));
          display.setCursor(88, 32);
          display.print(hap);
          display.drawRect(0, 40, 128, 5, 1);
          display.drawLine(2, 42, map(hap, 0, max_health, 3, 127), 42, 1);
          //Third Slot <------------------------------------|
          display.setCursor(0, 48);
          display.print(F("Boredom: "));
          display.setCursor(88, 48);
          display.print(bor);
          display.drawRect(0, 56, 128, 5, 1);
          display.drawLine(2, 58, map(bor, 0, max_health, 3, 127), 58, 1);
          break;
        case 3:
          display.fillRect(64, 5, 63, 7, 0);
          display.print(F("Power"));
          display.setTextSize(1);
          //The old mini-bar
          display.drawRect(74, 6, 54, 5, 1);
          display.drawLine(76, 8, map(getPower(), 0, max_power, 76, 126), 8, 1);
          //First Slot <------------------------------------|
          display.setCursor(0, 16);
          display.print(F("Ath: "));
          display.setCursor(88, 16);
          display.print(Ath);
          display.drawRect(0, 24, 128, 5, 1);
          display.drawLine(2, 26, map(Ath, 0, max_power, 3, 127), 26, 1);
          //Second Slot <------------------------------------|
          display.drawRect(0, 40, 128, 5, 1);
          display.setCursor(0, 32);
          display.print(F("Dis: "));
          display.setCursor(88, 32);
          display.print(Dis);
          display.drawLine(2, 42, map(Dis, 0, max_power, 3, 127), 42, 1);
          //Third Slot <------------------------------------|
          display.setCursor(0, 48);
          display.print(F("Int: "));
          display.setCursor(88, 48);
          display.print(Int);
          display.drawRect(0, 56, 128, 5, 1);
          display.drawLine(2, 58, map(Int, 0, max_power, 3, 127), 58, 1);
          break;
        default:
          break;
      }
      break;

    /*========================================================================================================================*/
    case foodM:
      display.clearDisplay(); //Erase Screen
      display.setTextColor(1);
      display.setTextSize(2);
      display.setCursor(0, 0);
      display.print(F("Food"));
      display.setTextColor(1);
      display.setTextSize(1);
      // x = 0, y = cursor * 16 pixels per two rows + skip 16 pixels, character number 16 (right arrow), foreground, background, size
      display.drawChar(0, (ocCursor * 16) + 16, 16, 1, 0, 1);
      display.setCursor(8, 16);
      display.print(F("Protein"));
      display.setCursor(8, 24);
      display.print(F("  +hun +Wgt"));
      display.setCursor(8, 32);
      display.print(F("Fat"));
      display.setCursor(8, 40);
      display.print(F("  ++hap ++Wgt -Dis"));
      display.setCursor(8, 48);
      display.print(F("Carbs"));
      display.setCursor(8, 56);
      display.print(F("  ++bor ++Wgt -Int"));
      break;

    /*========================================================================================================================*/

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
      display.print(F("Set Clock"));
      display.setCursor(8, 24);
      display.print(F("12-hour mode: "));
      display.print(hour12);
      display.setCursor(8, 32);
      display.print(F("Beeper Mute: "));
      display.print(beepMute);
      display.setCursor(8, 40);
      display.print(F("Rumble Mute: "));
      display.print(rumbleMute);
      display.setCursor(8, 48);
      display.print(F("WiFi Enabled: "));
      display.print(wifiEnabled);
      display.setCursor(8, 56);
      display.print(F("Ver: "));
      display.print(versionnum);
      break;

    /*========================================================================================================================*/
    case playM:
      display.clearDisplay(); //Erase Screen
      display.setTextColor(1);
      display.setTextSize(2);
      display.setCursor(0, 0);
      display.print(F("Games"));
      display.setTextColor(1);
      display.setTextSize(1);
      // x = 0, y = cursor * 16 pixels per two rows + skip 16 pixels, character number 16 (right arrow), foreground, background, size
      display.drawChar(0, (ocCursor * 16) + 16, 16, 1, 0, 1);
      display.setCursor(8, 16);
      display.print(F("Ball Catch"));
      display.setCursor(8, 24);
      display.print(F("  +Ath -Wgt"));
      display.setCursor(8, 32);
      display.print(F("High or Low"));
      display.setCursor(8, 40);
      display.print(F("  +hap +Dis"));
      display.setCursor(8, 48);
      display.print(F("BitShifter"));
      display.setCursor(8, 56);
      display.print(F("  +bor +Int"));
      break;

    /*========================================================================================================================*/

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

    /*========================================================================================================================*/

    case inventM:
      display.clearDisplay();
      display.setTextColor(1);
      display.setTextSize(1);
      display.drawChar(((ocCursor % 4) * 32), ((ocCursor / 4) * 16) + 5, 16 , 1, 0, 1);
      for (int i = 0; i < inv_max_itemtypes; i++) {
        switch (i) {
          case inv_meds_slot:
            display.drawBitmap(((i % 4) * 32) + 4, (i / 4) * 16, gfx_icon_meds, 16, 16, 1);
            display.setCursor(((i % 4) * 32) + 20, ((i / 4) * 16) + 5);
            if (Inventory[inv_meds_slot][inv_owned] < 10)
              display.print(F("0"));
            display.print(Inventory[inv_meds_slot][inv_owned]);
            break;
          case inv_soda_slot:
            display.drawBitmap(((i % 4) * 32) + 4, (i / 4) * 16, gfx_icon_soda, 16, 16, 1);
            display.setCursor(((i % 4) * 32) + 20, ((i / 4) * 16) + 5);
            if (Inventory[inv_soda_slot][inv_owned] < 10)
              display.print(F("0"));
            display.print(Inventory[inv_soda_slot][inv_owned]);
            break;
          default:
            display.drawBitmap(((i % 4) * 32) + 4, (i / 4) * 16, gfx_icon_unon, 16, 16, 1);
            display.setCursor(((i % 4) * 32) + 20, ((i / 4) * 16) + 5);
            display.print("00");
            break;
        }
      }
      break;
  }
  display.display();
}
