/*
 * This is the setup that normally goes before setup()
 * Typical variable declarations, hardware definitions
 */

//Start OLED
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

#define debugMode true
#define versionnum "0.04"
#define release "06/29/17"

//PIN ASSIGNMENT Arduino
#ifdef __AVR_ATmega328P__
#define hrt_pin 10
#define Abut_pin 9
#define Bbut_pin 8
#define Cbut_pin 7
#define buzzer_pin 5
#define beeper_pin 3
#define GPIO_pin 6
#define Tx_pin 4
#define Rx_pin 2
#include <EEPROM.h>
#endif

//PIN ASSIGNMENT ESP8266
#ifdef ARDUINO_ESP8266_NODEMCU
#define hrt_pin D0
#define Abut_pin D3
#define Bbut_pin D2
#define Cbut_pin D1
#define buzzer_pin D8
#define beeper_pin D4
#define GPIO_pin D7
//ESP8266 I2C pin assignment
#define i2cSDA D6
#define i2cSCL D5
#include "Z_gfx.h"
#endif

/* digicritter stats */
//Start stage at 0
byte breed = 0;
byte weight = 10;
byte Ath = 50;
byte Int = 50;
byte Dis = 50;
byte hunger = 255;
byte happiness = 255;
byte boredom = 255;
unsigned int heartbeats = 0;
float metabolism = 0.50;
byte clockOFFSETh, clockOFFSETm, clockOFFSETs = 0;

byte gfxBuffer[128] = {0};

unsigned long CLK[7] = {0}; //See clock array names

//Beeping functions
bool beepMute = false;
byte beepMode, beepOffset, beepStage = 0; //What type of beep the speaker should be doing and at what pitch? (see beep())

//Buzzing functions
bool buzzMute = false;
byte buzzMode, buzzStage = 0;

//Game functions
int gameStage = 0;
int gameVal[10] = {0};

//button state functions
bool butNOW[3] = {0};  //state of the button now
bool butTHEN[3] = {0}; //previous state of each button

//Menu and cursor funtions
byte selMenu = 0;
byte ocCursor = 0;

//Animation functions
byte aniMode, aniOffset, aniStage, aniLast = 0;

//Real clock functions
int dnow, hnow, mnow, snow = 0;
byte hoffset, moffset, soffset = 0;

/*        Game Properties       *\
 * These change certain constants
 * throughout the game. Changing
 * these will impact gameplay.
\*                              */

//MASTER PARAMETERS
#define baseHRT_speed 2000
#define ref_int 1000 //Standard time between refresh rates
#define max_stats 255
#define max_traits 100
#define stat_beat 10 //Roll to drain stats every X heartbeats
#define sick_beat 100 //Roll for sickness every X heartbeats
#define cry_beat 100  //Roll to cry for attention every X heartbeats
#define foodbonus 25

//BASE WEIGHT
#define egg_w 5
#define wibbur_w 10
#define tribbur_w 20
