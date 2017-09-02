
/*
   For fast editting and human readability, we used defined labels.
   These are just defined parameters, and contain no variables (constant or otherwsie).
*/

#define debugMode true

/*========================================================================================================================
    i2c Comms Labels
  ========================================================================================================================*/

// OLED ADDRESS
#define OLED_device       60

// The Q
#define max_requests      13

// Device Types
#define IOPU_device       2
#define GPU_device        4

// Requests
#define deviceID          10
#define wutuwant          11
#define gimmeButtons      12

// Command
#define debugSet          20
#define hrtSend           21
#define beepSend          22
#define buzzSend          23
#define updateParam       24

// Commands (for The Q. Up to 128 types of requests)
#define Q_baseHRT_speed   1
#define Q_breed           2
#define Q_weight          3
#define Q_Ath             4
#define Q_Int             5
#define Q_Dis             6
#define Q_hun             7
#define Q_hap             8
#define Q_bor             9
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
#define RESET 0

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

// BUZZER NAMES
//0 and 1 are reserved for changing buzzer mute state
#define buzz_Alert        2
#define buzz_Long         3
#define buzz_Short        4

/*        Game Properties       *\
   These change certain constants
   throughout the game. Changing
   these will impact gameplay.
  \*                              */

//MASTER PARAMETERS
#define baseHRT_speed     20          //Standard is 20, but this can be tweakedfor debugging purposes
#define ref_int           1000        //Standard time between refresh rates
#define max_stats         255         //The highest a stat can go
#define max_traits        100         //The highest a trait can go
#define max_metabolism    100         //The slowest the metabolism can be
#define sick_base         25          //The lowest the sick threshold can be
#define sick_multi        20          //Multiplier used to calculate chance of sickness
#define sick_penalty      10          //How much the trait is "lowered" by when calculating stat drain
#define foodbonus         25          //How much does food increase the stat?
#define gamebonus         10          //How much do games increase a stat?

//Random Number Maximums
#define max_sickChance    255
#define max_poopChance    20
#define max_drainChance   101

//Heartbeat keyframes
#if debugMode == true
#define stat_beat         10          //Roll to drain stats every X heartbeats
#define sick_beat         25          //Roll for sickness every X heartbeats
#define poop_beat         25          //Roll for poop every X beats
#define cry_beat          25          //Roll to cry for attention every X heartbeats
#define hatch_beat        10          //How long it takes to hatch the egg
#define evolve_beat       1000        //How many beats it takes to evolve
#else
#define stat_beat         20          //Roll to drain stats every X heartbeats
#define sick_beat         100         //Roll for sickness every X heartbeats
#define poop_beat         100         //Roll for poop every X beats
#define cry_beat          100         //Roll to cry for attention every X heartbeats
#define hatch_beat        1000        //How long it takes to hatch the egg
#define evolve_beat       10000       //How many beats it takes to evolve
#endif

//BASE WEIGHT
#define nominal_w         10
#define egg_w             5
#define wibbur_w          10
#define snek_w            15
#define tribbur_w         20

//BASE METABOLISM
#define egg_m             5
#define baby_m            10
#define teen_m            20
#define adult_m           40
#define senior_m          60

//MENU NAMES
//(g_ games, c_ config)
#define mainM             1
#define clockM            2
#define statsM            3
#define foodM             4
#define gameM             5
#define medsM             6
#define confM             7
#define playM             8
#define g_cardflip        9
#define c_clockset        10
#define g_bitshifter      11

//ANIMATION TYPES
#define a_idle            1
#define a_eat             2
#define a_run             3
#define a_play            4

//BREED NAMES
#define egg               0
#define wibbur            1
#define tribbur           2
#define snek              3

//card Flip gameVals
#define gcf_nextcard      0
#define gcf_thiscard      1
#define gcf_point         2

//bitshifter gameVals
#define gbs_setup         10
#define gbs_buttons       11
#define gbs_score         12
#define gbs_gameover      13
#define gbs_point         8
#define gbs_goalbyte      9
//do not use 0-7

/*        Graphics Index        *\
   These indicate where the game
   has to look in EEPROM for gfx
  \*                              */

#define numberoficons     9
#define numberofcrits     4
#define icon_size         32
#define crit_size         128
#define icon_dimensions   16
#define crit_dimensions   32
#define icon_start        0
#define crit_start        384

//ANIMATION NAMES
#define ani_egg_idle          1
#define ani_wibbur_idle       2
#define ani_wibbur_eat        3
#define ani_wibbur_play       4
#define ani_tribbur_idle      5
#define ani_tribbur_play      6
#define ani_tribbur_eat       7
#define ani_snek_idle         8
#define ani_snek_eat          9
#define ani_snek_play         10

//FRAME NAMES
#define icon_food 1
#define icon_clok 2
#define icon_stat 3
#define icon_game 4
#define icon_meds 5
#define icon_conf 6
#define icon_sick 7
#define icon_poop 8
#define icon_unon 9
#define egg_idle 10
#define egg_main 11
#define wibbur_idle 12
#define wibbur_main 13
#define wibbur_play 14
#define snek_idle 12
#define snek_main 13
#define snek_play 14

#define icon_food_addr 0
#define icon_clok_addr 32
#define icon_stat_addr 64
#define icon_game_addr 96
#define icon_meds_addr 128
#define icon_conf_addr 160
#define icon_sick_addr 192
#define icon_poop_addr 224
#define icon_unon_addr 256
#define egg_main_addr 384
#define egg_idle_addr 512
#define wibbur_main_addr 640
#define wibbur_idle_addr 768
