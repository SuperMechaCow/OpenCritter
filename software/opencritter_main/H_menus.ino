/*
   Handles all menus in the game

   Note that this does not actually draw the screen. It only handles the "behind the scenes".
*/

/*== Update BPM ==========================================================================================================*/
void updateBPM() {
  hrtBPM = (baseHRT_speed * metabolism); //length of a heartbeat is base game speed times the metabolism
  hrtBPM = hrtBPM / 100; //convert to seconds
  hrtBPM = 1 / hrtBPM; //converting length of the heart beat to a frequency
  hrtBPM = hrtBPM * 60; //beats per minute
}

/*== Update Clock ========================================================================================================*/
void updateclockMenu() {
  hnow = ((((clockOFFSET + millis()) / 1000) / 60) / 60);
  mnow = (((clockOFFSET + millis()) / 1000) / 60) % 60;
  snow = ((clockOFFSET + millis()) / 1000) % 60;
}

/*== Main Menu ===========================================================================================================*/
void mainMenu()
{

  //Show the critter doing stuff
  display.fillRect(24, 16, 80, 32, 0); //Erase where the critter was standing
  animate(playPen_now, 16, breed);

  //Figure out how to handle the buttons that  getButtons() found
  if (Inventory[inv_meds_slot][inv_owned] > Inventory[inv_meds_slot][inv_acked]) {
    if (butNOW[0] || butNOW[1] || butNOW[2]) {
      butNOW[0] = false;
      butNOW[1] = false;
      butNOW[2] = false;
      beep(beep_PosBeep);
      Inventory[inv_meds_slot][inv_acked] = Inventory[inv_meds_slot][inv_owned];
      display.clearDisplay();
      updateScreen();
    }
  }
  else if (Inventory[inv_soda_slot][inv_owned] > Inventory[inv_soda_slot][inv_acked]) {
    if (butNOW[0] || butNOW[1] || butNOW[2]) {
      butNOW[0] = false;
      butNOW[1] = false;
      butNOW[2] = false;
      beep(beep_PosBeep);
      Inventory[inv_soda_slot][inv_acked] = Inventory[inv_soda_slot][inv_owned];
      display.clearDisplay();
      updateScreen();
    }
  }
  else if (Inventory[inv_star_slot][inv_owned] > Inventory[inv_star_slot][inv_acked]) {
    if (butNOW[0] || butNOW[1] || butNOW[2]) {
      butNOW[0] = false;
      butNOW[1] = false;
      butNOW[2] = false;
      beep(beep_PosBeep);
      Inventory[inv_star_slot][inv_acked] = Inventory[inv_star_slot][inv_owned];
      display.clearDisplay();
      updateScreen();
    }
  }
  else {
    /////
    //A//
    /////
    if (butNOW[0]) //A button is pressed
    {

      beep(beep_NegBeep);
      //do stuff when button is HIGH
      butNOW[0] = false; //Set the button to not enable again
      ocCursor++;
      if (ocCursor >= 8)
        ocCursor = RESET;
      updateScreen();
    }
    /////
    //B//
    /////
    if (butNOW[1]) //B button is pressed
    {
      //do stuff when button is HIGH
      butNOW[1] = false; //Set the button to not enable again
      beep(beep_PosBeep);
      switch (ocCursor)
      {
        case 0:
          selMenu = m_clock;
          ocCursor = RESET;
          break;
        case 1:
          selMenu = m_stats;
          ocCursor = RESET;
          break;
        case 2:
          if (breed > 0) {
            selMenu = m_food;
            ocCursor = RESET;
          }
          else {
            beep(beep_HiLo1);
          }
          break;
        case 3:
          if (breed > 0) {
            selMenu = m_play;
            ocCursor = RESET;
          }
          else {
            beep(beep_HiLo1);
          }
          break;
        case 4:
          selMenu = m_invent;
          ocCursor = RESET;
          break;
        case 5:
          selMenu = m_conf;
          ocCursor = RESET;
          break;
        case 6:
          if (breed > 0) {
            if (poopCount > 0) { //If there's poop to clean
              poopCount--; //Clean one poop
              beep(beep_HiLo3);
            }
          }
          else {
            beep(beep_HiLo1);
          }
          break;
        case 7:
          ocCursor = RESET;
          clearAlert();
          break;
        default:
          break;
      }
      updateScreen();
    }
    /////
    //C//
    /////
    if (butNOW[2]) //C button is pressed
    {
      beep(beep_NegBeep);
      //do stuff when button is HIGH
      butNOW[2] = false; //Set the button to not enable again
      if (ocCursor == 0)
        ocCursor = 8;
      ocCursor--;
      updateScreen();
    }
    /////
    //D//
    /////
    if (butNOW[3] && debugMode == true) //C button is pressed
    {
      beep(beep_noise);
      butNOW[3] = false; //Set the button to not enable again
      //do stuff when button is HIGH
      if (breed >= max_breeds - 1)
        breed = RESET;
      else
        breed++;
    }
  }
}

