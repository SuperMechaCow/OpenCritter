void aniModeSet (byte brd, byte anitype) {

  switch (brd) {
    case egg:
      switch (anitype) {
        case a_idle:
          aniMode = ani_egg_idle;
          break;
      }
      break;
    case wibbur:
      switch (anitype) {
        case a_idle:
          aniMode = ani_wibbur_idle;
      }
      break;
    case tribbur:
      switch (anitype) {
        case a_idle:
          aniMode = ani_tribbur_idle;
      }
      break;
  }
}

void animate()
{
  switch (aniMode)
  {
    case ani_egg_idle:
      if (aniStage == 0)
      {
        Serial.print(F("Egging at: "));
        Serial.println(metabolism);
        CLK[aniCLK] = CLK[baseCLK];
        aniStage = 1;
      }
      /* //only do a certain number of times
          else if (CLK[baseCLK] - CLK[aniCLK] > (baseHRT_speed * 1.5) * metabolism)
          {
          aniMode = RESET;
          }
      */
      else
      {
        aniStage = 1 + ((CLK[baseCLK] - CLK[aniCLK]) / ((baseHRT_speed * 1) * metabolism));
        if (aniStage % 2) //If odd
        {
          display.fillRect(48, 16, 32, 32, 0);
          display.drawBitmap(48, 16, egg_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(48, 16, 32, 32, 0);
          display.drawBitmap(48, 16, egg_idle, 32, 32, 1);
        }
        if (aniLast != aniStage) //The last stage is not the same odd or even as the current stage
        {
          aniLast = aniStage; //Match the stages
          updateScreen(); //Update the screen
        }
      }
      break;
    case ani_wibbur_idle:
      if (aniStage == 0)
      {
        Serial.print(F("Wibbur idle at: "));
        Serial.println(metabolism);
        CLK[aniCLK] = CLK[baseCLK];
        aniStage = 1;
      }
      /* //only do a certain number of times
          else if (CLK[baseCLK] - CLK[aniCLK] > (baseHRT_speed * 1.5) * metabolism)
          {
          aniMode = RESET;
          }
      */
      else
      {
        aniStage = 1 + ((CLK[baseCLK] - CLK[aniCLK]) / ((baseHRT_speed * 1) * metabolism));
        if (aniStage % 2 == 1)
        {
          display.fillRect(48, 16, 32, 32, 0);
          display.drawBitmap(48, 16, wibbur_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(48, 16, 32, 32, 0);
          display.drawBitmap(48, 16, wibbur_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;
    case ani_wibbur_eat:
      if (aniStage == 0)
      {
        Serial.print(F("Wibbur eat at: "));
        Serial.println(metabolism);
        CLK[aniCLK] = CLK[baseCLK];
        aniStage = 1;
      }
      //only do a certain number of times
      else if (aniStage > 6)
      {
        aniModeSet(breed, a_idle);
        aniStage = RESET;
        aniLast = RESET;
        if (debugMode)
          Serial.println(F("Returning to normal animation"));
      }
      else
      {
        aniStage = 1 + ((CLK[baseCLK] - CLK[aniCLK]) / ((baseHRT_speed * 1) * metabolism));
        if (aniStage % 2 == 1)
        {
          display.fillRect(48, 16, 32, 32, 0);
          display.drawBitmap(48, 16, wibbur_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(48, 16, 32, 32, 0);
          display.drawBitmap(56, 24, icon_food, 16, 16, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      };
      break;
    default:
      break;
  }
}

