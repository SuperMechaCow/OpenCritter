#include <Wire.h>
//#include <U8g2lib.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
//Include custom files
#include "A_labels.h"
#include "B_boardselect.h"
#include "C_setup.h"
#include "Z_gfx.h"

//
// All of the variable declarations are in _setup.h
//

void setup()
{
  if (mcuinputs) {
    pinMode(hrt_pin, OUTPUT);
    pinMode(Abut_pin, INPUT);
    pinMode(Bbut_pin, INPUT);
    pinMode(Cbut_pin, INPUT);
    pinMode(beeper_pin, OUTPUT);
    pinMode(rumble_pin, OUTPUT);
    IOPUattached = false;
  }
  else {
    IOPUattached = true;
  }

  /*== Start Comms =========================================================================================================*/

  delay(2000); // Wait for other devices to boot.

  //Set the pins for I2C if using esp8266
  Wire.begin(i2cSDA, i2cSCL);

  //Spin up a serial port for debugging/comms
  Serial.begin(serialbaud);

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
  if (debugMode) {
    Serial.println(F("Ready for command..."));
    Energy = 255;  //I don't want to wait for energy to build up to test-play games
    beepMute = true;  //These get annoying after awhile
  }

  metaBonus = egg_m;

  /*== Create Inventory ====================================================================================================*/

  for (int i = 0; i < inv_max_itemtypes; i++) {
    switch (i) {
      case inv_meds_slot: //If we are dealing with meds
        Inventory[inv_meds_slot][inv_owned] = inv_meds_start;       //Set owned to starting value
        Inventory[inv_meds_slot][inv_acked] = inv_meds_start;       //Set acknoledged to starting value
        Inventory[inv_meds_slot][inv_maxnumber] = inv_meds_max;     //Set max to maximum value
        break;
      case inv_soda_slot: //If we are dealing with meds
        Inventory[inv_soda_slot][inv_owned] = inv_soda_start;       //Set owned to starting value
        Inventory[inv_soda_slot][inv_acked] = inv_soda_start;       //Set acknoledged to starting value
        Inventory[inv_soda_slot][inv_maxnumber] = inv_soda_max;     //Set max to maximum value
        break;
      default:
        break;
    }
  }

  /*== Animation Setup =====================================================================================================*/

  //Get the starting variables ready for the various functions
  selMenu = mainM;            //Start the menus with the "Main Menu" play screen
  aniMode = a_idle;  //First animation to play is the egg
  aniStage = RESET;           //prime animation stage
  aniLast = RESET;            //Set the placeholder for previous animation

  beep(beep_UpChirp);         //Hello World!

  updateScreen();             //draw the first screen

  /*== WebAP Setup =========================================================================================================*/

  //  We set the default state in the firmware for this. This is actually incredibly touchy and inconsistent.
  //  If we don't explicitly shut the WiFi off, it uses 50mA more current as if it's broadcasting, even after reset.

  if (wifiEnabled) {
    WiFiMode(WIFI_AP);                  //Set WiFi mode to Access Point
    WiFi.softAP(ssid, password);        //Start a WiFi AP with this Name and Password
    IPAddress myIP = WiFi.softAPIP();   //Make it assign it's own default IP address (192.168.4.1)
    server.on("/", handleRoot);         //Run handleroot() if the URL after the IP is just "/" (Root. '192.168.4.1/')
    server.begin();                     //Start a
  }
  else {
    WiFiMode(WIFI_STA);                 //Set the mode to Station, so it's not constantly broadcasting
    WiFi.disconnect();                  //If there is any connection, stop it.
    WiFi.mode(WIFI_OFF);                //The official command to turn WiFi off, but it doesn't seem to work
    WiFi.forceSleepBegin();             //So we force the WiFi portion of the chip to sleep
    delay(100);                         //If Arduino code tries to run before the sleep is complete, it won't work at all
  }

  /*== End Setup ===========================================================================================================*/
}