/*== Clock Menu ==========================================================================================================*/
void clockMenu()
{
  //Update the screen each standard refresh interval
  if (CLK[baseCLK] - CLK[timeCLK] > ref_int)
  {
    CLK[timeCLK] = CLK[baseCLK];
    updateclockMenu();
    updateScreen();
  }

  //Figure out how to handle the buttons that  getButtons() found
  if (butNOW[0]) //A button is pressed
  {

    beep(beep_NegBeep);
    butNOW[0] = false; //Set the button to not enable again
  }
  if (butNOW[1]) //B button is pressed
  {

    beep(beep_PosBeep);
    butNOW[1] = false; //Set the button to not enable again
  }
  if (butNOW[2]) //C button is pressed
  {

    beep(beep_HiLo1);
    //do stuff when button is HIGH
    butNOW[2] = false; //Set the button to not enable again
    selMenu = m_main;
    display.clearDisplay();
  }
}

/*== Stats Menu ==========================================================================================================*/
void statsMenu()
{
  //Update the screen each standard refresh interval
  if (CLK[baseCLK] - CLK[timeCLK] > ref_int)
  {
    CLK[timeCLK] = CLK[baseCLK];
    updateScreen();
  }


  //Figure out how to handle the buttons that  getButtons() found
  if (butNOW[0])
  {
    beep(beep_NegBeep);
    butNOW[0] = false; //Set the button to not enable again
    ocCursor++;
    if (ocCursor >= 4)
      ocCursor = RESET;
    updateScreen();
  }
  if (butNOW[1])
  {
    beep(beep_PosBeep);
    butNOW[1] = false; //Set the button to not enable again
    if (ocCursor <= 0)
      ocCursor = 4;
    ocCursor--;
    updateScreen();
  }
  if (butNOW[2])
  {

    beep(beep_HiLo1);
    //do stuff when button is HIGH
    butNOW[2] = false; //Set the button to not enable again
    selMenu = m_main;
    display.clearDisplay();
  }
}

/*== Food Menu ===========================================================================================================*/
void foodMenu()
{
  //Update the screen each standard refresh interval
  if (CLK[baseCLK] - CLK[timeCLK] > ref_int)
  {
    CLK[timeCLK] = CLK[baseCLK];
    updateScreen();
  }


  //Figure out how to handle the buttons that  getButtons() found
  if (butNOW[0])
  {

    beep(beep_NegBeep);
    //do stuff when button is HIGH
    butNOW[0] = false; //Set the button to not enable again
    ocCursor++;
    if (ocCursor >= 3)
      ocCursor = RESET;
    updateScreen();
  }
  if (butNOW[1])
  {

    beep(beep_PosBeep);
    //do stuff when button is HIGH
    butNOW[1] = false; //Set the button to not enable again
    switch (ocCursor)
    {
      case 0: //Protein!

        eatProtein();

        selMenu = m_main;
        display.clearDisplay();
        ocCursor = 2;
        break;
      case 1: //Fat!

        eatFat();

        selMenu = m_main;
        display.clearDisplay();
        ocCursor = 2;
        break;
      case 2: //Carbs!

        eatCarbs();

        selMenu = m_main;
        display.clearDisplay();
        ocCursor = 2;
        break;
      default:
        break;
    }
  }
  if (butNOW[2])
  {

    beep(beep_HiLo1);
    //do stuff when button is HIGH
    butNOW[2] = false; //Set the button to not enable again
    selMenu = m_main;
    display.clearDisplay();
    ocCursor = RESET;
  }
}

