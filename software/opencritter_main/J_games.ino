/*
   Handles all of the minigames in the game

   Note that this does not actually draw the screen. It only handles the "behind the scenes".
   See updateScreen() and animate() for drawing minigames.
*/


void ballcatch()
{

  //I really wanted to have multiple balls dropping, but this game is good enough

  if (gameStage == 0) //Splash screen
  {
    display.clearDisplay();
    display.setTextColor(1);
    display.setTextSize(2);
    display.setCursor(4, 0);
    display.print(F("Ball Catch"));
    display.setTextSize(1);
    display.setCursor(28, 20);
    display.print(F("Move catcher"));
    display.setCursor(32, 28);
    display.print(F("with A + B."));
    display.setCursor(37, 36);
    display.print(F("Catch the"));
    display.setCursor(24, 44);
    display.print(F("falling balls!"));
    display.setCursor(22, 56);
    display.print(F("Energy: "));
    display.print(NRGcost);
    display.print(F(" ("));
    display.print(NRG);
    display.print(F(")"));
    updateScreen();

    //A OR B button is pressed
    if (butNOW[0] || butNOW[1])
    {
      butNOW[0] = false; //Set the button to not enable again
      if (NRG >= NRGcost) { //If we have enough energy to start a game
        beep(beep_UpChirp);
        NRG -= NRGcost; //Remove that energy cost from the available amount
        gameStage++;
      }
      else { //If we don't have enough energy, just beep
        beep(beep_HiLo1);
      }
    }

    //C button is pressed
    if (butNOW[2])
    { //ABORT! Cancel the game...
      beep(beep_HiLo1);
      //do stuff when button is HIGH
      butNOW[2] = false; //Set the button to not enable again
      for (int i = 0; i <= 9; i++)
      {
        gameVal[i] = 0;
      }
      gameStage = RESET;
      selMenu = mainM;
      aniModeSet(breed, a_idle);
      display.clearDisplay();
    }

  }

  //Start up
  if (gameStage == 1)
  {
    //Make a ball drop... *snicker*
    gameVal[gbc_balls + 3] = random(0, 112);  //Pick a random X value to drop from
    gameVal[gbc_balls + 4] = RESET;           //Reset the Y position to the top of the screen
    gameVal[gbc_balls]++;                     //Add a ball to the current number of balls in play
    //clears screen
    display.clearDisplay();
    updateScreen();
    gameStage++;
  }

  else if (gameStage == 2)
  {
    if (CLK[timeCLK] - CLK[baseCLK] >= (baseHRT_speed * metabolism) / 4) {

      //Drop the balls... *snicker*...
      gameVal[gbc_1Y] += 1 + (gameVal[gbc_score] / 3); //Gets a little faster every three points!

      //Move the paddle
      gameVal[gbc_position] += gameVal[gbc_speed];
      if (gameVal[gbc_position] < 0) {
        gameVal[gbc_position] = 0;
        gameVal[gbc_speed] = gameVal[gbc_speed] * -1;
      }
      if (gameVal[gbc_position] > 112) {
        gameVal[gbc_position] = 112;
        gameVal[gbc_speed] = gameVal[gbc_speed] * -1;
      }
      if (gameVal[gbc_speed] > 0)
        gameVal[gbc_speed] -= 1;
      if (gameVal[gbc_speed] < 0)
        gameVal[gbc_speed] += 1;

      //Draw everything
      display.clearDisplay();
      display.setTextColor(1);
      display.setTextSize(2);
      display.setCursor(0, 0);
      display.print(gameVal[gbc_score]);
      display.drawBitmap(gameVal[gbc_1X], gameVal[gbc_1Y], gfx_icon_clok, 16, 16, 1); // Draw ball
      display.drawBitmap(gameVal[gbc_position], 48, gfx_icon_poop, 16, 16, 1); // Draw character at bottom of screen in it's position
      updateScreen();

      //See if there's a collision
      if (gameVal[gbc_position] - gameVal[gbc_1X] < 16 && gameVal[gbc_position] - gameVal[gbc_1X] > -16 && gameVal[gbc_1Y] > 36) {
        beep(beep_UpChirp);
        gameVal[gbc_score]++;
        gameVal[gbc_balls]--;
        gameStage = 1;

        //Reward
        if (weight < nominal_w)
          if (random(0, 101) <= Ath)
            weight++;
        if (weight > nominal_w)
          if (random(0, 101) <= Ath)
            weight--;
        if (Ath < max_traits)
          Ath++;
      }

      //See if the balls dropped... *SNICKER*
      if (gameVal[gbc_1Y] > 48) {
        beep(beep_DnChirp);
        gameVal[gbc_balls]--;
        gameStage = RESET;
        gameVal[gbc_score] = 0;
      }

      if (butNOW[0])
      {
        //butNOW[0] = false; //Set the button to not enable again
        gameVal[gbc_speed] -= 2;
        if (gameVal[gbc_speed] <= -10)
          gameVal[gbc_speed] = -10;
      }

      //B button is pressed
      if (butNOW[1])
      {
        //butNOW[1] = false; //Set the button to not enable again
        gameVal[gbc_speed] += 2;
        if (gameVal[gbc_speed] >= 10)
          gameVal[gbc_speed] = 10;
      }

      //C button is pressed
      if (butNOW[2])
      { //ABORT! Cancel the game...
        beep(beep_HiLo1);
        //do stuff when button is HIGH
        butNOW[2] = false; //Set the button to not enable again
        for (int i = 0; i <= 9; i++)
        {
          gameVal[i] = 0;
        }
        gameStage = RESET;
        selMenu = mainM;
        aniModeSet(breed, a_idle);
        display.clearDisplay();
      }
    }
  }
}

