/*
   Handles all of the minigames in the game

   Note that this does not actually draw the screen. It only handles the "behind the scenes".
   See updateScreen() and animate() for drawing minigames.
*/

/*========================================================================================================================*/

void ballcatch() {

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
    display.print(EnergyCost);
    display.print(F(" ("));
    display.print(Energy);
    display.print(F(")"));
    updateScreen();

    //A OR B button is pressed
    if (butNOW[0] || butNOW[1])
    {
      butNOW[0] = false; //Set the button to not enable again
      if (Energy >= EnergyCost) { //If we have enough energy to start a game
        beep(beep_UpChirp);
        Energy -= EnergyCost; //Remove that energy cost from the available amount
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
      aniMode = a_idle;
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
      if (!gameVal[gbc_ballframe]) {
        display.drawBitmap(gameVal[gbc_1X], gameVal[gbc_1Y], gfx_icon_ball, 16, 16, 1); // Draw ball
        gameVal[gbc_ballframe] = 1;
      }
      else {
        display.drawBitmap(gameVal[gbc_1X], gameVal[gbc_1Y], gfx_icon_balf, 16, 16, 1); // Draw ball
        gameVal[gbc_ballframe] = 0;
      }
      display.drawBitmap(gameVal[gbc_position], 48, gfx_icon_pail, 16, 16, 1); // Draw character at bottom of screen in it's position
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
        if (Ath < max_power)
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
        aniMode = a_idle;
        display.clearDisplay();
      }
    }
  }
}

/*========================================================================================================================*/