/*== Games Menu ==========================================================================================================*/
void playMenu()
{
  //Update the screen each standard refresh interval
  if (CLK[baseCLK] - CLK[timeCLK] > ref_int)
  {
    CLK[timeCLK] = CLK[baseCLK];
    updateScreen();
  }


  //Figure out how to handle the buttons that  getButtons() found
  if (butNOW[0])
  {

    beep(beep_NegBeep);
    //do stuff when button is HIGH
    butNOW[0] = false; //Set the button to not enable again
    ocCursor++;
    if (ocCursor >= 4)
      ocCursor = RESET;
    updateScreen();
  }
  if (butNOW[1])
  {

    beep(beep_PosBeep);
    //do stuff when button is HIGH
    butNOW[1] = false; //Set the button to not enable again
    switch (ocCursor)
    {
      case 0: // Card Flip
        selMenu = g_ballcatch;
        ocCursor = RESET;
        break;
      case 1: // Card Flip
        selMenu = g_cardflip;
        ocCursor = RESET;
        break;
      case 2: // Bit Shift
        selMenu = g_bitshifter;
        ocCursor = RESET;
        break;
      case 3: // Lazer jet
        selMenu = g_lazerjet;
        ocCursor = RESET;
        break;
      default:
        break;
    }
  }
  if (butNOW[2])
  {

    beep(beep_HiLo1);
    //do stuff when button is HIGH
    butNOW[2] = false; //Set the button to not enable again
    selMenu = m_main;
    display.clearDisplay();
    ocCursor = RESET;
  }
}

/*== Config Menu =========================================================================================================*/
void confMenu()
{
  //Update the screen each standard refresh interval
  if (CLK[baseCLK] - CLK[timeCLK] > ref_int)
  {
    CLK[timeCLK] = CLK[baseCLK];
    updateScreen();
  }

  //Figure out how to handle the buttons that  getButtons() found
  if (butNOW[0]) //A button is pressed
  {

    beep(beep_NegBeep);
    //do stuff when button is HIGH
    butNOW[0] = false; //Set the button to not enable again
    ocCursor++;
    if (ocCursor >= 5)
      ocCursor = RESET;
    updateScreen();
  }
  if (butNOW[1]) //B button is pressed
  {

    beep(beep_PosBeep);
    butNOW[1] = false; //Set the button to not enable again
    switch (ocCursor)
    {
      case 0: //Set Clock
        beep(beep_PosBeep);
        selMenu = m_clockset;
        ocCursor = RESET;
        break;
      case 1: //12 hour mode
        hour12 = !hour12;
        beep(beep_HiLo1);
      case 2: //Mute Beep
        beepMute = !beepMute;
        beep(beep_HiLo1);
        break;
      case 3: //Mute Beep
        rumbleMute = !rumbleMute;
        beep(beep_HiLo1);
        break;
      case 4: //WiFi Enabled
        if (wifiEnabled) { //If already enabled
          wifiEnabled = false; //disable it
          WiFiMode(WIFI_STA); //Station mode
          WiFi.disconnect();
          WiFi.mode(WIFI_OFF);
          WiFi.forceSleepBegin();
          delay(100); //If this delay doesn't happen, other Arduino nonsense will prevent the disable from happening
        }
        else {
          wifiEnabled = true; //enable it
          WiFiMode(WIFI_AP);
          WiFi.softAP(ssid, password);        //Start a WiFi AP with this Name and Password
          IPAddress myIP = WiFi.softAPIP();
          server.on("/", handleRoot);         //Root
          server.begin();
          WiFi.forceSleepWake();
          delay(100); //If this delay doesn't happen, other Arduino nonsense will prevent the enable from happening
        }
        beep(beep_HiLo1);
        break;
      default:
        break;
    }
  }
  if (butNOW[2]) //C button is pressed
  {

    beep(beep_HiLo1);
    //do stuff when button is HIGH
    butNOW[2] = false; //Set the button to not enable again
    selMenu = m_main;
    display.clearDisplay();
  }
}

