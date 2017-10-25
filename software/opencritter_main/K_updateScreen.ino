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
    case m_main: // Main Menu
      /*
          This section draws the main menu screen
      */

      //draw icons and both sides of the screen
      display.drawBitmap(8, 0, gfx_icon_clok, icon_dimensions, icon_dimensions, 1);       //Left top icon
      display.drawBitmap(8, 16, gfx_icon_stat, icon_dimensions, icon_dimensions, 1);      //Left middle upper icon
      display.drawBitmap(8, 32, gfx_icon_food, icon_dimensions, icon_dimensions, 1);      //Left middle lower icon
      display.drawBitmap(8, 48, gfx_icon_game, icon_dimensions, icon_dimensions, 1);      //Left bottom icon
      display.drawBitmap(104, 0, gfx_icon_pack, icon_dimensions, icon_dimensions, 1);     //Right top icon
      display.drawBitmap(104, 16, gfx_icon_conf, icon_dimensions, icon_dimensions, 1);    //Right middle upper icon
      display.drawBitmap(104, 32, gfx_icon_poop, icon_dimensions, icon_dimensions, 1);    //Right middle lower icon
      if (Alert == true)                                        //If Alert is active, then we draw the right bottom icon, too
        display.drawBitmap(104, 48, gfx_icon_sick, icon_dimensions, icon_dimensions, 1);  //Show alert icon
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
        display.drawBitmap(32 + (i * 16), 0, gfx_icon_sick, icon_dimensions, icon_dimensions, 1);
      }

      //draw poops
      display.fillRect(32, 48, 64, 16, 0);
      for (byte i = 0; i < poopCount; i++) {
        display.drawBitmap(32 + (i * 16), 48, gfx_icon_poop, icon_dimensions, icon_dimensions, 1);
      }

      if (Inventory[inv_meds_slot][inv_owned] > Inventory[inv_meds_slot][inv_acked]) {
        display.fillRect(16, 38, 96, 20, 0);
        display.drawRect(16, 38, 96, 20, 1);
        display.drawBitmap(26, 40, gfx_icon_meds, icon_dimensions, icon_dimensions, 1);
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
        display.drawBitmap(26, 40, gfx_icon_soda, icon_dimensions, icon_dimensions, 1);
        display.setTextColor(1);
        display.setTextSize(1);
        display.setCursor(44, 44);
        display.print(F("+"));
        display.print(Inventory[inv_soda_slot][inv_owned] - Inventory[inv_soda_slot][inv_acked]);
        display.print(F(" Soda!"));
      }
      else if (Inventory[inv_star_slot][inv_owned] > Inventory[inv_star_slot][inv_acked]) {
        display.fillRect(16, 38, 96, 20, 0);
        display.drawRect(16, 38, 96, 20, 1);
        display.drawBitmap(26, 40, gfx_icon_star, icon_dimensions, icon_dimensions, 1);
        display.setTextColor(1);
        display.setTextSize(1);
        display.setCursor(44, 44);
        display.print(F("+"));
        display.print(Inventory[inv_star_slot][inv_owned] - Inventory[inv_star_slot][inv_acked]);
        display.print(F(" Star!"));
      }

      break;

    /*========================================================================================================================*/
    case m_clock: //Clock Menu
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
      display.print(F("Distress: "));
      display.print(distressbeats);
      display.setCursor(0, 56);
      display.print(F("Days Alive: "));
      break;

    /*========================================================================================================================*/
    case m_stats:
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
          if (Inventory[inv_biok_slot][inv_owned] >= 1)
            display.print(Energy);
          display.drawRect(0, 24, 128, 5, 1);
          display.drawLine(2, 26, map(Energy, 0, max_energy, 3, 127), 26, 1);
          //Second Slot <------------------------------------|
          display.setCursor(0, 32);
          display.print(F("Health: "));
          if (Inventory[inv_biok_slot][inv_owned] >= 1) {
            display.setCursor(70, 32);
            display.print(getHealth());
            display.print(F(" ("));
            display.print(sick_thresh);
            display.print(F(")"));
          }
          display.drawRect(0, 40, 128, 5, 1);
          display.drawLine(2, 42, map(getHealth(), 0, max_health, 3, 127), 42, 1);
          //Sickness threshold bar
          display.drawLine(map(sick_thresh, 0, 255, 3, 127), 39, map(sick_thresh, 0, 255, 3, 127), 45, 1);
          //Third Slot <------------------------------------|
          display.setCursor(0, 48);
          display.print(F("Power: "));
          display.setCursor(88, 48);
          if (Inventory[inv_biok_slot][inv_owned] >= 1)
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
          if (Inventory[inv_biok_slot][inv_owned] >= 1) {
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
          }
          display.drawRect(0, 24, 128, 5, 1); //Meter outline
          display.drawLine(2, 26, map(weight, 0, 20, 3, 127), 26, 1); //Meter value
          display.drawLine(64, 23, 64, 29, 1);
          //Second Slot <------------------------------------|
          display.setCursor(0, 32);
          display.print(F("Metabolism: "));
          display.setCursor(88, 32);
          if (Inventory[inv_biok_slot][inv_owned] >= 1)
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
          if (Inventory[inv_biok_slot][inv_owned] >= 1)
            display.print(hun);
          display.drawRect(0, 24, 128, 5, 1); //Meter outline
          display.drawLine(2, 26, map(hun, 0, max_health, 3, 127), 26, 1); //Meter value
          //Second Slot <------------------------------------|
          display.setCursor(0, 32);
          display.print(F("Happiness: "));
          display.setCursor(88, 32);
          if (Inventory[inv_biok_slot][inv_owned] >= 1)
            display.print(hap);
          display.drawRect(0, 40, 128, 5, 1);
          display.drawLine(2, 42, map(hap, 0, max_health, 3, 127), 42, 1);
          //Third Slot <------------------------------------|
          display.setCursor(0, 48);
          display.print(F("Boredom: "));
          display.setCursor(88, 48);
          if (Inventory[inv_biok_slot][inv_owned] >= 1)
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
          if (Inventory[inv_biok_slot][inv_owned] >= 1)
            display.print(Ath);
          display.drawRect(0, 24, 128, 5, 1);
          display.drawLine(2, 26, map(Ath, 0, max_power, 3, 127), 26, 1);
          //Second Slot <------------------------------------|
          display.drawRect(0, 40, 128, 5, 1);
          display.setCursor(0, 32);
          display.print(F("Dis: "));
          display.setCursor(88, 32);
          if (Inventory[inv_biok_slot][inv_owned] >= 1)
            display.print(Dis);
          display.drawLine(2, 42, map(Dis, 0, max_power, 3, 127), 42, 1);
          //Third Slot <------------------------------------|
          display.setCursor(0, 48);
          display.print(F("Int: "));
          display.setCursor(88, 48);
          if (Inventory[inv_biok_slot][inv_owned] >= 1)
            display.print(Int);
          display.drawRect(0, 56, 128, 5, 1);
          display.drawLine(2, 58, map(Int, 0, max_power, 3, 127), 58, 1);
          break;
        default:
          break;
      }
      break;

    /*========================================================================================================================*/
    case m_food:
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

    case m_conf:
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
    case m_play:
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

    case m_clockset: //Clock set menu
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

    case m_invent:
      display.clearDisplay();
      display.setTextColor(1);
      display.setTextSize(1);
      display.drawChar(((ocCursor % 4) * 32), ((ocCursor / 4) * 16) + 5, 16 , 1, 0, 1);
      for (int i = 0; i < inv_max_itemtypes; i++) {
        display.drawBitmap(((i % 4) * 32) + 4, (i / 4) * 16, getIcon(i), icon_dimensions, icon_dimensions, 1);
        display.setCursor(((i % 4) * 32) + 20, ((i / 4) * 16) + 5);
        if (Inventory[i][inv_owned] < 10)
          display.print(F("0"));
        display.print(Inventory[i][inv_owned]);
      }
      break;

    /*========================================================================================================================*/

    case m_detail:
      display.clearDisplay();
      display.setTextColor(1);
      display.setTextSize(2);
      display.drawBitmap(4, 0 , getIcon(ocCursor), icon_dimensions, icon_dimensions, 1);
      switch (ocCursor) {
        case inv_meds_slot:
          display.setCursor(30, 0);
          display.print(F("Meds"));
          display.setTextSize(1);
          display.setCursor(0, 24);
          display.print(F("Removes one level of"));
          display.setCursor(0, 32);
          display.print(F("sickness from your"));
          display.setCursor(0, 40);
          display.print(F("critter."));
          break;
        case inv_soda_slot:
          display.setCursor(30, 0);
          display.print(F("Soda"));
          display.setTextSize(1);
          display.setCursor(0, 24);
          display.print(F("Boosts metabolism"));
          display.setCursor(0, 32);
          display.print(F("for "));
          display.print(sodaBonusBeats);
          display.print(F(" heartbeats."));
          break;
        case inv_star_slot:
          display.setCursor(30, 0);
          display.print(F("Star"));
          display.setTextSize(1);
          display.setCursor(0, 24);
          display.print(F("Boosts all health"));
          display.setCursor(0, 32);
          display.print(F("stats of critter!"));
          break;
        case inv_biok_slot:
          display.setCursor(30, 0);
          display.print(F("Lab Kit"));
          display.setTextSize(1);
          display.setCursor(0, 24);
          display.print(F("Shows the numerical"));
          display.setCursor(0, 32);
          display.print(F("value of each stat."));
          break;
        case inv_pedia_slot:
          display.setCursor(30, 0);
          display.print(F("Pedia"));
          display.setTextSize(1);

          display.setCursor(0, 24);
          display.print(F("An Encyclopedia on"));
          display.setCursor(0, 32);
          display.print(F("all of the breeds of"));
          display.setCursor(0, 40);
          display.print(F("critters in the game."));
          break;
        default:
          display.setCursor(30, 0);
          display.print(F("Nothing?"));
          display.setTextSize(1);
          display.setCursor(0, 24);
          display.print(F("Data not found!"));
          break;
      }
      display.setCursor(12, 55);
      display.print(F("x"));
      if (Inventory[ocCursor][inv_owned] < 10)
        display.print(F("0"));
      display.print(Inventory[ocCursor][inv_owned]);
      display.drawRect(43, 53, 42, 11, 1);
      display.setCursor(55, 55);
      display.print(F("USE"));
      display.drawRect(86, 53, 42, 11, 1);
      display.setCursor(90, 55);
      display.print(F("Cancel"));
      break;

    /*========================================================================================================================*/

    case m_pedia:
      display.clearDisplay();
      display.setTextColor(1);
      display.setTextSize(2);
      display.drawBitmap(0, 0 , getFrame(frame_main, ocCursor), crit_dimensions, crit_dimensions, 1);

      //      //First I tried this really fancy code
      //      if (strings_pedia[ocCursor * pedia_pages] == "") {
      //        display.print(F("Unknown"));
      //      }
      //      for (int i = 1; i < pedia_pages; i++) {
      //        display.setCursor(i / 3, 48 - (i * 8));
      //        display.print(strings_pedia[ocCursor * (pedia_pages - i)]);
      //      }

      //      //Then I tried this simple code
      //      String output;
      //      display.setCursor(32, 0);
      //      output = strings_pedia[ocCursor + 1];
      //      display.print(output);
      //      display.setTextSize(1);
      //      display.setCursor(32, 24);
      //      output = strings_pedia[ocCursor + 1];
      //      display.print(output);
      //      display.setCursor(0, 32);
      //      output = strings_pedia[ocCursor + 2];
      //      display.print(output);
      //      display.setCursor(0, 40);
      //      output = strings_pedia[ocCursor + 3];
      //      display.print(output);

      //This is what ended up working :(
      switch (ocCursor) {
        case egg:
          display.setCursor(34, 0);
          display.print(F("Egg"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("The very"));
          display.setCursor(0, 34);
          display.print(F("beginning. Best"));
          display.setCursor(0, 43);
          display.print(F("stats in the game."));
          break;
        case goob:
          display.setCursor(34, 0);
          display.print(F("Goob"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("Very curious,"));
          display.setCursor(0, 34);
          display.print(F("but everything makes"));
          display.setCursor(0, 43);
          display.print(F("it nervous."));
          break;
        case wibbur:
          display.setCursor(34, 0);
          display.print(F("Wibbur"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("Its two wiggly"));
          display.setCursor(0, 34);
          display.print(F("feet are just going"));
          display.setCursor(0, 43);
          display.print(F("with the flow."));
          break;
        case xorby:
          display.setCursor(34, 0);
          display.print(F("Xorby"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("It's always"));
          display.setCursor(0, 34);
          display.print(F("trying to use its"));
          display.setCursor(0, 43);
          display.print(F("limbs to play!"));
          break;
        case snek:
          display.setCursor(34, 0);
          display.print(F("Snek"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("It might not"));
          display.setCursor(0, 34);
          display.print(F("have any limbs, but"));
          display.setCursor(0, 43);
          display.print(F("it's very clever."));
          break;
        case shansy:
          display.setCursor(34, 0);
          display.print(F("Shansy"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("It sings a song"));
          display.setCursor(0, 34);
          display.print(F("while it twirls its"));
          display.setCursor(0, 43);
          display.print(F("tentacles around."));
          break;
        case moops:
          display.setCursor(34, 0);
          display.print(F("Moops"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("Shuffles around"));
          display.setCursor(0, 34);
          display.print(F("on its suction-cup"));
          display.setCursor(0, 43);
          display.print(F("feet and moos."));
          break;
        case hwooty:
          display.setCursor(34, 0);
          display.print(F("Hwooty"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("Staring into"));
          display.setCursor(0, 34);
          display.print(F("space seems to be its"));
          display.setCursor(0, 43);
          display.print(F("favorite pastime."));
          break;
        case flip:
          display.setCursor(34, 0);
          display.print(F("Flip"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("Can't fly, but"));
          display.setCursor(0, 34);
          display.print(F("runs very fast every-"));
          display.setCursor(0, 43);
          display.print(F("where it goes."));
          break;
        case lugerd:
          display.setCursor(34, 0);
          display.print(F("Lugerd"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("Gets grouchy"));
          display.setCursor(0, 34);
          display.print(F("when it's not allowed"));
          display.setCursor(0, 43);
          display.print(F("to hit things."));
          break;
        case culu:
          display.setCursor(34, 0);
          display.print(F("Culu"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("You can feel it"));
          display.setCursor(0, 34);
          display.print(F("in your mind..."));
          break;
        case shent:
          display.setCursor(34, 0);
          display.print(F("Shent"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("It's very smart"));
          display.setCursor(0, 34);
          display.print(F("but it also gets"));
          display.setCursor(0, 43);
          display.print(F("bored very easily."));
          break;
        case slorp:
          display.setCursor(34, 0);
          display.print(F("Slorp"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("It hides in its"));
          display.setCursor(0, 34);
          display.print(F("spiral shell when it"));
          display.setCursor(0, 43);
          display.print(F("feels threatened."));
          break;
        case zeta:
          display.setCursor(34, 0);
          display.print(F("Zeta"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("It's a slippery,"));
          display.setCursor(0, 34);
          display.print(F("zippidy-zappy, shocky"));
          display.setCursor(0, 43);
          display.print(F("water snake."));
          break;
        case butters:
          display.setCursor(34, 0);
          display.print(F("Butters"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("A highly mobile"));
          display.setCursor(0, 34);
          display.print(F("source of specific"));
          display.setCursor(0, 43);
          display.print(F("dairy products."));
          break;
        case tribbur:
          display.setCursor(34, 0);
          display.print(F("Tribbur"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("Nobody knows"));
          display.setCursor(0, 34);
          display.print(F("how it eats food with"));
          display.setCursor(0, 43);
          display.print(F("out a mouth."));
          break;
        case corine:
          display.setCursor(34, 0);
          display.print(F("Corine"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("It always looks"));
          display.setCursor(0, 34);
          display.print(F("like it's ready to be"));
          display.setCursor(0, 43);
          display.print(F("photgraphed."));
          break;
        case pyre:
          display.setCursor(34, 0);
          display.print(F("Pyre"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("A fiery atti-"));
          display.setCursor(0, 34);
          display.print(F("tude to match it's "));
          display.setCursor(0, 43);
          display.print(F("fiery body."));
          break;
        case rajur:
          display.setCursor(34, 0);
          display.print(F("Rajur"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("It will destroy"));
          display.setCursor(0, 34);
          display.print(F("anything that gets in"));
          display.setCursor(0, 43);
          display.print(F("its way."));
          break;
        case crosh:
          display.setCursor(34, 0);
          display.print(F("Crosh"));
          display.setTextSize(1);
          display.setCursor(34, 25);
          display.print(F("It only moves"));
          display.setCursor(0, 34);
          //-----------(F("0123456789ABCDEF01234"));
          display.print(F("to hit things with"));
          display.setCursor(0, 43);
          display.print(F("its hammer."));
          break;
        default:
          display.setCursor(34, 0);
          display.print(F("Unknown"));
          display.setTextSize(1);
          display.setCursor(0, 34);
          display.print(F("Data not found!"));
          break;
      }

      //Find its lifestage and draw it on the screen under the critter's name
      display.setCursor(34, 16);
      if (ocCursor == 0)
        display.print(F("Egg"));
      else if (ocCursor <= 3)
        display.print(F("Baby"));
      else if (ocCursor <= 9)
        display.print(F("Teen"));
      else if (ocCursor <= 19)
        display.print(F("Adult"));
      else if (ocCursor <= 25)
        display.print(F("Senior"));
      else if (ocCursor <= 28)
        display.print(F("Ancient"));
      else
        display.print(F("Ultimate"));

      display.setCursor(116, 0);
      if (ocCursor < 10)
        display.print(F("0"));
      display.print(ocCursor);
      display.drawRect(0, 53, 42, 11, 1);
      display.setCursor(18, 55);
      display.print(F("<"));
      display.drawRect(43, 53, 42, 11, 1);
      display.setCursor(62, 55);
      display.print(F(">"));
      display.drawRect(86, 53, 42, 11, 1);
      display.setCursor(90, 55);
      display.print(F("Cancel"));
      break;

  }
  display.display();
}
