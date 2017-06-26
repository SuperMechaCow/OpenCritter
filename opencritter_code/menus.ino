void mainMenu()
{
  animate();
  getButton();
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
    if (debugMode) {
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
    if (debugMode) {
      Serial.print(F("Menu ocCursor: "));
      Serial.println(ocCursor);
    }
    switch (ocCursor) {
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
        beepMode = HiLo1;

        if (weight <= 1)
          weight = RESET;
        else
          weight--;
        break;
      case 5:
        CLK[timeCLK] = CLK[baseCLK];
        selMenu = confM;
        display.fillRect(0, 0, 128, 64, 0);
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
    if (debugMode) {
      Serial.print(F("Menu ocCursor: "));
      Serial.println(ocCursor);
    }
  }
}

void clockMenu()
{
  if (CLK[baseCLK] - CLK[timeCLK] > 1000) {
    //Serial.println(CLK[baseCLK] - CLK[timeCLK]);
    CLK[timeCLK] = CLK[baseCLK];
    hnow = ((((millis() / 1000) / 60) / 60) / 24);
    hnow = (((millis() / 1000) / 60) / 60) % 12;
    mnow = ((millis() / 1000) / 60) % 60;
    snow = (millis() / 1000) % 60;
    updateScreen();
  }
  getButton();
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
  if (CLK[baseCLK] - CLK[timeCLK] > 1000) {
    //Serial.println(CLK[baseCLK] - CLK[timeCLK]);
    CLK[timeCLK] = CLK[baseCLK];
    updateScreen();
  }
  getButton();
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
  if (CLK[baseCLK] - CLK[timeCLK] > 1000) {
    //Serial.println(CLK[baseCLK] - CLK[timeCLK]);
    CLK[timeCLK] = CLK[baseCLK];
    updateScreen();
  }
  getButton();
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
    if (debugMode) {
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
    switch (ocCursor) {
      case 0: //Food 1
        hunger = hunger + 25;
        if (hunger > 100)
          hunger = 100;
        weight = weight + 1;
        aniMode = ani_wibbur_eat;
        aniStage = RESET;
        aniLast = RESET;
        selMenu = mainM;
        display.fillRect(0, 0, 128, 64, 0);
        ocCursor = 2;
        break;
      case 1: //Food 2
        happiness = happiness + 25;
        if (happiness > 100)
          happiness = 100;
        weight = weight + 1;
        aniMode = ani_wibbur_eat;
        aniStage = RESET;
        aniLast = RESET;
        selMenu = mainM;
        display.fillRect(0, 0, 128, 64, 0);
        ocCursor = 2;
        break;
      case 2: //Food 3
        boredom = boredom + 25;
        if (boredom > 100)
          boredom = 100;
        weight = weight + 1;
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

void confMenu() {
  if (CLK[baseCLK] - CLK[timeCLK] > 1000) {
    //Serial.println(CLK[baseCLK] - CLK[timeCLK]);
    CLK[timeCLK] = CLK[baseCLK];
    updateScreen();
  }
  getButton();
  if (butNOW[0]) //A button is pressed
  {
    beepStage = RESET;
    beepMode = NegBeep;
    //do stuff when button is HIGH
    butNOW[0] = false; //Set the button to not enable again
    ocCursor++;
    if (ocCursor >= 1)
      ocCursor = RESET;
    updateScreen();
    if (debugMode) {
      Serial.print(F("Menu ocCursor: "));
      Serial.println(ocCursor);
    }
  }
  if (butNOW[1]) //B button is pressed
  {
    beepStage = RESET;
    beepMode = PosBeep;
    butNOW[1] = false; //Set the button to not enable again

    switch (ocCursor) {
      case 0: //Mute Beep
        beepMute = !beepMute;
        beepMode = HiLo1;
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

void playMenu()
{
  if (CLK[baseCLK] - CLK[timeCLK] > 1000) {
    //Serial.println(CLK[baseCLK] - CLK[timeCLK]);
    CLK[timeCLK] = CLK[baseCLK];
    updateScreen();
  }
  getButton();
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
