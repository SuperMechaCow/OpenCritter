/*
   Handles all menus in the game

   Note that this does not actually draw the screen. It only handles the "behind the scenes".
   See updateScreen() and animate() for drawing menus.
*/

void mainMenu()
{
  //Show the critter doing stuff
  animate();

  //Find out which buttons the user is pressing
  getButton();

  //Figure out how to handle the buttons that getButton() found
  if (butNOW[0]) //A button is pressed
  {
    beepStage = RESET;
    beepMode = NegBeep;
    //do stuff when button is HIGH
    butNOW[0] = false; //Set the button to not enable again
    ocCursor++;
    if (ocCursor >= 8)
      ocCursor = RESET;
    updateScreen();
    if (debugMode)
    {
      Serial.print(F("Menu ocCursor: "));
      Serial.println(ocCursor);
    }
  }
  if (butNOW[1]) //B button is pressed
  {
    beepStage = RESET;
    beepMode = PosBeep;
    //do stuff when button is HIGH
    butNOW[1] = false; //Set the button to not enable again
    if (debugMode)
    {
      Serial.print(F("Menu ocCursor: "));
      Serial.println(ocCursor);
    }
    switch (ocCursor)
    {
    case 0:
      CLK[timeCLK] = CLK[baseCLK];
      selMenu = clockM;
      display.fillRect(0, 0, 128, 64, 0);
      ocCursor = RESET;
      break;
    case 1:
      CLK[timeCLK] = CLK[baseCLK];
      selMenu = statsM;
      display.fillRect(0, 0, 128, 64, 0);
      ocCursor = RESET;
      break;
    case 2:
      CLK[timeCLK] = CLK[baseCLK];
      selMenu = foodM;
      display.fillRect(0, 0, 128, 64, 0);
      ocCursor = RESET;
      break;
    case 3:
      CLK[timeCLK] = CLK[baseCLK];
      selMenu = playM;
      ocCursor = RESET;
      break;
    case 5:
      CLK[timeCLK] = CLK[baseCLK];
      selMenu = confM;
      ocCursor = RESET;
      break;
    default:
      break;
    }
    updateScreen();
  }
  if (butNOW[2]) //C button is pressed
  {
    beepStage = RESET;
    beepMode = HiLo1;
    butNOW[2] = false; //Set the button to not enable again
    //do stuff when button is HIGH
    ocCursor = RESET;
    updateScreen();
  }
}