void loop() {

  //Handle the web server if wifi is enabled
  if (wifiEnabled)
    server.handleClient();

  if (!deadcritter) {

    /*== Start Loop ==========================================================================================================*/

    //Calculate metabolism
    //Start with average value of health mapped to 0 to 100
    metabolism = map(getHealth(), 0, max_health, 100, 0);;
    //Add in average value of power and invert the value
    metabolism = metabolism + map(getPower(), 0, max_power, 100, 0);
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
    /*== Heartbeat Events ====================================================================================================*/

    if (sick_thresh > 255)
      sick_thresh = 255;

    /*HEARTBEATS AND CLOCK CHECKING
       The timing in this game is linked to Metabolism and Heartbeats, which are the frequency of "game ticks", respectively.
       There are several "Clocks" in the code that track when various functions should continue to the next "stage".

       Certain events happen every "X" heartbeats. Most hearbeats won't do anything, but some will "roll" or "roll the dice" on
       an event taking place. "Rolling" determines the result of something based on the critter's parameters. For example, every
       pre-defined set of heartbeats the game will roll to see if a health stat will drain. The higher the creature's power stat, the less
       likely it will drain a health stat.
    */

    CLK[baseCLK] = millis(); //Update clock to the current millisecond
    if ((CLK[baseCLK] - CLK[hrtCLK]) > (baseHRT_speed * metabolism)) //If at least one heartbeat time increment has passed since we last checked
    {
      //Add as many heartbeats to the "queue" as increments
      queueBeats = ((CLK[baseCLK] - CLK[hrtCLK]) / (baseHRT_speed * metabolism));

      for (int i = 0; i < queueBeats; i++) { //For each heartbeat that has happened since we last checked we have to "roll" for changes

        heartbeats++; //Add one heartbeat before we "roll" each loop

        //Each opencritter has three temporary health stats and three "power stats"
        //Each power stat evolves over time and effects short term change of health
        //Raising the power stat decreases the drain rate of the status
        //Raising a health stat with junk foods negatively impact power stats
        //Power stats also each effect one other part of the game
        //Every health_beat number of heartbeats the game "rolls" to decrease a health stat

        //CALCULATE STAT CHANGE
        //The game "rolls the dice" (picks a number between 0 and max_drainChance)
        //If the roll is higher than that health stat's related power stat, it reduces the health stat by 1
        //The higher the power stat, the less likely there will be a health reduction
        //Sickness lowers the power temporarily. This is calculated by how many stacks of sickness it has times the sickness penalty multiplier

        if (heartbeats % health_beat == 0) { //If the current heartbeat is a key beat for rolling for health stat drain
          if (random(0, max_drainChance) > Ath - (sick_penalty * sickCount)) { //High power stats reduce chance of health stat drain. Each stack of sickness increases chance.
            if (hun > 0)
              hun--; //hunger = athleticism
            if (Energy < max_health)
              Energy++;
            beep(beep_Tick);
          }
          if (random(0, max_drainChance) > Dis - (sick_penalty * sickCount)) {
            if (hap > 0)
              hap--; //happiness = Dis
            if (Energy < max_health)
              Energy++;
            beep(beep_Tick);
          }
          if (random(0, max_drainChance) > Int - (sick_penalty * sickCount)) {
            if (bor > 0)
              bor--; //boredom = Int
            if (Energy < max_health)
              Energy++;
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
        if (heartbeats % evolve_beat == 0 && lifestage < adult) {
          evolveHandler();
        }

        //Check for a discovery
        if (Energy == max_energy && breed != egg) {
          discovery();
        }

        if (heartbeats % EnergyC_beat == 0 && Energy != max_energy) {
          Energy++;
        }

      }

      //Update the IOPU with the heartbeat state
      sendhrtpin();

      CLK[hrtCLK] = CLK[baseCLK];              //Set last heart beat clock to current clock

    }

    /*== Update other devices =================================================================================================*/

    //theQ();

    //Comment out for NODEMCU
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
      case inventM:
        inventMenu();
        break;
      case c_clockset:
        clockset();
        break;
      //
      // Games
      case g_ballcatch:
        ballcatch();
        break;
      case g_cardflip:
        cardflip();
        break;
      case g_bitshifter:
        bitshifter();
      case g_lazerchiken:
        lazerchiken();
        break;
      default:
        break;
    }

    /*== Turn off OLED if inactive ============================================================================================*/

    // If the player hasn't touched the device since longer than the timeout number AND the device is not already sleeping
    // (we add ten to make sure the clock has had time to update since the last button press
    if (((CLK[baseCLK] + 10) - CLK[sleepCLK]) > sleepTimeout && !deviceSleep) {
      display.ssd1306_command(SSD1306_DISPLAYOFF);  //Tell the OLED to sleep
      deviceSleep = true; //Let the device know it's already sleeping, so it won't try to make it sleep again
    }
    else if ((CLK[baseCLK] - CLK[sleepCLK]) < sleepTimeout && deviceSleep) { // The player HAS touched it recently
      display.ssd1306_command(SSD1306_DISPLAYON);  //Tell the OLED to wake up
      deviceSleep = false; //Let the device know it's already awake, so it won't try to make it wake up again
    }

  }

  /*== Don't do anything if critter is dead ===================================================================================*/

  else {
    delay(1);
  }
}

