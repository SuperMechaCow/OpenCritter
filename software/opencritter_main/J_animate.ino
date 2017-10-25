/*
   Handles all of the critter animations in the game

   Note that this only prepares the animation for the screen.
   It does not update the screen itself.
   See updateScreen() for screen drawing.

*/

void animate(byte Xpos, byte Ypos, byte ani_breed) {
  //display.fillRect(playPen_then, 16, 32, 32, 0); //Erase where the critter was standing
  switch (aniMode) {
    case a_idle:
      if (aniStage == 0)
      {
        CLK[aniCLK] = CLK[baseCLK];
        aniStage = 1;
      }
      else
      {
        aniStage = 1 + ((CLK[baseCLK] - CLK[aniCLK]) / ((baseHRT_speed * 1) * metabolism));
        if (aniStage % 2) //If odd
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, getFrame(frame_main, breed), crit_dimensions, crit_dimensions, 1);
        }
        else
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          display.drawBitmap(Xpos, Ypos, getFrame(frame_idle, breed), crit_dimensions, crit_dimensions, 1);
        }
        if (aniLast != aniStage) //The last stage is not the same odd or even as the current stage
        {
          aniLast = aniStage; //Match the stages
          updateScreen();     //Update the screen
        }
      }
      break;
    case a_eat:
      if (aniStage == 0)
      {
        CLK[aniCLK] = CLK[baseCLK];
        aniStage = 1;
      }
      //only do a certain number of times
      else if (aniStage > 6)
      {
        aniMode = a_idle;
        aniStage = RESET;
        aniLast = RESET;
      }
      else
      {
        aniStage = 1 + ((CLK[baseCLK] - CLK[aniCLK]) / ((baseHRT_speed * 0.5) * metabolism));
        if (aniStage % 2 == 1)
        {
          display.fillRect(48, Ypos, 32, 32, 0);
          display.drawBitmap(48, Ypos, getFrame(frame_main, breed), crit_dimensions, crit_dimensions, 1);
        }
        else
        {
          display.fillRect(48, Ypos, 32, 32, 0);
          display.drawBitmap(48 + 8, Ypos + 8, getIcon(it_foods + foodType), icon_dimensions, icon_dimensions, 1);
        }
        if (aniLast != (aniStage % 2))
        {
          aniLast = aniStage % 2;
          updateScreen();
        }
      }
      break;
    case a_play:
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
          display.drawBitmap(Xpos, Ypos, getFrame(frame_main, ani_breed), crit_dimensions, crit_dimensions, 1);
        }
        else //if even
        {
          display.fillRect(Xpos, Ypos, 32, 32, 0);
          //          getGFX(wibbur_idle);
          display.drawBitmap(Xpos, Ypos, getFrame(frame_idle, ani_breed), crit_dimensions, crit_dimensions, 1);
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

/*========================================================================================================================*/

const unsigned char* getFrame(byte framename, byte frame_breed) {
  switch (framename) {
    case frame_main:
      switch (frame_breed) {
        case egg:
          return gfx_egg_main;
          break;
        case wibbur:
          return gfx_wibbur_main;
          break;
        case xorby:
          return gfx_xorby_main;
          break;
        case goob:
          return gfx_goob_main;
          break;
        case flip:
          return gfx_flip_main;
          break;
        case lugerd:
          return gfx_lugerd_main;
          break;
        case moops:
          return gfx_moops_main;
          break;
        case shansy:
          return gfx_shansy_main;
          break;
        case snek:
          return gfx_snek_main;
          break;
        case hwooty:
          return gfx_hwooty_main;
          break;
        case culu:
          return gfx_culu_main;
          break;
        case shent:
          return gfx_shent_main;
          break;
        case slorp:
          return gfx_slorp_main;
          break;
        case zeta:
          return gfx_zeta_main;
          break;
        case butters:
          return gfx_butters_main;
          break;
        case tribbur:
          return gfx_tribbur_main;
          break;
        case corine:
          return gfx_corine_main;
          break;
        case pyre:
          return gfx_pyre_main;
          break;
        case rajur:
          return gfx_rajur_main;
          break;
        case crosh:
          return gfx_crosh_main;
          break;
        default:
          return gfx_egg_main;
          break;
      }
      break;
    case frame_idle:
      switch (breed) {
        case egg:
          return gfx_egg_idle;
          break;
        case wibbur:
          return gfx_wibbur_idle;
          break;
        case xorby:
          return gfx_xorby_idle;
          break;
        case goob:
          return gfx_goob_idle;
          break;
        case flip:
          return gfx_flip_idle;
          break;
        case lugerd:
          return gfx_lugerd_idle;
          break;
        case moops:
          return gfx_moops_idle;
          break;
        case shansy:
          return gfx_shansy_idle;
          break;
        case snek:
          return gfx_snek_idle;
          break;
        case hwooty:
          return gfx_hwooty_idle;
          break;
        case culu:
          return gfx_culu_idle;
          break;
        case shent:
          return gfx_shent_idle;
          break;
        case slorp:
          return gfx_slorp_idle;
          break;
        case zeta:
          return gfx_zeta_idle;
          break;
        case butters:
          return gfx_butters_idle;
          break;
        case tribbur:
          return gfx_tribbur_idle;
          break;
        case corine:
          return gfx_corine_idle;
          break;
        case pyre:
          return gfx_pyre_idle;
          break;
        case rajur:
          return gfx_rajur_idle;
          break;
        case crosh:
          return gfx_crosh_idle;
          break;
        default:
          return gfx_egg_idle;
          break;
      }
      break;
  }
}

/*========================================================================================================================*/

const unsigned char* getIcon(byte iconname) {
  switch (iconname) {
    case i_meds:
      return gfx_icon_meds;
      break;
    case i_soda:
      return gfx_icon_soda;
      break;
    case i_star:
      return gfx_icon_star;
      break;
    case i_biok:
      return gfx_icon_biok;
      break;
    case i_pedia:
      return gfx_icon_book;
      break;
    case i_labk:
      return gfx_icon_labk;
      break;
    case i_food:
      return gfx_icon_food;
      break;
    case i_fats:
      return gfx_icon_fats;
      break;
    case i_carb:
      return gfx_icon_carb;
      break;
    default:
      return gfx_icon_unon;
      break;
  }
}
