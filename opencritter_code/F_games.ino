/*
   Handles all of the minigames in the game

   Note that this does not actually draw the screen. It only handles the "behind the scenes".
   See updateScreen() and animate() for drawing minigames.
*/

void cardflip() {

  animate();
  getButton();

  //Start up
  if (gameStage == 0)  { //If game is not setup or is reset
    //Reset all game variables
    for (int i = 0; i >= sizeof(gameVal); i++) {
      gameVal[i] = 0;
    }
    display.fillRect(0, 0, 128, 64, 0);
    aniModeSet(breed, a_play);
    aniStage = RESET;
    gameVal[gcf_nextcard] = random(10);
    gameStage++;
    //clears screen
  }

  else if (gameStage == 1) {
    if (debug) {
      Serial.print(F("stage 1 gcf_nextcard is "));
      Serial.println(gameVal[gcf_nextcard]);
    }
    display.fillRect(80, 16, 128, 64, 0);
    display.setCursor(96, 16);
    display.setTextColor(1);
    display.setTextSize(2);
    display.print(gameVal[gcf_nextcard]);
    display.drawChar(112, 16, 3 + random(4), 1, 0, 2);
    updateScreen();
    if (debug)
      Serial.println(F("Starting a new round."));
    gameStage++;
  }

  else if (gameStage == 2) {

    //A button is pressed
    if (butNOW[0])
    {
      butNOW[0] = false; //Set the button to not enable again
      gameVal[gcf_thiscard] = random(10);
      if (debug) {
        Serial.println(F("Current card: "));
        Serial.print(gameVal[gcf_nextcard]);
        Serial.println(F("Drawn card: "));
        Serial.print(gameVal[gcf_thiscard]);
      }
      if (gameVal[gcf_thiscard] >= gameVal[gcf_nextcard]) {
        gameVal[gcf_point] = 1;
      }
      else {
        gameVal[gcf_point] = 0;
      }
      gameStage++;
    }

    //B button is pressed
    if (butNOW[1])
    {
      butNOW[1] = false; //Set the button to not enable again
      gameVal[gcf_thiscard] = random(10);
      if (debug) {
        Serial.print(F("Current card: "));
        Serial.println(gameVal[gcf_nextcard]);
        Serial.print(F("Drawn card: "));
        Serial.println(gameVal[gcf_thiscard]);
      }
      if (gameVal[gcf_thiscard] <= gameVal[gcf_nextcard])
        gameVal[gcf_point] = 1;
      else
        gameVal[gcf_point] = 0;
      gameStage++;
    }

    //C button is pressed
    if (butNOW[2])
    {
      beepStage = RESET;
      beepMode = HiLo1;
      //do stuff when button is HIGH
      butNOW[2] = false; //Set the button to not enable again
      if (debug)
        Serial.println(F("Exiting"));
      gameStage = RESET;
      selMenu = mainM;
      aniModeSet(breed, a_idle);
      display.fillRect(0, 0, 128, 64, 0);
    }
  }

  else if (gameStage == 3) {
    if (gameVal[gcf_point]) {
      if (debug)
        Serial.println(F("You win!"));
      beepStage = RESET;
      beepMode = UpChirp;
      gameVal[gcf_point] = 1;
      //WEIGHT DROP ISN'T SUPPOSED TO HAPPEN IN THIS GAME
      if (weight <= 1)
        weight = RESET;
      else
        weight--;
      //WEIGHT DROP ISN'T SUPPOSED TO HAPPEN IN THIS GAME
      Int = Int + 1;
      boredom = boredom + 100;
      if (boredom > 10000)
        boredom  = 10000;
      display.setCursor(80, 48);
      display.setTextColor(1);
      display.setTextSize(1);
      display.print(F("YOU WIN!"));
    }
    else {
      beepStage = RESET;
      beepMode = DnChirp;
      display.setCursor(80, 48);
      display.setTextColor(1);
      display.setTextSize(1);
      display.print(F("You lose"));
      updateScreen();
    }
    display.setCursor(96, 32);
    display.setTextSize(2);
    display.print(gameVal[gcf_thiscard]);
    display.drawChar(112, 32, 3 + random(4), 1, 0, 2);
    updateScreen();
    gameStage++;
    if (gameVal[gcf_point]) {
      if (debug) {
        Serial.print(F("gcf_thiscard is "));
        Serial.println(gameVal[gcf_thiscard]);
      }
      gameVal[gcf_nextcard] = gameVal[gcf_thiscard];
      if (debug) {
        Serial.print(F("stage 3 gcf_nextcard is "));
        Serial.println(gameVal[gcf_nextcard]);
      }
      CLK[gameCLK] = CLK[baseCLK];
    }
    if (debug) {
      Serial.print(F("stage 3 gcf_nextcard is "));
      Serial.println(gameVal[gcf_nextcard]);
    }
  }

  else if (gameStage == 4) {
    if (debug) {
      Serial.print(F("stage 4 gcf_nextcard is "));
      Serial.println(gameVal[gcf_nextcard]);
    }
    //Wait to reset
    if (CLK[baseCLK] - CLK[gameCLK] > 1000) {
      if (debug)
        Serial.println(F("Waited one second. Restarting."));
      gameStage = 1;
      if (debug) {
        Serial.print(F("stage 4 gcf_nextcard is "));
        Serial.println(gameVal[gcf_nextcard]);
      }
    }
  }
}
















































