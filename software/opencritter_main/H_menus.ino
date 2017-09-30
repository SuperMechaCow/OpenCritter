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
void updateClock() {
  hnow = ((((clockOFFSET + millis()) / 1000) / 60) / 60);
  mnow = (((clockOFFSET + millis()) / 1000) / 60) % 60;
  snow = ((clockOFFSET + millis()) / 1000) % 60;
}

/*== Main Menu ===========================================================================================================*/
void mainMenu()
{
  //Show the critter doing stuff
  animate(48, 16);

  //Figure out how to handle the buttons that  getButtons() found
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
  if (butNOW[1]) //B button is pressed
  {
    //do stuff when button is HIGH
    butNOW[1] = false; //Set the button to not enable again
    beep(beep_PosBeep);
    switch (ocCursor)
    {
      case 0:
        selMenu = clockM;
        ocCursor = RESET;
        break;
      case 1:
        selMenu = statsM;
        ocCursor = 2;
        break;
      case 2:
        if (breed > 0) {
          selMenu = foodM;
          ocCursor = RESET;
        }
        else {
          beep(beep_HiLo1);
        }
        break;
      case 3:
        if (breed > 0) {
          selMenu = playM;
          ocCursor = RESET;
        }
        else {
          beep(beep_HiLo1);
        }
        break;
      case 4:
        if (breed > 0) {
          if (sickCount > 0) { //If there's sickness to remove
            sickCount--; //Cure one sickness
            beep(beep_HiLo3);
          }
        }
        else {
          beep(beep_HiLo1);
        }
        break;
      case 5:
        selMenu = confM;
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
        clearAlert();
        ocCursor = RESET;
        break;
      default:
        break;
    }
    updateScreen();
  }
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
}

/*== Clock Menu ==========================================================================================================*/
void clockMenu()
{
  //Update the screen each standard refresh interval
  if (CLK[baseCLK] - CLK[timeCLK] > ref_int)
  {
    CLK[timeCLK] = CLK[baseCLK];
    updateClock();
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
    selMenu = mainM;
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
    if (ocCursor >= 3)
      ocCursor = RESET;
    updateScreen();
  }
  if (butNOW[1])
  {

    beep(beep_PosBeep);
    butNOW[1] = false; //Set the button to not enable again
    if (ocCursor <= 0)
      ocCursor = 3;
    ocCursor--;
    updateScreen();
  }
  if (butNOW[2])
  {

    beep(beep_HiLo1);
    //do stuff when button is HIGH
    butNOW[2] = false; //Set the button to not enable again
    selMenu = mainM;
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

        if (hun <= max_stats - foodbonus)
          hun += foodbonus;
        else
          hun = max_stats;
        if (random(0, 101) >= Ath)
          weight += 1;

        aniModeSet(breed, a_eat);
        aniStage = RESET;
        aniLast = RESET;
        selMenu = mainM;
        display.clearDisplay();
        ocCursor = 2;
        break;
      case 1: //Fat!

        if (hap <= max_stats - (foodbonus * 2))
          hap += foodbonus * 2;
        else
          hap = max_stats;
        if (random(0, 101) >= Ath)
          weight += 1;
        weight += 1;
        if (Dis > 0)
          Dis -= 1;

        aniModeSet(breed, a_eat);
        aniStage = RESET;
        aniLast = RESET;
        selMenu = mainM;
        display.clearDisplay();
        ocCursor = 2;
        break;
      case 2: //Food 3
        if (bor <= max_stats - (foodbonus * 2))
          bor += foodbonus  * 2;
        else
          bor = max_stats;
        if (random(0, 101) >= Ath)
          weight += 1;
        weight += 1;
        if (Int > 0)
          Int -= 1;

        aniModeSet(breed, a_eat);
        aniStage = RESET;
        aniLast = RESET;
        selMenu = mainM;
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
    selMenu = mainM;
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
      default:
        break;
    }
  }
  if (butNOW[2])
  {

    beep(beep_HiLo1);
    //do stuff when button is HIGH
    butNOW[2] = false; //Set the button to not enable again
    selMenu = mainM;
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
        selMenu = c_clockset;
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
    selMenu = mainM;
    display.clearDisplay();
  }
}

/*== Clock Set ===========================================================================================================*/
void clockset()
{
  //Update the screen each standard refresh interval
  if (CLK[baseCLK] - CLK[timeCLK] > ref_int)
  {
    CLK[timeCLK] = CLK[baseCLK];
    updateClock();
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
    updateClock();
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
    updateClock();
    updateScreen();
  }
  if (butNOW[2])
  {

    beep(beep_HiLo1);
    //do stuff when button is HIGH
    butNOW[2] = false; //Set the button to not enable again
    selMenu = confM;
    ocCursor = RESET;
    display.clearDisplay();
  }
}