/*========================================================================================================================*/

void cardflip()
{

  animate(24, 16);

  //Start up
  if (gameStage == 0)
  { //If game is not setup or is reset
    //Reset all game variables
    //for (int i = 0; i <= sizeof(gameVal); i++) //This line didn't work. Returned a sizeof of 40
    for (int i = 0; i <= 9; i++)
    {
      gameVal[i] = 0;
    }
    display.clearDisplay();
    aniModeSet(breed, a_play);
    aniStage = RESET;
    gameVal[gcf_nextcard] = random(10);
    gameStage++;
    //clears screen
  }

  else if (gameStage == 1)
  {
    display.fillRect(80, 16, 128, 64, 0);
    display.setCursor(96, 16);
    display.setTextColor(1);
    display.setTextSize(2);
    display.print(gameVal[gcf_nextcard]);
    display.drawChar(112, 16, 3 + random(4), 1, 0, 2);
    updateScreen();
    gameStage++;
  }

  else if (gameStage == 2)
  {

    //A button is pressed
    if (butNOW[0])
    {
      butNOW[0] = false; //Set the button to not enable again
      gameVal[gcf_thiscard] = random(10);
      if (gameVal[gcf_thiscard] >= gameVal[gcf_nextcard])
      {
        gameVal[gcf_point] = 1;
      }
      else
      {
        gameVal[gcf_point] = 0;
      }
      gameStage++;
    }

    //B button is pressed
    if (butNOW[1])
    {
      butNOW[1] = false; //Set the button to not enable again
      gameVal[gcf_thiscard] = random(10);
      if (gameVal[gcf_thiscard] <= gameVal[gcf_nextcard])
        gameVal[gcf_point] = 1;
      else
        gameVal[gcf_point] = 0;
      gameStage++;
    }

    //C button is pressed
    if (butNOW[2])
    {

      beep(beep_HiLo1);
      //do stuff when button is HIGH
      butNOW[2] = false; //Set the button to not enable again
      for (int i = 0; i <= 9; i++)
      {
        gameVal[i] = 0;
      }
      gameStage = RESET;
      selMenu = mainM;
      aniModeSet(breed, a_idle);
      display.clearDisplay();
    }
  }

  else if (gameStage == 3)
  {
    if (gameVal[gcf_point])
    {

      beep(beep_UpChirp);
      gameVal[gcf_point] = 1;
      //WEIGHT DROP ISN'T SUPPOSED TO HAPPEN IN THIS GAME
      if (weight <= 1)
        weight = RESET;
      else
        weight--;

      if (Dis < max_traits)
        Dis++;

      if (hap + gamebonus > max_stats)
        hap = max_stats;
      else
        hap = hap + gamebonus;

      display.setCursor(80, 48);
      display.setTextColor(1);
      display.setTextSize(1);
      display.print(F("YOU WIN!"));
    }
    else
    {

      beep(beep_DnChirp);
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
    if (gameVal[gcf_point])
    {
      gameVal[gcf_nextcard] = gameVal[gcf_thiscard];
      CLK[timeCLK] = CLK[baseCLK];
    }
  }

  else if (gameStage == 4)
  {
    //Wait to reset
    if (CLK[baseCLK] - CLK[timeCLK] > 1000)
    {
      gameStage = 1;
    }
  }
}

/*========================================================================================================================*/

void bitshifter()
{
  if (gameStage == 0) {

    display.clearDisplay();
    display.setTextColor(1);
    display.setTextSize(2);
    display.setCursor(4, 0);
    display.print(F("Bit Shifter"));
    display.setTextSize(1);
    display.setCursor(0, 20);
    display.print(F("Rotate bits with A."));
    display.setCursor(0, 28);
    display.print(F("When the byte matches"));
    display.setCursor(0, 36);
    display.print(F("the number above,"));
    display.setCursor(0, 44);
    display.print(F("confirm with B."));
    display.setCursor(22, 56);
    display.print(F("Energy: "));
    display.print(NRGcost);
    display.print(F(" ("));
    display.print(NRG);
    display.print(F(")"));
    updateScreen();

    //A OR B button is pressed
    if (butNOW[0] || butNOW[1])
    {
      butNOW[0] = false; //Set the button to not enable again
      if (NRG >= NRGcost) { //If we have enough energy to start a game
        beep(beep_UpChirp);
        NRG -= NRGcost; //Remove that energy cost from the available amount
        gameStage++;
      }
      else { //If we don't have enough energy, just beep
        beep(beep_HiLo1);
      }
    }

    //C button is pressed
    if (butNOW[2])
    { //ABORT! Cancel the game...
      beep(beep_HiLo1);
      //do stuff when button is HIGH
      butNOW[2] = false; //Set the button to not enable again
      for (int i = 0; i <= 9; i++)
      {
        gameVal[i] = 0;
      }
      gameStage = RESET;
      selMenu = mainM;
      aniModeSet(breed, a_idle);
      display.clearDisplay();
    }
  }
  else {
    //The critter animation plays on every screen except the title screen
    animate(16, 12);
  }

  if (gameStage == 1)
  {

    //pick a random
    gameVal[gbs_goalbyte] = random(1, 256);
    ocCursor = random(0, 8);

    //Start the game
    gameStage++;
  }

  else if (gameStage == 2)
  {

    display.clearDisplay();

    display.setCursor(80, 16);
    display.setTextColor(1);
    display.setTextSize(2);

    if (gameVal[gbs_score] > 3) {
      display.print(gameVal[gbs_goalbyte], HEX);
    }
    else {
      if (gameVal[gbs_goalbyte] < 100)
        display.print(F("0"));
      if (gameVal[gbs_goalbyte] < 10)
        display.print(F("0"));
      display.print(gameVal[gbs_goalbyte]);
    }

    display.setCursor(72, 32);
    display.setTextSize(1);

    for (int i = 7; i >= 0; i--)
    {
      display.print((gameVal[gbs_goalbyte] >> ((i + ocCursor) % 8)) % 2);
    }
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.print(gameVal[gbs_score]);
    updateScreen();

    gameStage++;
  }

  else if (gameStage == 3)
  {

    //A button is pressed
    if (butNOW[0])
    {

      beep(beep_PosBeep);
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

      if (ocCursor == 0)
      {

        beep(beep_UpChirp);
        gameVal[gbs_point] = 1;
        gameVal[gbs_score]++;
      }
      else
      {
        beep(beep_DnChirp);
        gameVal[gbs_point] = 0;
        gameVal[gbs_score] = RESET;
      }
      gameStage++;
    }

    //C button is pressed
    if (butNOW[2])
    {

      beep(beep_HiLo1);
      //do stuff when button is HIGH
      butNOW[2] = false; //Set the button to not enable again
      for (int i = 0; i <= 9; i++)
      {
        gameVal[i] = 0;
      }
      gameStage = RESET;
      selMenu = mainM;
      ocCursor = RESET;
      aniModeSet(breed, a_idle);
      display.clearDisplay();
    }
  }

  else if (gameStage == 4)
  {
    if (gameVal[gbs_point])
    {
      gameVal[gbs_point] = RESET;

      if (Int < max_traits)
        Int++;

      if (bor + gamebonus > max_stats)
        bor = max_stats;
      else
        bor = bor + gamebonus;

      display.setCursor(80, 48);
      display.setTextColor(1);
      display.setTextSize(1);
      display.print(F("YOU WIN!"));
      //Wait to reset
      if (CLK[baseCLK] - CLK[timeCLK] > 1000)
      {
        gameStage = 1;
      }
    }
    else
    {
      display.setCursor(80, 48);
      display.setTextColor(1);
      display.setTextSize(1);
      display.print(F("You lose"));
      //Wait to reset
      if (CLK[baseCLK] - CLK[timeCLK] > 1000)
      {
        gameStage = RESET;
      }
    }
    CLK[timeCLK] = CLK[baseCLK];
    updateScreen();
  }
}


/*========================================================================================================================*/


void lazerchiken()
{

  //I really wanted to have multiple balls dropping, but this game is good enough

  if (gameStage == 0) //Splash screen
  {
    display.clearDisplay();
    display.setTextColor(1);
    display.setTextSize(2);
    display.setCursor(4, 0);
    display.print(F("Ball Catch"));
    display.setTextSize(1);
    display.setCursor(28, 20);
    display.print(F("Move catcher"));
    display.setCursor(32, 28);
    display.print(F("with A + B."));
    display.setCursor(37, 36);
    display.print(F("Catch the"));
    display.setCursor(24, 44);
    display.print(F("falling balls!"));
    display.setCursor(22, 56);
    display.print(F("Energy: "));
    display.print(NRGcost);
    display.print(F(" ("));
    display.print(NRG);
    display.print(F(")"));
    updateScreen();

    //A OR B button is pressed
    if (butNOW[0] || butNOW[1])
    {
      butNOW[0] = false; //Set the button to not enable again
      if (NRG >= NRGcost) { //If we have enough energy to start a game
        beep(beep_UpChirp);
        NRG -= NRGcost; //Remove that energy cost from the available amount
        gameStage++;
      }
      else { //If we don't have enough energy, just beep
        beep(beep_HiLo1);
      }
    }

    //C button is pressed
    if (butNOW[2])
    { //ABORT! Cancel the game...
      beep(beep_HiLo1);
      //do stuff when button is HIGH
      butNOW[2] = false; //Set the button to not enable again
      for (int i = 0; i <= 9; i++)
      {
        gameVal[i] = 0;
      }
      gameStage = RESET;
      selMenu = mainM;
      aniModeSet(breed, a_idle);
      display.clearDisplay();
    }

  }

  //Start up
  if (gameStage == 1)
  {
    //Make a ball drop... *snicker*
    gameVal[lcc_balls + 3] = 128;             //Right edge of screen
    gameVal[lcc_balls + 4] = random(1, 48);   //Anywhere up and down on the right edge without leaving the bottom of the screen
    gameVal[lcc_balls]++;
    //clears screen
    display.clearDisplay();
    updateScreen();
    gameStage++;
  }

  else if (gameStage == 2)
  {
    if (CLK[timeCLK] - CLK[baseCLK] >= (baseHRT_speed * metabolism) / 4) {

      //Move the target
      gameVal[lcc_1X] -= 1 + (gameVal[lcc_score] / 3); //Gets a little faster every three points!

      //Move the laser
      if (gameVal[lcc_lazerX] != RESET)
        gameVal[lcc_lazerX] += (1 + (gameVal[lcc_score] / 3)) * 3; //Gets a little faster every three points!
      if (gameVal[lcc_lazerX] >= 128)
        gameVal[lcc_lazerX] = RESET;

      //Move the paddle
      gameVal[lcc_position] += gameVal[lcc_speed];
      if (gameVal[lcc_position] < 0) {
        gameVal[lcc_position] = 0;
        gameVal[lcc_speed] = 0;
      }
      if (gameVal[lcc_position] > 48) {
        gameVal[lcc_position] = 48;
        gameVal[lcc_speed] = (gameVal[lcc_speed] * -1) / 2;
      }
      if (gameVal[lcc_speed] > -10)
        gameVal[lcc_speed] += 1;

      //Draw everything
      display.clearDisplay();
      display.setTextColor(1);
      display.setTextSize(2);
      display.setCursor(0, 0);
      display.print(gameVal[lcc_score]);
      display.drawBitmap(gameVal[lcc_1X], gameVal[lcc_1Y], gfx_icon_clok, 16, 16, 1); // Draw ball
      display.drawBitmap(0, gameVal[lcc_position], gfx_icon_poop, 16, 16, 1); // Draw character at left edge of screen in it's position
      if (gameVal[lcc_lazerX] != RESET)
        display.drawLine(gameVal[lcc_lazerX], gameVal[lcc_lazerY], gameVal[lcc_lazerX] + lcc_lazersize, gameVal[lcc_lazerY], 1);
      updateScreen();

      //See if there's a collision
      if (gameVal[lcc_lazerY] - gameVal[lcc_1Y] < 16 && gameVal[lcc_lazerY] - gameVal[lcc_1Y] > -16 && gameVal[lcc_1X] - (gameVal[lcc_lazerX] + lcc_lazersize) <= 0) {
        gameVal[lcc_lazerX] = RESET;
        gameVal[lcc_lazerY] = RESET;
        beep(beep_UpChirp);
        gameVal[lcc_score]++;
        gameVal[lcc_balls]--;
        gameStage = 1;

        //Reward
        if (weight < nominal_w)
          if (random(0, 101) <= Ath)
            weight++;
        if (weight > nominal_w)
          if (random(0, 101) <= Ath)
            weight--;
        if (Ath < max_traits)
          Ath++;
      }

      //See if the balls dropped... *SNICKER*
      if (gameVal[lcc_1X] <= 0) {
        beep(beep_DnChirp);
        gameVal[lcc_balls]--;
        gameStage = RESET;
        gameVal[lcc_score] = 0;
      }

      if (butNOW[0])
      {
        //butNOW[0] = false; //Set the button to not enable again
        gameVal[lcc_speed] -= 2;
        if (gameVal[lcc_speed] <= -10)
          gameVal[lcc_speed] = -10;
      }

      //B button is pressed
      if (butNOW[1])
      {
        butNOW[1] = false; //Set the button to not enable again
        if (gameVal[lcc_lazerX] == RESET) {
          beep(beep_Bip);
          gameVal[lcc_lazerX] = 1;
          gameVal[lcc_lazerY] = gameVal[lcc_position] + 8;
        }
      }

      //C button is pressed
      if (butNOW[2])
      { //ABORT! Cancel the game...
        beep(beep_HiLo1);
        //do stuff when button is HIGH
        butNOW[2] = false; //Set the button to not enable again
        for (int i = 0; i <= 9; i++)
        {
          gameVal[i] = 0;
        }
        gameStage = RESET;
        selMenu = mainM;
        aniModeSet(breed, a_idle);
        display.clearDisplay();
      }
    }
  }
}