/*== Clock Set ===========================================================================================================*/
void clockSet()
{
  //Update the screen each standard refresh interval
  if (CLK[baseCLK] - CLK[timeCLK] > ref_int)
  {
    CLK[timeCLK] = CLK[baseCLK];
    updateclockMenu();
    updateScreen();
  }


  //Figure out how to handle the buttons that  getButtons() found
  if (butNOW[0])
  {

    beep(beep_NegBeep);
    butNOW[0] = false; //Set the button to not enable again
    ocCursor++;
    if (ocCursor >= 3)
      ocCursor = RESET;
    updateclockMenu();
    updateScreen();
  }
  if (butNOW[1])
  {

    beep(beep_PosBeep);
    butNOW[1] = false; //Set the button to not enable again
    if (ocCursor == 0)
    {
      clockOFFSET = clockOFFSET + 3600000;  //One hour is 1000 milliseconds times 60 seconds times 60 minutes
      if (clockOFFSET >= 86400000)          //If offset greater than 24 hours
        clockOFFSET -= 86400000;           //Then remove 24 hours
    }
    if (ocCursor == 1)
    {
      clockOFFSET = clockOFFSET + 60000; //One minute is 1000 milliseconds times 60 seconds
      if (clockOFFSET >= 86400000)
        clockOFFSET -= 86400000;
    }
    if (ocCursor == 2)
    {
      clockOFFSET = clockOFFSET + 1000; //One second is 1000 milliseconds
      if (clockOFFSET >= 86400000)
        clockOFFSET -= 86400000;
    }
    updateclockMenu();
    updateScreen();
  }
  if (butNOW[2])
  {

    beep(beep_HiLo1);
    //do stuff when button is HIGH
    butNOW[2] = false; //Set the button to not enable again
    selMenu = m_conf;
    ocCursor = RESET;
    display.clearDisplay();
  }
}

/*== Inventory ===========================================================================================================*/

void inventMenu()
{
  /////
  //A//
  /////
  if (butNOW[0])
  {
    beep(beep_NegBeep);
    butNOW[0] = false; //Set the button to not enable again
    ocCursor++;
    if (ocCursor >= inv_max_itemtypes)
      ocCursor = RESET;
    updateScreen();
  }

  /////
  //B//
  /////
  if (butNOW[1])
  {
    beep(beep_NegBeep);
    butNOW[1] = false;
    selMenu = m_detail;
    display.clearDisplay();
    updateScreen();
  }

  /////
  //C//
  /////
  if (butNOW[2])
  {
    beep(beep_HiLo1);
    //do stuff when button is HIGH
    butNOW[2] = false; //Set the button to not enable again
    selMenu = m_main;
    display.clearDisplay();
  }

  /////
  //D//
  /////
  if (butNOW[3] && debugMode == true)
  {
    beep(beep_HiLo1);
    butNOW[3] = false; //Set the button to not enable again
    Inventory[ocCursor][inv_owned]++;
    Inventory[ocCursor][inv_acked]++;
    updateScreen();
  }

}

/*========================================================================================================================*/

