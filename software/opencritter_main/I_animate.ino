/*
   Handles all of the critter animations in the game

   Note that this only prepares the animation for the screen.
   It does not update the screen itself.
   See updateScreen() for screen drawing.

*/


//NEEDS A MORE DYNAMIC WAY OF PICKING FRAMES!
//This is a lot of copy/paste code that doesn't need to exist

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

    case xorby:
      switch (anitype)
      {
        case a_idle:
          aniMode = ani_xorby_idle;
          break;
        case a_eat:
          aniMode = ani_xorby_eat;
          break;
        case a_play:
          aniMode = ani_xorby_play;
          break;
      }
      break;

    case goob:
      switch (anitype)
      {
        case a_idle:
          aniMode = ani_goob_idle;
          break;
        case a_eat:
          aniMode = ani_goob_eat;
          break;
        case a_play:
          aniMode = ani_goob_play;
          break;
      }
      break;

    case hwooty:
      switch (anitype)
      {
        case a_idle:
          aniMode = ani_hwooty_idle;
          break;
        case a_eat:
          aniMode = ani_hwooty_eat;
          break;
        case a_play:
          aniMode = ani_hwooty_play;
          break;
      }
      break;

    case flip:
      switch (anitype)
      {
        case a_idle:
          aniMode = ani_flip_idle;
          break;
        case a_eat:
          aniMode = ani_flip_eat;
          break;
        case a_play:
          aniMode = ani_flip_play;
          break;
      }
      break;

    case lugerd:
      switch (anitype)
      {
        case a_idle:
          aniMode = ani_lugerd_idle;
          break;
        case a_eat:
          aniMode = ani_lugerd_eat;
          break;
        case a_play:
          aniMode = ani_lugerd_play;
          break;
      }
      break;

    case moops:
      switch (anitype)
      {
        case a_idle:
          aniMode = ani_moops_idle;
          break;
        case a_eat:
          aniMode = ani_moops_eat;
          break;
        case a_play:
          aniMode = ani_moops_play;
          break;
      }
      break;

    case shansy:
      switch (anitype)
      {
        case a_idle:
          aniMode = ani_shansy_idle;
          break;
        case a_eat:
          aniMode = ani_shansy_eat;
          break;
        case a_play:
          aniMode = ani_shansy_play;
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
  }
}

