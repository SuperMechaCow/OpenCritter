//#include <OpenCritterIO.h>

#define debugMode true

/*
   For fast editting and human readability, we used defined labels.
   These are just defined parameters, and contain no variables (constant or otherwsie).
*/

/*========================================================================================================================
    i2c Comms Labels
  ========================================================================================================================*/

// OLED ADDRESS
#define OLED_device           60

// The Q
#define max_requests          13

// Requests
#define deviceID              10
#define wutuwant              11
#define gimmeButtons          12

// Command
#define debugSet              20
#define hrtSend               21
#define beepSend              22
#define rumbleSend            23
#define updateParam           24

// Commands (for The Q. Up to 128 types of requests)
#define Q_baseHRT_speed       1
#define Q_breed               2
#define Q_weight              3
#define Q_Ath                 4
#define Q_Int                 5
#define Q_Dis                 6
#define Q_hun                 7
#define Q_hap                 8
#define Q_bor                 9
#define Q_heartbeats          10
#define Q_metabolism          11
#define Q_selMenu             12
#define Q_ocCursor            13

// Command to change parameter (request's index + 128)
#define X_baseHRT_speed       129
#define X_breed               120
#define X_weight              131
#define X_Ath                 132
#define X_Int                 133
#define X_Dis                 134
#define X_hun                 135
#define X_hap                 136
#define X_bor                 137
#define X_heartbeats          138
#define X_metabolism          139
#define X_selMenu             140
#define X_ocCursor            150

/*========================================================================================================================
    Game Function Labels
  ========================================================================================================================*/

//Functions
#define RESET                 0

//CLOCK NAMES
#define baseCLK               0   //Base clock
#define hrtCLK                1   //Heartbeat clock
#define timeCLK               2   //Generic clock
#define butCLK                3   //Button clock
#define aniCLK                4   //Animation clock
#define beepCLK               5   //beeper clock
#define rumbleCLK             6   //beeper clock
#define sleepCLK              7   //Time since last user interaction

/*========================================================================================================================
    I/O Function Labels
  ========================================================================================================================*/

// BEEPER NAMES
//0 and 1 are reserved for changing beeper mute state
#define beep_UpChirp          2
#define beep_DnChirp          3
#define beep_HiLo1            4
#define beep_HiLo3            5
#define beep_PosBeep          6
#define beep_NegBeep          7
#define beep_Bip              8
#define beep_Bop              9
#define beep_Tick             10

// BUZZER NAMES
//0 and 1 are reserved for changing rumble mute state
#define rumble_Alert          2
#define rumble_Long           3
#define rumble_Short          4

// Other hardware stuff I haven't sorted yet
#define sleepTimeout          120000

/*        Game Properties       *\
   These change certain constants
   throughout the game. Changing
   these will impact gameplay.
  \*                              */

//MASTER PARAMETERS
#define baseHRT_speed         20          //Standard is 20, but this can be tweakedfor debugging purposes
#define ref_int               1000        //Standard time between refresh rates
#define max_energy            255         //The highest the energy bar can go
#define max_health            255         //The highest a health stat can go
#define max_power             255         //The highest a power stat can go
#define max_metabolism        100         //The slowest the metabolism can be
#define sick_base             25          //The lowest the sick threshold can be
#define sick_multi            20          //Multiplier used to calculate chance of sickness
#define sick_penalty          10          //How much the power stat is "lowered" by when calculating health stat drain
#define foodbonus             25          //How much does food increase the health stat?
#define gamebonus             10          //How much do games increase a health stat?
#define EnergyCost            10          //How much energy does a game use?

//Random Number Maximums
#define max_sickChance        255
#define max_poopChance        20
#define max_drainChance       256

//Heartbeat keyframes
#if debugMode == true
#define health_beat           10          //Roll to drain health every X heartbeats
#define sick_beat             25          //Roll for sickness every X heartbeats
#define poop_beat             25          //Roll for poop every X beats
#define cry_beat              25          //Roll to cry for attention every X heartbeats
#define hatch_beat            50          //How long it takes to hatch the egg
#define evolve_beat           100         //How many beats it takes to evolve
#define EnergyC_beat          1           //How many beats before charging Energy
#else
#define health_beat           20          //Roll to drain health every X heartbeats
#define sick_beat             100         //Roll for sickness every X heartbeats
#define poop_beat             100         //Roll for poop every X beats
#define cry_beat              100         //Roll to cry for attention every X heartbeats
#define hatch_beat            1000        //How long it takes to hatch the egg
#define evolve_beat           10000       //How many beats it takes to evolve
#define EnergyC_beat          10           //How many beats before charging Energy
#endif

//BASE WEIGHT
#define nominal_w             10
#define egg_w                 5
#define baby_w                10
#define teen_w                15
#define adult_w               20
#define senior_w              25
#define ancient_w             30

//BASE METABOLISM
#define egg_m                 5
#define baby_m                10
#define teen_m                20
#define adult_m               40
#define senior_m              50
#define ancient_m             70

//MENU NAMES
//(g_ games, c_ config)
#define mainM                 1
#define clockM                2
#define statsM                3
#define foodM                 4
#define gameM                 5
#define medsM                 6
#define confM                 7
#define playM                 8
#define inventM               9
#define g_ballcatch           10
#define g_lazerchiken        11
#define g_cardflip            12
#define g_bitshifter          13
#define c_clockset            14

