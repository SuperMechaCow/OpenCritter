#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
//#include <U8glib.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>

//Include custom files
#include "gfx.h"
#include "names.h"
#include "setup.h"

void setup()
{
  //Spin up a serial port for debugging/comms
  Serial.begin(9600);

  if (ARDUINO_ESP8266_NODEMCU) {
    //Set the pins for I2C
    Wire.begin(espSDA, espSCL);
    //Set the EEPROM size in bytes
    EEPROM.begin(32);
  }

  //start an OLED screen object
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
  //Display the buffer image
  display.display();
  // Clear the buffer
  display.clearDisplay();

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
    hunger = hunger - (1 * Ath); //hunger = athleticism
    happiness = happiness - (1 * Dis); //happiness = Dis
    boredom = boredom - (1 * Int); //boredom = Int
    //Keep stats from going below 0
    if (hunger <= 0)
      hunger = RESET;
    if (happiness <= 0)
      happiness = RESET;
    if (boredom <= 0)
      boredom = RESET;
  }

  //Hacked up temporary evolution handler
  if (heartbeats > 60 && breed < 1)
  {
    beepMode = HiLo3;
    breed = wibbur;
    aniModeSet(breed, a_idle);
  }

  //Call the function for running the beeper if not muted
  if (!beepMute)
    beep();
  //Call the function for running the buzzer
  buzz();

  //Call the right menu function depending on what the current menu variable is set to (selMenu)
  switch (selMenu)
  {
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

void getButton() //Game-wide handling of reading button input
{
  if (digitalRead(Abut_pin) != butTHEN[0]) //If the current physical state of then button is not what it was
  {
    butTHEN[0] = digitalRead(Abut_pin); //Set the "previous state" to the button state
    butNOW[0] = digitalRead(Abut_pin); //Set the current state to the button state
  }
  if (digitalRead(Bbut_pin) != butTHEN[1])
  {
    butTHEN[1] = digitalRead(Bbut_pin);
    butNOW[1] = digitalRead(Bbut_pin);
  }
  if (digitalRead(Cbut_pin) != butTHEN[2])
  {
    butTHEN[2] = digitalRead(Cbut_pin);
    butNOW[2] = digitalRead(Cbut_pin);
  }
}
