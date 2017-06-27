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
    gameVal[nextcard] = random(10);
    gameStage++;
    //clears screen
  }

  else if (gameStage == 1) {
    if (debug) {
      Serial.print(F("stage 1 nextcard is "));
      Serial.println(gameVal[nextcard]);
    }
    display.fillRect(80, 16, 128, 64, 0);
    display.setCursor(96, 16);
    display.setTextColor(1);
    display.setTextSize(2);
    display.print(gameVal[nextcard]);
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
      beepStage = RESET;
      beepMode = UpChirp;
      butNOW[0] = false; //Set the button to not enable again
      gameVal[thiscard] = random(10);
      if (debug) {
        Serial.println(F("Current card: "));
        Serial.print(gameVal[nextcard]);
        Serial.println(F("Drawn card: "));
        Serial.print(gameVal[thiscard]);
      }
      if (gameVal[thiscard] >= gameVal[nextcard]) {
        gameVal[point] = 1;
      }
      else {
        gameVal[point] = 0;
      }
      gameStage++;
    }

    //B button is pressed
    if (butNOW[1])
    {
      beepStage = RESET;
      beepMode = DnChirp;
      butNOW[1] = false; //Set the button to not enable again
      gameVal[thiscard] = random(10);
      if (debug) {
        Serial.print(F("Current card: "));
        Serial.println(gameVal[nextcard]);
        Serial.print(F("Drawn card: "));
        Serial.println(gameVal[thiscard]);
      }
      if (gameVal[thiscard] <= gameVal[nextcard])
        gameVal[point] = 1;
      else
        gameVal[point] = 0;
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
    if (gameVal[point]) {
      if (debug)
        Serial.println(F("You win!"));
      gameVal[point] = 1;
      //WEIGHT DROP ISN'T SUPPOSED TO HAPPEN IN THIS GAME
      if (weight <= 1)
        weight = RESET;
      else
        weight--;
      //WEIGHT DROP ISN'T SUPPOSED TO HAPPEN IN THIS GAME
      Int = Int + 0.01;
      boredom = boredom + 10;
      if (boredom > 100)
        boredom  = 100;
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
      updateScreen();
    }
    display.setCursor(96, 32);
    display.setTextSize(2);
    display.print(gameVal[thiscard]);
    display.drawChar(112, 32, 3 + random(4), 1, 0, 2);
    updateScreen();
    gameStage++;
    if (gameVal[point]) {
      if (debug) {
        Serial.print(F("thiscard is "));
        Serial.println(gameVal[thiscard]);
      }
      gameVal[nextcard] = gameVal[thiscard];
      if (debug) {
        Serial.print(F("stage 3 nextcard is "));
        Serial.println(gameVal[nextcard]);
      }
      CLK[gameCLK] = CLK[baseCLK];
    }
    if (debug) {
      Serial.print(F("stage 3 nextcard is "));
      Serial.println(gameVal[nextcard]);
    }
  }

  else if (gameStage == 4) {
    if (debug) {
      Serial.print(F("stage 4 nextcard is "));
      Serial.println(gameVal[nextcard]);
    }
    //Wait to reset
    if (CLK[baseCLK] - CLK[gameCLK] > 1000) {
      if (debug)
        Serial.println(F("Waited one second. Restarting."));
      gameStage = 1;
      if (debug) {
        Serial.print(F("stage 4 nextcard is "));
        Serial.println(gameVal[nextcard]);
      }
    }
  }
}
