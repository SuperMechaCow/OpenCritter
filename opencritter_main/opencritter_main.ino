#include <Wire.h>
//#include <U8g2lib.h>
#include <Adafruit_SSD1306.h>

//Include custom files
#include "A_labels.h"
#include "B_boardselect.h"
#include "C_setup.h"
#include "Z_gfx.h"


void setup()
{
  /*== Start Comms =========================================================================================================*/

  delay(2000); // Wait for other devices to boot.

  //Spin up a serial port for debugging/comms
  Serial.begin(serialbaud);

  //Set the pins for I2C
  Wire.begin(i2cSDA, i2cSCL);

  //Find all of the i2c devices on the bus and start registering them
  //i2c_scanbus();

  /*== Start Graphics ======================================================================================================*/

  if (!GPUattached) { //If there's no GPU, do your own graphics
    //start an OLED screen object
    display.begin(SSD1306_SWITCHCAPVCC, OLED_device);
    //Display the buffer image
    display.display();
    // Clear the buffer
    display.clearDisplay();
  }

  /*== Misc. Setup =========================================================================================================*/

  //Reset the seed
  randomSeed(analogRead(0));

  //If the debugging is on, let the user know over serial
  if (debugMode)
    Serial.println(F("Ready for command..."));


  metaBonus = egg_m;

  // If we are debugging, skip the egg
  //  if (debugMode) {
  //    breed = wibbur;
  //    metaBonus = baby_m;
  //  }

  /*== Animation Setup =====================================================================================================*/

  //Get the starting variables ready for the various functions
  selMenu = mainM; //Start the menus with the "Main Menu" play screen
  aniModeSet(breed, a_idle); //First animation to play is the egg
  aniStage = RESET; //primer animation stage
  aniLast = RESET;  //Set the placeholder for previous animation

  //Call the function for running the beeper if not muted
  beep(beep_UpChirp);

  updateScreen(); //draw the first screen

  /*== End Setup ===========================================================================================================*/

}

void loop() {

  /*== Start Loop ==========================================================================================================*/

  //Calculate metabolism
  //Start with average value of stats mapped to 0 to 100
  metabolism = (map(hun, 0, 255, 100, 0) + map(hap, 0, 255, 100, 0) + map(bor, 0, 255, 100, 0)) / 3;
  //Add in average value of traits and invert the value
  metabolism = metabolism + map(((Ath + Dis + Int) / 3), 0, 100, 100, 0);
  //Add in metabolism bonus from breed
  metabolism = metabolism + metaBonus;
  //Take the average of the prior three values
  metabolism = metabolism / 3;
  //Modulate by how far away from a healthy weight the critter is
  metabolism = metabolism + abs(weight - nominal_w);
  //Make sure metabolism is at least 1 or else we will be dividing by zero later on and ripping holes in the universe
  if (metabolism <= 0)
    metabolism = 1;

  //Calculate the sickness threshold
  sick_thresh = (sick_multi * (poopCount + sickCount + lifestage)) + sick_base;
  if (sick_thresh > 255)
    sick_thresh = 255;

  /*== Heartbeat Events ====================================================================================================*/

  /*HEARTBEATS AND CLOCK CHECKING
     The timing in this game is linked to Metabolism and Heartbeats, which are the frequency of "game ticks", respectively.
     There are several "Clocks" in the code that track when various functions should continue to the next "stage".

     Certain events happen every "X" heartbeats. Most hearbeats won't do anything, but some will "roll" or "roll the dice" on
     an event taking place. "Rolling" determines the result of something based on the critter's parameters. For example, every
     pre-defined set of heartbeats the game will roll to see if a stat will drain. The higher the creature's trait, the less
     likely it will drain a stat.
  */

  CLK[baseCLK] = millis(); //Update clock to the current millisecond
  if ((CLK[baseCLK] - CLK[hrtCLK]) > (baseHRT_speed * metabolism)) //If at least one heartbeat time increment has passed since we last checked
  {
    //Add as many heartbeats to the "queue" as increments
    queueBeats = ((CLK[baseCLK] - CLK[hrtCLK]) / (baseHRT_speed * metabolism));

    for (int i = 0; i < queueBeats; i++) { //For each heartbeat that has happened since we last checked we have to "roll" for changes

      heartbeats++; //Add one heartbeat before we "roll" each loop

      //Each opencritter has three temporary stats and three "traits"
      //Each traits evolves over time and effects short term change of stats
      //Raising the trait decreases the drain rate of the status
      //Raising a stat with junk foods negatively impact traits
      //Traits also each effect one other part of the game
      //Every stat_beat number of heartbeats the game "rolls" to decrease a stat

      //CALCULATE STAT CHANGE
      //The game "rolls the dice" (picks a number between 0 and max_drainChance)
      //If the roll is higher than that stat's related trait, it reduces the stat by 1
      //The higher the trait, the less likely there will be a stat reduction
      //Sickness lowers the trait temporarily. This is calculated by how many stacks of sickness it has times the sickness penalty multiplier

      if (heartbeats % stat_beat == 0) { //If the current heartbeat is a key beat for rolling for stat drain
        if (random(0, max_drainChance) > Ath - (sick_penalty * sickCount)) { //High traits reduce chance of stat drain. Each stack of sickness increases chance.
          if (hun > 0)
            hun--; //hunger = athleticism
          beep(beep_Tick);
        }
        if (random(0, max_drainChance) > Dis - (sick_penalty * sickCount)) {
          if (hap > 0)
            hap--; //happiness = Dis
          beep(beep_Tick);
        }
        if (random(0, max_drainChance) > Int - (sick_penalty * sickCount)) {
          if (bor > 0)
            bor--; //boredom = Int
          beep(beep_Tick);
        }
      }

      //See if it will cry wolf
      if (heartbeats % cry_beat == 0) { //If this is a key
        cryHandler();
      }

      //Check for sickness
      if (heartbeats % sick_beat == 0) {
        sickHandler();
      }

      //Check for poop
      if (heartbeats % poop_beat == 0) {
        poopHandler();
      }

      //Check to see if it has hatched
      if (heartbeats % hatch_beat == 0 && breed == 0) {
        evolveHandler();
      }

      //Check for evolution
      if (heartbeats % evolve_beat == 0) {
        evolveHandler();
      }

    }

    //Update the IOPU with the heartbeat state
    sendhrtpin();
    //digitalWrite(hrt_pin, (heartbeats % 2)); //HIGH (1) if it's an odd beat, LOW (2) if it's an even beat.

    CLK[hrtCLK] = CLK[baseCLK];              //Set last heart beat clock to current clock

  }

  /*== Update other devices =================================================================================================*/

  //theQ();

  updateIOPU();

  getButtons();

  debug();

  /*== Call the current menu ================================================================================================*/

  //Call the right menu function depending on what the current menu variable is set to (selMenu)
  switch (selMenu)
  {
    //
    // Menus
    case mainM:
      mainMenu();
      break;
    case clockM:
      clockMenu();
    case statsM:
      statsMenu();
      break;
    case foodM:
      foodMenu();
      break;
    case confM:
      confMenu();
      break;
    case playM:
      playMenu();
      break;
    case c_clockset:
      clockset();
      break;
    //
    // Games
    case g_cardflip:
      cardflip();
      break;
    case g_bitshifter:
      bitshifter();
      break;
    default:
      break;
  }
}

