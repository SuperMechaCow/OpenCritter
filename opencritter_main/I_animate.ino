
/*
   Handles all of the critter animations in the game

   Note that this only prepares the animation for the screen.
   It does not update the screen itself.
   See updateScreen() for screen drawing.

*/


void getGFX(int frameFetch) {
  int index = 0;
  byte gfxsize = 0;
  switch (frameFetch) {
    case icon_food:
      index = icon_food_addr;
      break;
    case icon_clok:
      index = icon_clok_addr;
      break;
    case icon_stat:
      index = icon_stat_addr;
      break;
    case icon_game:
      index = icon_game_addr;
      break;
    case icon_meds:
      index = icon_meds_addr;
      break;
    case icon_conf:
      index = icon_conf_addr;
      break;
    case icon_sick:
      index = icon_sick_addr;
      break;
    case icon_poop:
      index = icon_poop_addr;
      break;
    case icon_unon:
      index = icon_unon_addr;
      break;
    case egg_main:
      index = egg_main_addr;
      break;
    case egg_idle:
      index = egg_idle_addr;
      break;
    case wibbur_main:
      index = wibbur_main_addr;
      break;
    case wibbur_idle:
      index = wibbur_idle_addr;
      break;
    case wibbur_play:
      index = wibbur_idle_addr;
    default:
      index = 0;
      break;
  }

  //Find if it's an icon or a critter
  //  if (frameFetch <= numberoficons)
  //    gfxsize = icon_size;
  //  else
  //    gfxsize = crit_size;
  //
  //  //Load the proper gfx from the address with the right size
  //  for (int i = 0; i < gfxsize; i++) {
  //    gfxBuffer[i] = EEPROM.read(i + index);
  //  }
}