void detailMenu() {
  /////
  //A//
  /////
  if (butNOW[0])
  {
    beep(beep_NegBeep);
    butNOW[0] = false; //Set the button to not enable again
  }

  /////
  //B//
  /////
  if (butNOW[1])
  {
    beep(beep_NegBeep);
    butNOW[1] = false; //Set the button to not enable again
    switch (ocCursor) {
      case inv_meds_slot:
        //Use medicine
        if (breed > 0 && sickCount > 0 && Inventory[inv_meds_slot][inv_owned] > 0) {
          Inventory[inv_meds_slot][inv_owned]--;
          Inventory[inv_meds_slot][inv_acked]--;
          sickCount--; //Cure one sickness
          beep(beep_UpChirp);
          updateScreen();
        }
        else {
          beep(beep_HiLo1);
        }
        //End use medicine
        break;
      case inv_soda_slot:
        if (Inventory[inv_soda_slot][inv_owned] > 0) {
          Inventory[inv_soda_slot][inv_owned]--;
          Inventory[inv_soda_slot][inv_acked]--;
          boostActive = true;
          boostBeat = heartbeats + sodaBonusBeats;
          beep(beep_UpChirp);
          updateScreen();
        }
        else {
          beep(beep_HiLo1);
        }
        break;
      case inv_star_slot:
        if (Inventory[inv_star_slot][inv_owned] > 0) {
          Inventory[inv_star_slot][inv_owned]--;
          Inventory[inv_star_slot][inv_acked]--;
          if (hun + (foodbonus * 2) > max_health)
            hun = max_health;
          else
            hun = hun + (foodbonus * 2);
          if (hap + (foodbonus * 2) > max_health)
            hap = max_health;
          else
            hap = hap + (foodbonus * 2);
          if (bor + (foodbonus * 2) > max_health)
            bor = max_health;
          else
            bor = bor + (foodbonus * 2);
          beep(beep_UpChirp);
          updateScreen();
        }
        else {
          beep(beep_HiLo1);
        }
        break;
      case inv_biok_slot:
        if (Inventory[inv_biok_slot][inv_owned] > 0) {
          selMenu = m_stats;
          beep(beep_UpChirp);
          updateScreen();
        }
        else {
          beep(beep_HiLo1);
        }
        break;
      case inv_pedia_slot:
        if (Inventory[inv_pedia_slot][inv_owned] > 0) {
          selMenu = m_pedia;
          ocCursor = RESET;
          beep(beep_UpChirp);
          updateScreen();
        }
        else {
          beep(beep_HiLo1);
        }
        break;
      default:
        break;
    }
  }

  /////
  //C//
  /////
  if (butNOW[2])
  {
    beep(beep_HiLo1);
    butNOW[2] = false; //Set the button to not enable again
    selMenu = m_invent;
    display.clearDisplay();
    updateScreen();
  }

}

/*========================================================================================================================*/

void pediaMenu() {

  /////
  //A//
  /////
  if (butNOW[0])
  {
    beep(beep_NegBeep);
    butNOW[0] = false; //Set the button to not enable again
    if (ocCursor <= 0)
      ocCursor = max_breeds - 1;
    else
      ocCursor--;
    updateScreen();
  }

  /////
  //B//
  /////
  if (butNOW[1])
  {
    beep(beep_NegBeep);
    butNOW[1] = false;

    if (ocCursor >= max_breeds - 1)
      ocCursor = RESET;
    else
      ocCursor++;
    updateScreen();
  }

  /////
  //C//
  /////
  if (butNOW[2])
  {
    beep(beep_HiLo1);
    //do stuff when button is HIGH
    butNOW[2] = false; //Set the button to not enable again
    selMenu = m_main;
    display.clearDisplay();
  }

  /////
  //D//
  /////
  if (butNOW[3] && debugMode == true)
  {
    beep(beep_HiLo1);
    butNOW[3] = false; //Set the button to not enable again
    breed = ocCursor;
    updateScreen();
  }

}

