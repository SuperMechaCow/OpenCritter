/*
   For fast editting and human readability, we used defined labels.
   These are just defined parameters, and contain no variables (constant or otherwsie).
*/


/*========================================================================================================================
    i2c Comms Labels
  ========================================================================================================================*/

// This device
#define i2c_addr          10
#define devicetype        IOPU_Atmega328

// The Q
#define max_requests      13 

// Device Types
#define IOPU_Atmega328    2
#define IOPU_Attiny85     3
#define GPU_Atmega328     4

// Requests
#define deviceID          10
#define wutuwant          11
#define gimmeButtons      12

// Commands
#define debugSet          20
#define hrtSend           21
#define beepSend          22
#define buzzSend          23
#define updateParam       24

// Commands (for The Q)
#define Q_baseHRT_speed   01
#define Q_breed           02
#define Q_weight          03
#define Q_Ath             04
#define Q_Int             05
#define Q_Dis             06
#define Q_hun             07
#define Q_hap             08
#define Q_bor             09
#define Q_heartbeats      10
#define Q_metabolism      11
#define Q_selMenu         12
#define Q_ocCursor        13

// Command to change parameter (request's index + 128)
#define X_baseHRT_speed   129
#define X_breed           120
#define X_weight          131
#define X_Ath             132
#define X_Int             133
#define X_Dis             134
#define X_hun             135
#define X_hap             136
#define X_bor             137
#define X_heartbeats      138
#define X_metabolism      139
#define X_selMenu         140
#define X_ocCursor        150

/*========================================================================================================================
    Game Function Labels
  ========================================================================================================================*/

//Functions
#define RESET             0

//CLOCK NAMES
#define baseCLK           0   //Base clock
#define hrtCLK            1   //Heartbeat clock
#define timeCLK           2   //Generic clock
#define butCLK            3   //Button clock
#define aniCLK            4   //Animation clock
#define beepCLK           5   //beeper clock
#define buzzCLK           6   //beeper clock

/*========================================================================================================================
    I/O Function Labels
  ========================================================================================================================*/

// BEEPER NAMES
//0 and 1 are reserved for changing beeper mute state
#define beep_UpChirp      2
#define beep_DnChirp      3
#define beep_HiLo1        4
#define beep_HiLo3        5
#define beep_PosBeep      6
#define beep_NegBeep      7
#define beep_Bip          8
#define beep_Bop          9
#define beep_Tick         10
#define beep_noise        11
//#define beep_ thee fast upchirps

// BUZZER NAMES
//0 and 1 are reserved for changing buzzer mute state
#define buzz_Alert        2
#define buzz_Long         3
#define buzz_Short        4
