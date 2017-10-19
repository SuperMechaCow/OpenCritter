#define versionnum "a0.012"
#define branchnum "0.00"
#define release "101817"

//Setup Access Point
const char *ssid = "OpenCritter";
const char *password = "Wibbur77";
//Start the server
ESP8266WebServer server(80);

//Start OLED
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// WiFi stuff
bool wifiEnabled = false;

// i2c module handler
bool IOPUattached = false;
bool GPUattached = false;
byte IOPUaddress = 10;
int i2c_devices[] = {0};

// Critter parameters
//Misc.
String crittername = "";
// Health Stats
byte Ath = 128;                  // Athleticism. How fast Hunger drains
byte Dis = 128;                  // Discipline. How fast happiness drains
byte Int = 128;                  // Intelligence. How fast Boredom drains
// Trait
byte hun = 255;                 // Hunger
byte hap = 255;                 // Happiness
byte bor = 255;                 // Boredom
// Energy Stats
byte Energy = 0;                   // How much Energy the critter has to complete tasks
byte metabolism = 50;           // The frequency at which heartbeats occur
byte weight = 10;               // How much the critter "weighs"
/*========================================================================================================================*/
/*========================================================================================================================*/
//ADD THIS ENERGY SYSTEM AS A BIOSTAT! HIGHER WEIGHT AND LOWER TRAITS DRAIN ENERGY FASTER! ENERGY IS NEEDED TO DO THINGS!
//CAN DO THINGS ON ITS OWN IF ENERGY IS MAXED OUT!
/*========================================================================================================================*/
/*========================================================================================================================*/


// Bio-functions
bool deadcritter = false;
unsigned int heartbeats = 0;    // How many heartbeats have been... beaten?
float hrtBPM = 0;               // Beats per minute. Not vital to the game. Good for the user's imagination, though.
byte metaBonus = 0;             // A flat modifier of the metabolism from lifestage and medicines, etc.
byte lifestage = 0;             // What stage
int sick_thresh = 0;            // Roll for sickness on a sickness heartbeat if average health stats are under this number
int sick_thresh_bonus = 0;      // An additive modifier to the sick threshold
int queueBeats = 0;             // How many beats are we waiting to roll on?
byte poopCount = 0;             // How many poops are on the floor
byte sickCount = 0;             // What stage of sickness the critter is at
int sickRolls = 0;              // How many times was the critter left vulnerable to sickness?
bool Alert = false;             // Does the critter want/need attention?
byte rollResult = 0;            //
byte breed = 0;                 // What breed in the breed index (see _labels.h) the critter is

//Inventory Items
byte Inventory[inv_max_itemtypes][3] = {{0}}; //A table of items with three properties. "total owned", "total acknowledged", and "max limit".

//Menu and cursor funtions
byte selMenu = 0;               // The currently selected menu
byte ocCursor = 0;              // The current position of the cursor

unsigned long CLK[8] = {0};     // The various clocks used in the game. See _labels.h for details

byte gfxBuffer[128] = {0};      // Used to store graphics for rendering on screen

/*========================================================================================================================*/

// OpenCritter supports 8 buttons, though it has 3 by default
bool butREAD[8] = {0};
bool butNOW[8] = {0};           // state of button to use
bool butTHEN[8] = {0};          // previous state of each button
//bool butREAD[8] = {0};          // State of the button received from IOPU
byte buttbyte = 0;

bool deviceSleep = false;

/*========================================================================================================================*/

//Animation functions
byte aniMode = 0;               // Which animation is currently playing?
byte aniOffset = 0;             // Offset the frames of the animation by this much
byte aniStage = 0;              // Which frame of the animation is playing?
byte aniLast = 0;               // What was the LAST frame to be played?

//Real clock functions
int dnow, hnow, mnow, snow = 0; // Days, Hours, Minutes, Seconds right now
unsigned long clockOFFSET = 0;  // Offset the real clock by the game clokc by this much
bool hour12 = false;            // 'True' uses AM/PM system, 'False' uses 24 hour system

//Beeping functions
bool beepMute = false;          // Is the beeper muted?
byte beepMode = 0;              // Which beep are we playing?
byte beepOffset = 0;            // The pitch offset of the beep
byte beepStage = 0;             // What "frame" of the beeping are we currently on?

//Buzzing functions
bool rumbleMute = false;          // Is the rumble muted?
byte rumbleMode = 0;              // What type of rumble is playing?
byte rumbleStage = 0;             // What "frame" of the rumble are we currently on?

//Game functions
int gameStage = 0;              // What stage of each game we are on currently
int gameVal[10] = {0};          // Sets aside 10 integers to be re-used per game. See _labels.h for details