//INVENTORY PARAMETERS
#define inv_max_itemtypes         2    //How many different types of items are there in the game? Can be up to 16
#define inv_owned                 0     //Table position for owned of this item type
#define inv_acked                 1     //Table position for acknowledged amount of this item type
#define inv_maxnumber             2     //Table position for max number of this item allowed to be owned
#define inv_meds_slot             0     //What slot of the inventory are the meds in?
#define inv_meds_start            0     //How many meds does the player start with?
#define inv_meds_max              99    //Maximum number of meds the player can have
#define inv_soda_slot             1     //What slot of the inventory are the meds in?
#define inv_soda_start            3     //How many meds does the player start with?
#define inv_soda_max              99    //Maximum number of meds the player can have

//ANIMATION TYPES
#define a_idle                1
#define a_eat                 2
#define a_play                3

//FRAME TYPES
#define frame_idle            0
#define frame_main            1

//BREED NAMES
#define egg                   0
#define wibbur                1
#define xorby                 2
#define goob                  3
#define flip                  4
#define lugerd                5
#define moops                 6
#define shansy                7
#define tribbur               8
#define snek                  9
#define hwooty                10

//LIFESTAGE NAMES
#define egged                 0
#define baby                  1
#define teen                  2
#define adult                 3
#define senior                4
#define ancient               5

//ballcatch gameVals
#define gbc_balls             0     //How many balls are in play?
#define gbc_position          1     //Position of the "paddle"
#define gbc_speed             2     //speed of the paddle
#define gbc_1X                3     //X position of ball 1
#define gbc_1Y                4     //Y position of ball 1
#define gbc_ballframe         5     //Which animation frame is the ball on?
#define gbc_score             9     //Score of the game. Also affects game speed
//ballcatch misc values
#define gbc_maxspeed          10    //The fastest the paddle can go
#define gbc_incspeed          2     //How fast the speed charges
#define gbc_decspeed          1     //How fast the speed drains per tick

//lazerchiken gameVals
#define lcc_balls             0     //How many balls are in play?
#define lcc_position          1     //Position of the "paddle"
#define lcc_speed             2     //speed of the paddle
#define lcc_1X                3     //X position of ball 1
#define lcc_1Y                4     //Y position of ball 1
#define lcc_2X                5     //X position of ball 2
#define lcc_2Y                6     //Y position of ball 2
#define lcc_lazerX            7     //X position of ball 3
#define lcc_lazerY            8     //Y position of ball 3
#define lcc_score             9     //Score of the game. Also affects game speed
//ballcatch misc values
#define lcc_maxspeed          10    //The fastest the paddle can go
#define lcc_incspeed          2     //How fast the speed charges
#define lcc_decspeed          1     //How fast the speed drains per tick
#define lcc_lazersize         8     //How long is the lazer?

//card Flip gameVals
#define gcf_nextcard          0
#define gcf_thiscard          1
#define gcf_point             2
#define gcf_score             3
#define gcf_round             4

//bitshifter gameVals
#define gbs_setup             0
#define gbs_buttons           1
#define gbs_score             2
#define gbs_gameover          3
#define gbs_point             8
#define gbs_goalbyte          9
//do not use 0-7

/*        Graphics Index        *\
   These indicate where the game
   has to look in EEPROM for gfx
  \*                              */

#define numberoficons         9     //Number of icons in the device
#define numberofcrits         4     //Number of critters in the device
#define icon_size             32    //Number of bytes in an icon
#define crit_size             128
#define icon_dimensions       16    //How wide/high is the icon bitmap?
#define crit_dimensions       32    //How wide/high is the critter bitmap?

//ANIMATION NAMES
//#define ani_egg_idle          1
//#define ani_wibbur_idle       2
//#define ani_wibbur_eat        3
//#define ani_wibbur_play       4
//#define ani_xorby_idle        5
//#define ani_xorby_eat         6
//#define ani_xorby_play        7
//#define ani_goob_idle         8
//#define ani_goob_eat          9
//#define ani_goob_play         10
//#define ani_flip_idle         11
//#define ani_flip_eat          12
//#define ani_flip_play         13
//#define ani_lugerd_idle       14
//#define ani_lugerd_eat        15
//#define ani_lugerd_play       16
//#define ani_moops_idle        17
//#define ani_moops_eat         18
//#define ani_moops_play        19
//#define ani_shansy_idle       20
//#define ani_shansy_eat        21
//#define ani_shansy_play       22
//#define ani_tribbur_idle      23
//#define ani_tribbur_play      24
//#define ani_tribbur_eat       25
//#define ani_snek_idle         26
//#define ani_snek_eat          27
//#define ani_snek_play         28
//#define ani_hwooty_idle       29
//#define ani_hwooty_eat        30
//#define ani_hwooty_play       31

//FRAME NAMES
//#define icon_food             1
//#define icon_clok             2
//#define icon_stat             3
//#define icon_game             4
//#define icon_meds             5
//#define icon_conf             6
//#define icon_sick             7
//#define icon_poop             8
//#define icon_unon             9
//#define egg_idle              10
//#define egg_main              11
//#define wibbur_idle           12
//#define wibbur_main           13
//#define wibbur_play           14
//#define xorby_idle            15
//#define xorby_main            16
//#define xorby_play            17
//#define goob_idle             18
//#define goob_main             19
//#define goob_play             20
//#define flip_idle             21
//#define flip_main             22
//#define flip_play             23
//#define lugerd_idle           24
//#define lugerd_main           25
//#define lugerd_play           26
//#define moops_idle            27
//#define moops_main            28
//#define moops_play            29
//#define shansy_idle           30
//#define shansy_main           31
//#define shansy_play           32
//#define snek_idle             33
//#define snek_main             34
//#define snek_play             35
//#define hwooty_idle           36
//#define hwooty_main           37
//#define hwooty_play           38