void cardflip() {

  if (gameStage == 0) //Splash screen
  {
    display.clearDisplay();
    display.setTextColor(1);
    display.setTextSize(2);
    display.setCursor(4, 0);
    display.print(F("Card Flip"));
    display.setTextSize(1);
    display.setCursor(0, 20);
    display.print(F("Guess if the next"));
    display.setCursor(0, 28);
    display.print(F("card will be higher"));
    display.setCursor(0, 36);
    display.print(F("or lower with A or B."));
    display.setCursor(0, 44);
    display.print(F("Best of 5."));
    display.setCursor(0, 56);
    display.print(F("Energy: "));
    display.print(EnergyCost);
    display.print(F(" ("));
    display.print(Energy);
    display.print(F(")"));
    updateScreen();

    //A OR B button is pressed
    if (butNOW[0] || butNOW[1])
    {
      butNOW[0] = false; //Set the button to not enable again
      if (Energy >= EnergyCost) { //If we have enough energy to start a game
        beep(beep_UpChirp);
        Energy -= EnergyCost; //Remove that energy cost from the available amount
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
      aniMode = a_idle;
      display.clearDisplay();
    }

  }
  else {
    animate(24, 16);
  }

  //Start up
  if (gameStage == 1)
  { //If game is not setup or is reset
    //Reset all game variables
    //for (int i = 0; i <= sizeof(gameVal); i++) //This line didn't work. Returned a sizeof of 40
    for (int i = 0; i <= 9; i++) //I don't like 9 being a constant like this. Needs fixed.
    {
      gameVal[i] = 0;
    }
    display.clearDisplay();             //Clear the display and set the animation
    aniMode = a_play;
    aniStage = RESET;
    gameVal[gcf_nextcard] = random(10); //Pick the first card's value (0-9)
    gameVal[gcf_round] = RESET;         //Set the current round to 0
    gameStage++;                        //Move on to the next stage
  }

  else if (gameStage == 2)
  { //This stage just draws the UI once
    //Erase score area
    display.fillRect(12, 0, 72, 16, 0);
    //Draw rounds won
    for (int i = 0; i < gameVal[gcf_score]; i++) {
      display.drawChar(12 + (i * 12), 0, 2, 1, 0, 2);
    }
    //Draw rounds lost
    for (int i = 0; i < (gameVal[gcf_round] - gameVal[gcf_score]); i++) {
      display.drawChar(12 + (gameVal[gcf_score] * 12) + (i * 12), 0, 1, 1, 0, 2);
    }
    //Erase card area
    display.fillRect(80, 16, 128, 64, 0);
    //Draw current card
    display.setCursor(96, 16);
    display.setTextColor(1);
    display.setTextSize(2);
    display.print(gameVal[gcf_nextcard]);
    display.drawChar(112, 16, 3 + random(4), 1, 0, 2);
    updateScreen();   //Draw this new data to screen
    gameStage++;      //Move on to nextr round
  }

  else if (gameStage == 3)
  { //This stage waits for a button press, then picks a card at random and compares
    //A button is pressed, meaning the player thinks the next card will be greater
    if (butNOW[0])
    {
      butNOW[0] = false; //Set the button to not enable again
      //Pick the next card
      gameVal[gcf_thiscard] = random(10);
      //If it's greater, the player scores a point
      if (gameVal[gcf_thiscard] >= gameVal[gcf_nextcard])
        gameVal[gcf_point] = 1;
      else
        gameVal[gcf_point] = 0;
      //Move to the next stage
      gameStage++;
    }

    //B button is pressed, meaning the player thinks the next card will be less
    if (butNOW[1])
    {
      butNOW[1] = false; //Set the button to not enable again
      //Pick the next card
      gameVal[gcf_thiscard] = random(10);
      //If it's less, the player scores a point
      if (gameVal[gcf_thiscard] <= gameVal[gcf_nextcard])
        gameVal[gcf_point] = 1;
      else
        gameVal[gcf_point] = 0;
      //Move to the next stage
      gameStage++;
    }

    //C button is pressed
    if (butNOW[2])
    {
      //Cancel and leave game
      beep(beep_HiLo1);
      //do stuff when button is HIGH
      butNOW[2] = false; //Set the button to not enable again
      for (int i = 0; i <= 9; i++)
      {
        gameVal[i] = 0;
      }
      gameStage = RESET;
      selMenu = mainM;
      aniMode = a_idle;
      display.clearDisplay();
    }
  }

  else if (gameStage == 4)
  {
    if (gameVal[gcf_point]) { //If the player scored a point last stage
      beep(beep_UpChirp); //Play a winning sound!
      //Tell the player they won!
      display.setCursor(80, 48);
      display.setTextColor(1);
      display.setTextSize(1);
      display.print(F("YOU WIN!"));
      //Add a point to the score
      gameVal[gcf_score]++;
      //Make the new card be the next card we have to guess against
      gameVal[gcf_nextcard] = gameVal[gcf_thiscard];
    }
    else {
      //Play a losing sound :(
      beep(beep_DnChirp);
      //Tell the player they lost
      display.setCursor(80, 48);
      display.setTextColor(1);
      display.setTextSize(1);
      display.print(F("You lose"));
    }
    //Show the card that got flipped
    display.setCursor(96, 32);
    display.setTextSize(2);
    display.print(gameVal[gcf_thiscard]);
    display.drawChar(112, 32, 3 + random(4), 1, 0, 2);
    updateScreen();
    //Set the clock to the current time so we know how long to show this screen
    CLK[timeCLK] = CLK[baseCLK];
    //Add one to the number of rounds we've played
    gameVal[gcf_round]++;
    //If we've played five rounds now
    if (gameVal[gcf_round] == 5) {
      //See if we've gotten at least three points to win a best of 5
      if (gameVal[gcf_score] >= 3) {
        //for every point we scored
        for (int i = 0; i < gameVal[gcf_score]; i++) {
          //give the typical bonus
          if (Dis < max_power)
            Dis++;
          if (hap + gamebonus > max_health)
            hap = max_health;
          else
            hap = hap + gamebonus;
        }
      }
      gameStage = 5; //Gameover Screen
    }
    else {
      gameStage = 6; //Pause for user to see results
    }
  }

  else if (gameStage == 5)
  {
    //Wait to reset
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(2);

    if (gameVal[gcf_score] >= 3) {
      display.print(F("You Win!"));
    }
    else {
      display.print(F("You Lose"));
    }

    for (int i = 0; i < gameVal[gcf_score]; i++) {
      display.drawChar(64 + (i * 12), 24, 2, 1, 0, 2);
    }
    for (int i = 0; i < (gameVal[gcf_round] - gameVal[gcf_score]); i++) {
      display.drawChar(64 + (gameVal[gcf_score] * 12) + (i * 12), 24, 1, 1, 0, 2);
    }
    gameStage = 6;
  }

  else if (gameStage == 6) {
    if (CLK[baseCLK] - CLK[timeCLK] > 1000) //Wait one second
    {
      if (gameVal[gcf_round] == 5) { //Unless we've played all five rounds
        if (CLK[baseCLK] - CLK[timeCLK] > 3000) //Then wait three instead
          gameStage = RESET; //Back to the title screen
      }
      else {
        gameStage = 2; //Back to flip another card
      }
    }
  }
}

/*========================================================================================================================*/

void bitshifter() {

  if (gameStage == 0) {

    display.clearDisplay();
    display.setTextColor(1);
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.print(F("BitShifter"));
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
    display.print(EnergyCost);
    display.print(F(" ("));
    display.print(Energy);
    display.print(F(")"));
    updateScreen();

    //A OR B button is pressed
    if (butNOW[0] || butNOW[1])
    {
      butNOW[0] = false; //Set the button to not enable again
      if (Energy >= EnergyCost) { //If we have enough energy to start a game
        beep(beep_UpChirp);
        Energy -= EnergyCost; //Remove that energy cost from the available amount
        gameStage++;
      }
      else { //If we don't have enough energy, just beep
        beep(beep_HiLo1);
      }
      display.clearDisplay();
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
      aniMode = a_idle;
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
    gameVal[gbs_point] = RESET;
    gameVal[gbs_goalbyte] = random(1, 256);
    ocCursor = random(0, 8);

    //Start the game
    gameStage++;
  }

  else if (gameStage == 2)
  {
    display.fillRect(72, 0, 60, 16, 0);     //Cover Score
    display.fillRect(72, 16, 48, 32, 0);    //Cover numbers
    display.fillRect(72, 40, 48, 8, 0);     //Cover win/lose
    display.setTextColor(1);
    display.setCursor(72, 0);
    display.setTextSize(1);
    display.print(F("Score: "));
    display.print(gameVal[gbs_score]);

    display.setTextSize(2);
    if (gameVal[gbs_score] > 3) {
      display.setCursor(72, 16);
      display.print(F("0x"));
      if (gameVal[gbs_goalbyte] < 16)
        display.print(F("0"));
      display.print(gameVal[gbs_goalbyte], HEX);
    }
    else {
      display.setCursor(80, 16);
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

    display.setCursor(1, 56);
    display.print(F("128 64 32 16 8 4 2 1"));

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
      aniMode = a_idle;
      display.clearDisplay();
    }
  }

  else if (gameStage == 4) { //Show the win/lose screen, and
    if (gameVal[gbs_point]) //If they scored a point!
    {
      if (Int < max_power)
        Int++;

      if (bor + gamebonus > max_health)
        bor = max_health;
      else
        bor = bor + gamebonus;

      display.setCursor(72, 40);
      display.setTextColor(1);
      display.setTextSize(1);
      display.print(F("YOU WIN!"));
    }
    else { //If they didn't score a point and the game ended
      display.setCursor(72, 40);
      display.setTextColor(1);
      display.setTextSize(1);
      display.print(F("You lose"));
    }
    updateScreen();
    CLK[timeCLK] = CLK[baseCLK];  //We sync up the clock here once so we can check it in the next game stage
    gameStage++;                  //The next game stage will show this screen for a set amount of time
  }

  else if (gameStage == 5) {  //Wait to restart the game or round
    //Wait to reset
    if (gameVal[gbs_point]) { //If we scored a point
      if (CLK[baseCLK] - CLK[timeCLK] > 1000) //If 1 second has passed
      {
        gameStage = 1; //Continue with a new round
      }
    }
    else { //If we didn't score a point
      if (CLK[baseCLK] - CLK[timeCLK] > 3000) //If 3 seconds have passed
      {
        gameStage = RESET; //Go back to the title screen
      }
    }
  }
}


/*========================================================================================================================*/

void lazerchiken() {

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
    display.print(EnergyCost);
    display.print(F(" ("));
    display.print(Energy);
    display.print(F(")"));
    updateScreen();

    //A OR B button is pressed
    if (butNOW[0] || butNOW[1])
    {
      butNOW[0] = false; //Set the button to not enable again
      if (Energy >= EnergyCost) { //If we have enough energy to start a game
        beep(beep_UpChirp);
        Energy -= EnergyCost; //Remove that energy cost from the available amount
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
      aniMode = a_idle;
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
      display.drawBitmap(gameVal[lcc_1X], gameVal[lcc_1Y], gfx_icon_jetl, 16, 16, 1); // Draw ball
      display.drawBitmap(0, gameVal[lcc_position], gfx_icon_jetr, 16, 16, 1); // Draw character at left edge of screen in it's position
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
          if (random(0, max_power + 1) <= Ath)
            weight++;
        if (weight > nominal_w)
          if (random(0, max_power + 1) <= Ath)
            weight--;
        if (Ath < max_power)
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
        aniMode = a_idle;
        display.clearDisplay();
      }
    }
  }
}