void clockMenu()
{
  //Update the screen each standard refresh interval
  if (CLK[baseCLK] - CLK[timeCLK] > ref_int)
  {
    CLK[timeCLK] = CLK[baseCLK];
    hnow = ((((millis() / 1000) / 60) / 60) / 24);
    hnow = (((millis() / 1000) / 60) / 60) % 12;
    mnow = ((millis() / 1000) / 60) % 60;
    snow = (millis() / 1000) % 60;
    updateScreen();
  }

  //Find out which buttons the user is pressing
  getButton();

  //Figure out how to handle the buttons that getButton() found
  if (butNOW[0]) //A button is pressed
  {
    beepStage = RESET;
    beepMode = NegBeep;
    butNOW[0] = false; //Set the button to not enable again
  }
  if (butNOW[1]) //B button is pressed
  {
    beepStage = RESET;
    beepMode = PosBeep;
    butNOW[1] = false; //Set the button to not enable again
  }
  if (butNOW[2]) //C button is pressed
  {
    beepStage = RESET;
    beepMode = HiLo1;
    //do stuff when button is HIGH
    butNOW[2] = false; //Set the button to not enable again
    selMenu = mainM;
    display.fillRect(0, 0, 128, 64, 0);
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

  //Find out which buttons the user is pressing
  getButton();

  //Figure out how to handle the buttons that getButton() found
  if (butNOW[0])
  {
    beepStage = RESET;
    beepMode = NegBeep;
    butNOW[0] = false; //Set the button to not enable again
    ocCursor++;
    if (ocCursor >= 3)
      ocCursor = RESET;
    Serial.print(F("Menu ocCursor: "));
    Serial.println(ocCursor);
  }
  if (butNOW[1])
  {
    beepStage = RESET;
    beepMode = PosBeep;
    butNOW[1] = false; //Set the button to not enable again
    ocCursor = RESET;
  }
  if (butNOW[2])
  {
    beepStage = RESET;
    beepMode = HiLo1;
    //do stuff when button is HIGH
    butNOW[2] = false; //Set the button to not enable again
    selMenu = mainM;
    display.fillRect(0, 0, 128, 64, 0);
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

  //Find out which buttons the user is pressing
  getButton();

  //Figure out how to handle the buttons that getButton() found
  if (butNOW[0])
  {
    beepStage = RESET;
    beepMode = NegBeep;
    //do stuff when button is HIGH
    butNOW[0] = false; //Set the button to not enable again
    ocCursor++;
    if (ocCursor >= 3)
      ocCursor = RESET;
    updateScreen();
    if (debugMode)
    {
      Serial.print(F("Menu ocCursor: "));
      Serial.println(ocCursor);
    }
  }
  if (butNOW[1])
  {
    beepStage = RESET;
    beepMode = PosBeep;
    //do stuff when button is HIGH
    butNOW[1] = false; //Set the button to not enable again
    switch (ocCursor)
    {
    case 0: //Food 1

      if (hunger <= max_stats - foodbonus)
        hunger -= foodbonus;
      else
        hunger = max_stats;
      if (random(0, 101) >= Ath)
        weight += 2;
      Dis -= 1;

      aniMode = ani_wibbur_eat;
      aniStage = RESET;
      aniLast = RESET;
      selMenu = mainM;
      display.fillRect(0, 0, 128, 64, 0);
      ocCursor = 2;
      break;
    case 1: //Food 2

      if (happiness <= max_stats - foodbonus)
        happiness -= foodbonus;
      else
        happiness = max_stats;
      if (random(0, 101) >= Ath)
        weight += 2;
      Int -= 1;

      aniMode = ani_wibbur_eat;
      aniStage = RESET;
      aniLast = RESET;
      selMenu = mainM;
      display.fillRect(0, 0, 128, 64, 0);
      ocCursor = 2;
      break;
    case 2: //Food 3
      if (boredom <= max_stats - foodbonus)
        boredom -= foodbonus;
      else
        boredom = max_stats;
      if (random(0, 101) >= Ath)
        weight += 2;
      Ath -= 1;

      aniMode = ani_wibbur_eat;
      aniStage = RESET;
      aniLast = RESET;
      selMenu = mainM;
      display.fillRect(0, 0, 128, 64, 0);
      ocCursor = 2;
      break;
    default:
      break;
    }
  }
  if (butNOW[2])
  {
    beepStage = RESET;
    beepMode = HiLo1;
    //do stuff when button is HIGH
    butNOW[2] = false; //Set the button to not enable again
    selMenu = mainM;
    display.fillRect(0, 0, 128, 64, 0);
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

  //Find out which buttons the user is pressing
  getButton();

  //Figure out how to handle the buttons that getButton() found
  if (butNOW[0])
  {
    beepStage = RESET;
    beepMode = NegBeep;
    //do stuff when button is HIGH
    butNOW[0] = false; //Set the button to not enable again
    ocCursor++;
    if (ocCursor >= 2)
      ocCursor = RESET;
    updateScreen();
    if (debugMode)
    {
      Serial.print(F("Menu ocCursor: "));
      Serial.println(ocCursor);
    }
  }
  if (butNOW[1])
  {
    beepStage = RESET;
    beepMode = PosBeep;
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
    beepStage = RESET;
    beepMode = HiLo1;
    //do stuff when button is HIGH
    butNOW[2] = false; //Set the button to not enable again
    selMenu = mainM;
    display.fillRect(0, 0, 128, 64, 0);
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

  //Find out which buttons the user is pressing
  getButton();

  //Figure out how to handle the buttons that getButton() found
  if (butNOW[0]) //A button is pressed
  {
    beepStage = RESET;
    beepMode = NegBeep;
    //do stuff when button is HIGH
    butNOW[0] = false; //Set the button to not enable again
    ocCursor++;
    if (ocCursor >= 3)
      ocCursor = RESET;
    updateScreen();
    if (debugMode)
    {
      Serial.print(F("Menu ocCursor: "));
      Serial.println(ocCursor);
    }
  }
  if (butNOW[1]) //B button is pressed
  {
    beepStage = RESET;
    beepMode = PosBeep;
    butNOW[1] = false; //Set the button to not enable again

    switch (ocCursor)
    {
    case 0: //Mute Beep
      beepMute = !beepMute;
      beepMode = HiLo1;
      break;
    case 1: //Mute Beep
      buzzMute = !buzzMute;
      beepMode = HiLo1;
      break;
    case 2: //Mute Beep
      beepMode = PosBeep;
      selMenu = c_clockset;
      ocCursor = RESET;
      break;
    default:
      break;
    }
  }
  if (butNOW[2]) //C button is pressed
  {
    beepStage = RESET;
    beepMode = HiLo1;
    //do stuff when button is HIGH
    butNOW[2] = false; //Set the button to not enable again
    selMenu = mainM;
    display.fillRect(0, 0, 128, 64, 0);
  }
}

void clockset()
{
  //Update the screen each standard refresh interval
  if (CLK[baseCLK] - CLK[timeCLK] > ref_int)
  {
    CLK[timeCLK] = CLK[baseCLK];
    hnow = ((((millis() / 1000) / 60) / 60) / 24);
    hnow = (((millis() / 1000) / 60) / 60) % 12;
    mnow = ((millis() / 1000) / 60) % 60;
    snow = (millis() / 1000) % 60;
    updateScreen();
  }

  //Find out which buttons the user is pressing
  getButton();

  //Figure out how to handle the buttons that getButton() found
  if (butNOW[0])
  {
    beepStage = RESET;
    beepMode = NegBeep;
    butNOW[0] = false; //Set the button to not enable again
    ocCursor++;
    if (ocCursor >= 3)
      ocCursor = RESET;
    Serial.print(F("Menu ocCursor: "));
    Serial.println(ocCursor);
    updateScreen();
  }
  if (butNOW[1])
  {
    beepStage = RESET;
    beepMode = PosBeep;
    butNOW[1] = false; //Set the button to not enable again
    if (ocCursor == 0)
    {
      clockOFFSETh++;
      if (clockOFFSETh >= 24)
        clockOFFSETh = RESET;
    }
    if (ocCursor == 1)
    {
      clockOFFSETm++;
      if (clockOFFSETm >= 60)
        clockOFFSETm = RESET;
    }
    if (ocCursor == 2)
    {
      clockOFFSETs++;
      if (clockOFFSETs >= 60)
        clockOFFSETs = RESET;
    }
    updateScreen();
  }
  if (butNOW[2])
  {
    beepStage = RESET;
    beepMode = HiLo1;
    //do stuff when button is HIGH
    butNOW[2] = false; //Set the button to not enable again
    selMenu = confM;
    ocCursor = RESET;
    display.fillRect(0, 0, 128, 64, 0);
  }
}
