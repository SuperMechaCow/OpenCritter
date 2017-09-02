
/*
   Handles all menus in the game

   Note that this does not actually draw the screen. It only handles the "behind the scenes".
   See updateScreen() and animate() for drawing menus.
*/

void updateBPM() {
  hrtBPM = (baseHRT_speed * metabolism); //length of a heartbeat is base game speed times the metabolism
  hrtBPM = hrtBPM / 1000; //convert to seconds
  hrtBPM = 1 / hrtBPM; //converting length of the heart beat to a frequency
  hrtBPM = hrtBPM / 60; //beats per minute
}

void updateClock() {
  hnow = ((((clockOFFSET + millis()) / 1000) / 60) / 60);
  mnow = (((clockOFFSET + millis()) / 1000) / 60) % 60;
  snow = ((clockOFFSET + millis()) / 1000) % 60;
}

void mainMenu()
{
  //Show the critter doing stuff
  animate();

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
        ocCursor = RESET;
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
      ocCursor = 7;
    else
      ocCursor--;
    updateScreen();
    //    beep(beep_HiLo1);
    //    butNOW[2] = false; //Set the button to not enable again
    //    //do stuff when button is HIGH
    //    ocCursor = RESET;
    //    updateScreen();
  }
}

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
    ocCursor = RESET;
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
      case 0: //Food 1

        if (hun <= max_stats - foodbonus)
          hun += foodbonus;
        else
          hun = max_stats;
        if (random(0, 101) >= Ath)
          weight += 2;
        Dis -= 1;

        aniMode = ani_wibbur_eat;
        aniStage = RESET;
        aniLast = RESET;
        selMenu = mainM;
        display.clearDisplay();
        ocCursor = 2;
        break;
      case 1: //Food 2

        if (hap <= max_stats - foodbonus)
          hap += foodbonus;
        else
          hap = max_stats;
        if (random(0, 101) >= Ath)
          weight += 2;
        Int -= 1;

        aniMode = ani_wibbur_eat;
        aniStage = RESET;
        aniLast = RESET;
        selMenu = mainM;
        display.clearDisplay();
        ocCursor = 2;
        break;
      case 2: //Food 3
        if (bor <= max_stats - foodbonus)
          bor += foodbonus;
        else
          bor = max_stats;
        if (random(0, 101) >= Ath)
          weight += 2;
        Ath -= 1;

        aniMode = ani_wibbur_eat;
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
    if (ocCursor >= 2)
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
        selMenu = g_cardflip;
        ocCursor = RESET;
        break;
      case 1: // Bit Shift
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
    if (ocCursor >= 4)
      ocCursor = RESET;
    updateScreen();
  }
  if (butNOW[1]) //B button is pressed
  {

    beep(beep_PosBeep);
    butNOW[1] = false; //Set the button to not enable again

    switch (ocCursor)
    {
      case 0: //Mute Beep
        beepMute = !beepMute;
        beep(beep_HiLo1);
        break;
      case 1: //Mute Beep
        buzzMute = !buzzMute;
        beep(beep_HiLo1);
        break;
      case 2: //Mute Beep
        beep(beep_PosBeep);
        selMenu = c_clockset;
        ocCursor = RESET;
        break;
      case 3: //12 hour mode
        hour12 = !hour12;
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
