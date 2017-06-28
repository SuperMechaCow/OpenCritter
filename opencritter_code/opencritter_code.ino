#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
//#include <U8glib.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>

//Include custom files
#include "A_setup.h"
#include "B_names.h"
#include "Z_gfx.h"

void setup()
{
  //Spin up a serial port for debugging/comms
  Serial.begin(9600);

  /*
    if (ARDUINO_ESP8266_NODEMCU) {
      //Set the pins for I2C
      Wire.begin(i2cSDA, i2cSCL);
      //Set the EEPROM size in bytes
      EEPROM.begin(32);
    }
  */

  //start an OLED screen object
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
  //Display the buffer image
  display.display();
  // Clear the buffer
  display.clearDisplay();

  //Reset the seed
  randomSeed(analogRead(0));

  //Set pin modes for the input tactile switches
  pinMode(Abut_pin, INPUT);
  pinMode(Bbut_pin, INPUT);
  pinMode(Cbut_pin, INPUT);

  //Set the heartbeat, speaker, and rumble motor to outputs
  pinMode(hrt_pin, OUTPUT);
  pinMode(beeper_pin, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);

  //If the debugging is on, let the user know over serial
  if (debugMode)
    Serial.println(F("Ready for command..."));

  // If we are debugging, skip the egg
  if (debug)
    breed = 1;

  //Get the starting variables ready for the various functions
  selMenu = mainM; //Start the menus with the "Main Menu" play screen
  aniModeSet(breed, a_idle); //First animation to play is the egg
  aniStage = RESET; //primer animation stage
  aniLast = RESET;  //Set the placeholder for previous animation

  beepMode = UpChirp;

  updateScreen(); //draw the first screen
}

void loop()
{
  //If debug mode is on, enable the debugging menu
  if (debugMode)
    debug();

  //HEARTBEATS: Each opencritter gets a set amount of heartbeats. Metabolism effects how fast it uses those beats
  CLK[baseCLK] = millis(); //Update clock to the current millisecond
  //If the current clock is bigger than the heartbeat clock by the heartbeat's speed (speed * metabolism)
  if ((CLK[baseCLK] - CLK[hrtCLK]) > (baseHRT_speed * metabolism))
  {
    //
    heartbeats++;                            //Add a heartbeat to the counter
    digitalWrite(hrt_pin, (heartbeats % 2)); //HIGH (1) if it's an odd beat, LOW (2) if it's an even beat.
    CLK[hrtCLK] = CLK[baseCLK];              //Set last heart beat clock to current clock

    //Each opencritter has three temporary stats and three "traits"
    //Each traits evolves over time and effects short term change of stats
    //Raising the trait decreases the drain rate of the status
    //Raising a stat with junk foods should negatively impact the trait
    //Traits also each effect one other part of the game
    hunger = hunger - (100 - Ath); //hunger = athleticism
    happiness = happiness - (100 - Dis); //happiness = Dis
    boredom = boredom - (100 - Int); //boredom = Int
    //Keep stats from going below 0
    if (hunger <= 0)
      hunger = RESET;
    if (happiness <= 0)
      happiness = RESET;
    if (boredom <= 0)
      boredom = RESET;
  }

  //Check for evolution change
  evolveHandler();

  //Call the function for running the beeper if not muted
  if (!beepMute)
    beep();

  //Call the function for running the buzzer
  if (!buzzMute)
    buzz();

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
  /*
    This is where we should be putting "plugins"
    The plugin should just be an ino file with a single function
    The function gets called here
    This should be able to overwrite menus
  */
}