void animate(byte Xpos, byte Ypos)
{ //Play the animation stored in aniMode at position X and Y
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_egg_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);

          //          unsigned char flipbuffer[] = {0};
          //          for (int i = 0; i <= sizeof(gfx_egg_main); i++) {
          //            for (int j = 1; j <= 8; j++) {
          //              flipbuffer[i] = ((gfx_egg_main[i] / j) % 2) * (128 / j);
          //            }
          //          }
          //          display.drawBitmap(Xpos, Ypos, flipbuffer, 32, 32, 1);
          
          display.drawBitmap(Xpos, Ypos, gfx_egg_idle, 32, 32, 1);
        }
        if (aniLast != aniStage) //The last stage is not the same odd or even as the current stage
        {
          aniLast = aniStage; //Match the stages
          updateScreen();     //Update the screen
        }
      }
      break;

    /*== Wibbur =============================================================================================================*/

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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(wibbur_main);
          display.drawBitmap(Xpos, Ypos, gfx_wibbur_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(wibbur_idle);
          display.drawBitmap(Xpos, Ypos, gfx_wibbur_idle, 32, 32, 1);
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(wibbur_main);
          display.drawBitmap(Xpos, Ypos, gfx_wibbur_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(icon_food);
          display.drawBitmap(Xpos + 8, Ypos + 8, gfx_icon_food, 16, 16, 1);
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(wibbur_main);
          display.drawBitmap(Xpos, Ypos, gfx_wibbur_main, 32, 32, 1);
        }
        else //if even
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(wibbur_idle);
          display.drawBitmap(Xpos, Ypos, gfx_wibbur_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;

    /*== xorby ==============================================================================================================*/

    case ani_xorby_idle:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_xorby_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_xorby_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;
    case ani_xorby_eat:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_xorby_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos + 8, Ypos + 8, gfx_icon_food, 16, 16, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      };
      break;
    case ani_xorby_play:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_xorby_main, 32, 32, 1);
        }
        else //if even
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_xorby_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;

    /*== goob =============================================================================================================*/

    case ani_goob_idle:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_goob_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_goob_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;
    case ani_goob_eat:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_goob_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos + 8, Ypos + 8, gfx_icon_food, 16, 16, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      };
      break;
    case ani_goob_play:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_goob_main, 32, 32, 1);
        }
        else //if even
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_goob_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;

    /*== hwooty =============================================================================================================*/

    case ani_hwooty_idle:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(hwooty_main);
          display.drawBitmap(Xpos, Ypos, gfx_hwooty_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(hwooty_idle);
          display.drawBitmap(Xpos, Ypos, gfx_hwooty_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;
    case ani_hwooty_eat:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(hwooty_main);
          display.drawBitmap(Xpos, Ypos, gfx_hwooty_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(icon_food);
          display.drawBitmap(Xpos + 8, Ypos + 8, gfx_icon_food, 16, 16, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      };
      break;
    case ani_hwooty_play:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(hwooty_main);
          display.drawBitmap(Xpos, Ypos, gfx_hwooty_main, 32, 32, 1);
        }
        else //if even
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(hwooty_idle);
          display.drawBitmap(Xpos, Ypos, gfx_hwooty_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;

    /*== flip =============================================================================================================*/

    case ani_flip_idle:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_flip_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_flip_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;
    case ani_flip_eat:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_flip_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos + 8, Ypos + 8, gfx_icon_food, 16, 16, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      };
      break;
    case ani_flip_play:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_flip_main, 32, 32, 1);
        }
        else //if even
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_flip_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;

    /*== lugerd =============================================================================================================*/

    case ani_lugerd_idle:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_lugerd_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_lugerd_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;
    case ani_lugerd_eat:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_lugerd_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos + 8, Ypos + 8, gfx_icon_food, 16, 16, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      };
      break;
    case ani_lugerd_play:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_lugerd_main, 32, 32, 1);
        }
        else //if even
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_lugerd_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;

    /*== moops =============================================================================================================*/

    case ani_moops_idle:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_moops_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_moops_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;
    case ani_moops_eat:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_moops_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos + 8, Ypos + 8, gfx_icon_food, 16, 16, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      };
      break;
    case ani_moops_play:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_moops_main, 32, 32, 1);
        }
        else //if even
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_moops_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;

    /*== shansy =============================================================================================================*/

    case ani_shansy_idle:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_shansy_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_shansy_idle, 32, 32, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;
    case ani_shansy_eat:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_shansy_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos + 8, Ypos + 8, gfx_icon_food, 16, 16, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      };
      break;
    case ani_shansy_play:
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_shansy_main, 32, 32, 1);
        }
        else //if even
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_shansy_idle, 32, 32, 1);
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_tribbur_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_tribbur_idle, 32, 32, 1);
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_tribbur_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos + 8, Ypos + 8, gfx_icon_food, 16, 16, 1);
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_tribbur_main, 32, 32, 1);
        }
        else //if even
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, gfx_tribbur_idle, 32, 32, 1);
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(snek_main);
          display.drawBitmap(Xpos, Ypos, gfx_snek_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(snek_idle);
          display.drawBitmap(Xpos, Ypos, gfx_snek_idle, 32, 32, 1);
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(snek_main);
          display.drawBitmap(Xpos, Ypos, gfx_snek_main, 32, 32, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(icon_food);
          display.drawBitmap(Xpos + 8, Ypos + 8, gfx_icon_food, 16, 16, 1);
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
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(snek_main);
          display.drawBitmap(Xpos, Ypos, gfx_snek_main, 32, 32, 1);
        }
        else //if even
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(snek_idle);
          display.drawBitmap(Xpos, Ypos, gfx_snek_idle, 32, 32, 1);
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
