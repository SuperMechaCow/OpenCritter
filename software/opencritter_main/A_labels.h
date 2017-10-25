//#include <OpenCritterIO.h>

#define debugMode false

/*
   For fast editting and human readability, we used defined labels.
   These are just defined parameters, and contain no variables (constant or otherwsie).
*/

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
#define beep_noise            11

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
#define gamebonus_health      10          //How much do games increase a health stat?
#define gamebonus_power       1           //How much do games increase a power stat?
#define EnergyCost            10          //How much energy does a game use?

//Random Number Maximums
#define max_sickChance        255
#define max_poopChance        20
#define max_drainChance       300

//Heartbeat keyframes
#if debugMode == true
#define health_beat           20          //Roll to drain health every X heartbeats
#define sick_beat             100         //Roll for sickness every X heartbeats
#define poop_beat             100         //Roll for poop every X beats
#define cry_beat              100         //Roll to cry for attention every X heartbeats
#define hatch_beat            50          //How long it takes to hatch the egg
#define evolve_beat           10000       //How many beats it takes to evolve
#define energy_beat           1          //How many beats before charging Energy
#else
#define health_beat           20          //Roll to drain health every X heartbeats
#define sick_beat             100         //Roll for sickness every X heartbeats
#define poop_beat             100         //Roll for poop every X beats
#define cry_beat              100         //Roll to cry for attention every X heartbeats
#define hatch_beat            1000        //How long it takes to hatch the egg
#define evolve_beat           10000       //How many beats it takes to evolve
#define energy_beat           10          //How many beats before charging Energy
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

//SYSTEM SHOCK PENALTIES
#define shockHealth           0.5
#define shockPower            0.8

//MENU NAMES
//(g_ games, c_ config)
#define m_main                1
#define m_clock               2
#define m_stats               3
#define m_food                4
#define m_play                5
#define m_conf                7
#define m_clockset            9
#define m_invent              10
#define m_detail              11
#define m_pedia               12
#define g_ballcatch           13
#define g_cardflip            14
#define g_bitshifter          15
#define g_lazerjet            16


//INVENTORY PARAMETERS
#define inv_max_itemtypes     6     //How many different types of items are there in the game? Can be up to 16
#define inv_owned             0     //Table position for owned of this item type
#define inv_acked             1     //Table position for acknowledged amount of this item type
#define inv_maxnumber         2     //Table position for max number of this item allowed to be owned
#define inv_meds_slot         0     //What slot of the inventory is the item in?
#define inv_soda_slot         1
#define inv_star_slot         2
#define inv_biok_slot         3
#define inv_pedia_slot        4
#define inv_labk_slot         5
#define inv_meds_start        0     //How many of the item does the player start with?
#define inv_soda_start        0
#define inv_star_start        0
#define inv_biok_start        0
#define inv_pedia_start       0
#define inv_labk_start        0
#define inv_meds_max          99    //Maximum number of meds the player can have
#define inv_soda_max          99
#define inv_star_max          3
#define inv_biok_max          1
#define inv_pedia_max         1
#define inv_labk_max          1

#define sodaBonusBeats       1000
#define sodaBonusMulti       0.7

//ANIMATION TYPES
#define a_idle                1
#define a_eat                 2
#define a_play                3

//FRAME TYPES
#define frame_idle            0
#define frame_main            1

//ICON NAMES
#define i_meds                0
#define i_soda                1
#define i_star                2
#define i_biok                3
#define i_pedia               4
#define i_labk                5
#define i_food                16
#define i_fats                17
#define i_carb                18

//ICON TYPES
#define it_items              0
#define it_foods              16
#define it_menus              19

//FOOD TYPES
#define food_prot             0
#define food_fats             1
#define food_carb             2

//PLAYPEN PARAMETERS
#define pp_min                24    //The minimum area of the playpen
#define pp_max                72    //The maximum area of the playpen

//BREED NAMES
//These are in a specific order according to category, tier, and lifestage
//Changing the numbers will give you unexpected results in evolveHandler()
#define egg                   0     //Egg, black, tier 0
#define goob                  1     //Baby, blue, tier 0
#define wibbur                2     //Baby, green, tier 0
#define xorby                 3     //Baby, red, tier 0
#define snek                  4     //Teen, blue, tier 0
#define shansy                5     //Teen, cyan, tier 0
#define moops                 6     //Teen, green, tier 0
#define hwooty                7     //Teen, green, tier 0
#define flip                  8     //Teen, yellow, tier 0
#define lugerd                9     //Teen, red, tier 0
#define culu                  10    //Adult, blue, tier 2
#define shent                 11    //Adult, blue, tier 1
#define slorp                 12    //Adult, cyan, tier 2
#define zeta                  13    //Adult, cyan, tier 1
#define butters               14    //Adult, green, tier 2
#define tribbur               15    //Adult, green, tier 1
#define corine                16    //Adult, yellow, tier 2
#define pyre                  17    //Adult, yellow, tier 1
#define rajur                 18    //Adult, red, tier 2
#define crosh                 19    //Adult, red, tier 1
#define piru                  20    //Senior, blue, tier 0
#define ascii                 21    //Senior, cyan, tier 0
#define senior3               22    //Senior, green, tier 0
#define clipper               23    //Senior, green, tier 0
#define roc                   24    //Senior, yellow, tier 0
#define monty                 25    //Senior, blue, tier 0
#define coyl                  26    //Ancient, blue, tier 0
#define doko                  27    //Anceint, green, tier 0
#define smog                  28    //Ancient, red, tier 0
#define ultimate              29    //Ultimate form

//OTHER BREED STUFF
#define max_breeds            30    //How many different breeds are there?

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

//lazerjet gameVals
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

//STRINGS DATA
#define pedia_pages           4


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