void bitshifter() {

  getButton();

  if (gameStage == 0) {

    //pick a random
    gameVal[gbs_goalbyte] = random(1, 256);
    ocCursor = random(0, 8);

    if (debug) {
      Serial.print(F("Byte is: "));
      Serial.println(gameVal[gbs_goalbyte]);
      Serial.print(F("Cursor is: "));
      Serial.println(ocCursor);
    }

    //Start the game
    gameStage++;
  }

  else if (gameStage == 1) {

    display.fillRect(0, 0, 128, 64, 0);

    display.setCursor(48, 16);
    display.setTextColor(1);
    display.setTextSize(2);

    if (gameVal[gbs_goalbyte] < 100)
      display.print(F("0"));
    if (gameVal[gbs_goalbyte] < 10)
      display.print(F("0"));
    display.print(gameVal[gbs_goalbyte]);

    display.setCursor(40, 32);
    display.setTextSize(1);

    for (int i = 7; i >= 0; i--) {
      display.print((gameVal[gbs_goalbyte] >> ((i + ocCursor) % 8)) % 2);
      Serial.print((gameVal[gbs_goalbyte] >> ((i + ocCursor) % 8)) % 2);
    }
    Serial.println(F(" "));

    updateScreen();

    gameStage++;

  }

  else if (gameStage == 2) {

    //A button is pressed
    if (butNOW[0])
    {
      beepStage = RESET;
      beepMode = PosBeep;
      butNOW[0] = false; //Set the button to not enable again

      //Move the cursor
      ocCursor++;
      if (ocCursor >= 8)
        ocCursor = RESET;
      gameStage--;
    }

    //B button is pressed
    if (butNOW[1])
    {
      butNOW[1] = false; //Set the button to not enable again

      if (ocCursor == 0) {
        beepStage = RESET;
        beepMode = UpChirp;
        gameVal[gbs_point] = 1;
      }
      else {
        gameVal[gbs_point] = 0;
      }
      gameStage++;
    }

    //C button is pressed
    if (butNOW[2])
    {
      beepStage = RESET;
      beepMode = HiLo1;
      //do stuff when button is HIGH
      butNOW[2] = false; //Set the button to not enable again
      if (debug)
        Serial.println(F("Exiting"));
      gameStage = RESET;
      selMenu = mainM;
      aniModeSet(breed, a_idle);
      display.fillRect(0, 0, 128, 64, 0);
    }
  }

  else if (gameStage == 3) {
    if (gameVal[gbs_point]) {
      if (debug)
        Serial.println(F("You win!"));
      gameVal[gbs_point] = RESET;

      //WEIGHT DROP ISN'T SUPPOSED TO HAPPEN IN THIS GAME
      if (weight <= 1)
        weight = RESET;
      else
        weight--;
      //WEIGHT DROP ISN'T SUPPOSED TO HAPPEN IN THIS GAME
      Int = Int + 1;
      boredom = boredom + 100;
      if (boredom > 1000)
        boredom  = 1000;
      display.setCursor(80, 48);
      display.setTextColor(1);
      display.setTextSize(1);
      display.print(F("YOU WIN!"));
    }
    else {
      display.setCursor(80, 48);
      display.setTextColor(1);
      display.setTextSize(1);
      display.print(F("You lose"));
    }
    CLK[gameCLK] = CLK[baseCLK];
    updateScreen();
    gameStage++;

  }

  else if (gameStage == 4) {
    //Wait to reset
    if (CLK[baseCLK] - CLK[gameCLK] > 1000) {
      if (debug)
        Serial.println(F("Waited one second. Restarting."));
      gameStage = RESET;
    }
  }
}
