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
#define versionnum "0.01"
#define release "0/0/00"

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
#define espSDA D6
#define espSCL D5
#endif

/* digicritter stats */
//Start stage at 0
byte breed = 0;
byte weight = 0;
float Ath = 0.50;
float Int = 0.50;
float Dis = 0.50;
float hunger = 100;
float happiness = 100;
float boredom = 100;
int heartbeats = 0;
float metabolism = 0.50;
byte clockOFFSETh, clockOFFSETm, clockOFFSETs = 0;

unsigned long CLK[7] = {0}; //See clock array names

//Beeping functions
bool beepMute = false;
byte beepMode, beepOffset, beepStage = 0; //What type of beep the speaker should be doing and at what pitch? (see beep())

//Buzzing functions
bool buzzMute = false;
byte buzzMode, buzzStage = 0;

//Game functions
int gameStage = 0;
byte gameVal[10] = {0};

//button state functions
bool butNOW[3] = {0};                     //state of the button now
bool butTHEN[3] = {0};                    //previous state of each button

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

//BASE WEIGHT
#define egg_w 5
#define wibbur_w 10
#define tribbur_w 20