void aniModeSet(byte brd, byte anitype)
{
  switch (brd)
  {
    case egg:
      switch (anitype)
      {
        case a_idle:
          aniMode = ani_egg_idle;
          break;
      }
      break;
    case wibbur:
      switch (anitype)
      {
        case a_idle:
          aniMode = ani_wibbur_idle;
          break;
        case a_eat:
          aniMode = ani_wibbur_eat;
          break;
        case a_play:
          aniMode = ani_wibbur_play;
          break;
      }
      break;
    case tribbur:
      switch (anitype)
      {
        case a_idle:
          aniMode = ani_tribbur_idle;
          break;
        case a_eat:
          aniMode = ani_tribbur_eat;
          break;
        case a_play:
          aniMode = ani_tribbur_play;
          break;
      }
      break;
    case snek:
      switch (anitype)
      {
        case a_idle:
          aniMode = ani_snek_idle;
          break;
        case a_eat:
          aniMode = ani_snek_eat;
          break;
        case a_play:
          aniMode = ani_snek_play;
          break;
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
          //          getGFX(egg_main);
          display.drawBitmap(48, 16, gfx_egg_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(48, 16, 32, 32, 0);
          //          getGFX(egg_idle);
          display.drawBitmap(48, 16, gfx_egg_idle, 32, 32, 1);
        }
        if (aniLast != aniStage) //The last stage is not the same odd or even as the current stage
        {
          aniLast = aniStage; //Match the stages
          updateScreen();     //Update the screen
        }
      }
      break;
    case ani_wibbur_idle:
      if (aniStage == 0)
      {
        CLK[aniCLK] = CLK[baseCLK];
        aniStage = 1;
      }
      else
      {
        aniStage = 1 + ((CLK[baseCLK] - CLK[aniCLK]) / ((baseHRT_speed * 1) * metabolism));
        if (aniStage % 2 == 1)
        {
          display.fillRect(48, 16, 32, 32, 0);
          //          getGFX(wibbur_main);
          display.drawBitmap(48, 16, gfx_wibbur_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(48, 16, 32, 32, 0);
          //          getGFX(wibbur_idle);
          display.drawBitmap(48, 16, gfx_wibbur_idle, 32, 32, 1);
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
        CLK[aniCLK] = CLK[baseCLK];
        aniStage = 1;
      }
      //only do a certain number of times
      else if (aniStage > 6)
      {
        aniModeSet(breed, a_idle);
        aniStage = RESET;
        aniLast = RESET;
      }
      else
      {
        aniStage = 1 + ((CLK[baseCLK] - CLK[aniCLK]) / ((baseHRT_speed * 1) * metabolism));
        if (aniStage % 2 == 1)
        {
          display.fillRect(48, 16, 32, 32, 0);
          //          getGFX(wibbur_main);
          display.drawBitmap(48, 16, gfx_wibbur_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(48, 16, 32, 32, 0);
          //          getGFX(icon_food);
          display.drawBitmap(56, 24, gfx_icon_food, 16, 16, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      };
      break;
    case ani_wibbur_play:
      if (aniStage == 0)
      {
        CLK[aniCLK] = CLK[baseCLK];
        aniStage = 1;
      }
      else
      {
        // Starts on one. How long it's been since clocks synced divided by increments equal to 2000 * 0.25 * 0.5
        aniStage = 1 + ((CLK[baseCLK] - CLK[aniCLK]) / ((baseHRT_speed * 0.25) * metabolism));
        if (aniStage % 2 == 1) //if odd
        {
          display.fillRect(24, 16, 32, 32, 0);
          //          getGFX(wibbur_main);
          display.drawBitmap(48, 16, gfx_wibbur_main, 32, 32, 1);
        }
        else //if even
        {
          display.fillRect(24, 16, 32, 32, 0);
          //          getGFX(wibbur_idle);
          display.drawBitmap(48, 16, gfx_wibbur_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;

    /*== Tribbur ===============================================================================================================*/
    case ani_tribbur_idle:
      if (aniStage == 0)
      {
        CLK[aniCLK] = CLK[baseCLK];
        aniStage = 1;
      }
      else
      {
        aniStage = 1 + ((CLK[baseCLK] - CLK[aniCLK]) / ((baseHRT_speed * 1) * metabolism));
        if (aniStage % 2 == 1)
        {
          display.fillRect(48, 16, 32, 32, 0);
          //          getGFX(tribbur_main);
          display.drawBitmap(48, 16, gfx_tribbur_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(48, 16, 32, 32, 0);
          //          getGFX(tribbur_idle);
          display.drawBitmap(48, 16, gfx_tribbur_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;
    case ani_tribbur_eat:
      if (aniStage == 0)
      {
        CLK[aniCLK] = CLK[baseCLK];
        aniStage = 1;
      }
      //only do a certain number of times
      else if (aniStage > 6)
      {
        aniModeSet(breed, a_idle);
        aniStage = RESET;
        aniLast = RESET;
      }
      else
      {
        aniStage = 1 + ((CLK[baseCLK] - CLK[aniCLK]) / ((baseHRT_speed * 1) * metabolism));
        if (aniStage % 2 == 1)
        {
          display.fillRect(48, 16, 32, 32, 0);
          //          getGFX(tribbur_main);
          display.drawBitmap(48, 16, gfx_tribbur_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(48, 16, 32, 32, 0);
          //          getGFX(icon_food);
          display.drawBitmap(56, 24, gfx_icon_food, 16, 16, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      };
      break;
    case ani_tribbur_play:
      if (aniStage == 0)
      {
        CLK[aniCLK] = CLK[baseCLK];
        aniStage = 1;
      }
      else
      {
        // Starts on one. How long it's been since clocks synced divided by increments equal to 2000 * 0.25 * 0.5
        aniStage = 1 + ((CLK[baseCLK] - CLK[aniCLK]) / ((baseHRT_speed * 0.25) * metabolism));
        if (aniStage % 2 == 1) //if odd
        {
          display.fillRect(24, 16, 32, 32, 0);
          //          getGFX(tribbur_main);
          display.drawBitmap(48, 16, gfx_tribbur_main, 32, 32, 1);
        }
        else //if even
        {
          display.fillRect(24, 16, 32, 32, 0);
          //          getGFX(tribbur_idle);
          display.drawBitmap(48, 16, gfx_tribbur_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;

    /*== Snek ===============================================================================================================*/

    case ani_snek_idle:
      if (aniStage == 0)
      {
        CLK[aniCLK] = CLK[baseCLK];
        aniStage = 1;
      }
      else
      {
        aniStage = 1 + ((CLK[baseCLK] - CLK[aniCLK]) / ((baseHRT_speed * 1) * metabolism));
        if (aniStage % 2 == 1)
        {
          display.fillRect(48, 16, 32, 32, 0);
          //          getGFX(snek_main);
          display.drawBitmap(48, 16, gfx_snek_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(48, 16, 32, 32, 0);
          //          getGFX(snek_idle);
          display.drawBitmap(48, 16, gfx_snek_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;
    case ani_snek_eat:
      if (aniStage == 0)
      {
        CLK[aniCLK] = CLK[baseCLK];
        aniStage = 1;
      }
      //only do a certain number of times
      else if (aniStage > 6)
      {
        aniModeSet(breed, a_idle);
        aniStage = RESET;
        aniLast = RESET;
      }
      else
      {
        aniStage = 1 + ((CLK[baseCLK] - CLK[aniCLK]) / ((baseHRT_speed * 1) * metabolism));
        if (aniStage % 2 == 1)
        {
          display.fillRect(48, 16, 32, 32, 0);
          //          getGFX(snek_main);
          display.drawBitmap(48, 16, gfx_snek_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(48, 16, 32, 32, 0);
          //          getGFX(icon_food);
          display.drawBitmap(56, 24, gfx_icon_food, 16, 16, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      };
      break;
    case ani_snek_play:
      if (aniStage == 0)
      {
        CLK[aniCLK] = CLK[baseCLK];
        aniStage = 1;
      }
      else
      {
        // Starts on one. How long it's been since clocks synced divided by increments equal to 2000 * 0.25 * 0.5
        aniStage = 1 + ((CLK[baseCLK] - CLK[aniCLK]) / ((baseHRT_speed * 0.25) * metabolism));
        if (aniStage % 2 == 1) //if odd
        {
          display.fillRect(24, 16, 32, 32, 0);
          //          getGFX(snek_main);
          display.drawBitmap(48, 16, gfx_snek_main, 32, 32, 1);
        }
        else //if even
        {
          display.fillRect(24, 16, 32, 32, 0);
          //          getGFX(snek_idle);
          display.drawBitmap(48, 16, gfx_snek_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;
    default:
      break;
  }
}
