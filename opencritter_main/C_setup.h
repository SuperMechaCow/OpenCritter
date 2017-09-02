
//Start OLED
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

#define versionnum "0.05"
#define branchnum "0.00"
#define release "070717"

// i2c module handler
bool IOPUattached = false;
bool GPUattached = false;
byte IOPUaddress = 10;
int i2c_devices[] = {0};

// Critter parameters
// Stats
byte Ath = 50;
byte Int = 50;
byte Dis = 50;
// Trait
byte hun = 255;
byte hap = 255;
byte bor = 255;
// Biostat
byte breed = 0;
byte weight = 10;
byte NRG = 0;
/*========================================================================================================================*/
/*========================================================================================================================*/
//ADD THIS ENERGY SYSTEM AS A BIOSTAT! HIGHER WEIGHT AND LOWER TRAITS DRAIN ENERGY FASTER! ENERGY IS NEEDED TO DO THINGS!
//CAN DO THINGS ON ITS OWN IF ENERGY IS MAXED OUT!
/*========================================================================================================================*/
/*========================================================================================================================*/


// Bio-functions
unsigned int heartbeats = 0;
float hrtBPM = 0;               // Beats per minute. Not vital to the game. Good for the user's imagination, though.
byte metabolism = 50;           // The frequency at which heartbeats occur
byte metaBonus = 0;             // A flat modifier of the metabolism from lifestage and medicines, etc.
byte lifestage = 0;             // What stage 
int sick_thresh = 0;            // Roll for sickness on a sickness heartbeat if average stats are under this number
int sick_thresh_bonus = 0;      //
int queueBeats = 0;             // How many beats are we waiting to roll on?
byte poopCount = 0;
byte sickCount = 0;
bool Alert = false;
byte rollResult = 0;

//Menu and cursor funtions
byte selMenu = 0;
byte ocCursor = 0;

unsigned long CLK[7] = {0}; //See clock array names

byte gfxBuffer[128] = {0};

/*========================================================================================================================*/

// OpenCritter supports 8 buttons, though it has 3 by default
bool butNOW[8] = {0};  //state of to use
bool butTHEN[8] = {0}; //previous state of each button
bool butREAD[8] = {0}; //State of the button received from IOPU

/*========================================================================================================================*/

//Animation functions
byte aniMode, aniOffset, aniStage, aniLast = 0;

//Real clock functions
int dnow, hnow, mnow, snow = 0;
unsigned long clockOFFSET = 0;
bool hour12 = false;

//Beeping functions
bool beepMute = false;
byte beepMode, beepOffset, beepStage = 0; //What type of beep the speaker should be doing and at what pitch? (see //beep)))

//Buzzing functions
bool buzzMute = false;
byte buzzMode, buzzStage = 0;

//Game functions
int gameStage = 0;
int gameVal[10] = {0};
