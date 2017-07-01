/*        SWITCH NAMES        *\
 *  These values never need to
 *  be changed. They are simply
 *  for eschewing variables
 *  and to make human read-able
 *  code.
\*                            */

//Functions
#define RESET 0

//CLOCK NAMES
#define baseCLK 0 //Base clock
#define hrtCLK 1  //Heartbeat clock
#define timeCLK 2 //Generic clock
#define butCLK 3  //Button clock
#define aniCLK 4  //Animation clock
#define beepCLK 5 //beeper clock
#define buzzCLK 6 //beeper clock

//BEEPER NAMES
#define UpChirp 1
#define DnChirp 2
#define HiLo1 3
#define HiLo3 4
#define PosBeep 5
#define NegBeep 6
#define bip 7

//MENU NAMES
//(g_ games, c_ config)
#define mainM 1
#define clockM 2
#define statsM 3
#define foodM 4
#define gameM 5
#define medsM 6
#define confM 7
#define playM 8
#define g_cardflip 9
#define c_clockset 10
#define g_bitshifter 11
//ANIMATION TYPES
#define a_idle 1
#define a_eat 2
#define a_run 3
#define a_play 4

//BREED NAMES
#define egg 0
#define wibbur 1
#define tribbur 2

//card Flip gameVals
#define gcf_nextcard 0
#define gcf_thiscard 1
#define gcf_point 2

//bitshifter gameVals
#define gbs_setup 10
#define gbs_buttons 11
#define gbs_score 12
#define gbs_gameover 13
#define gbs_point 8
#define gbs_goalbyte 9
//do not use 0-7

/*        Graphics Index        *\
 * These indicate where the game
 * has to look in EEPROM for gfx
\*                              */

#define numberoficons 9
#define numberofcrits 4
#define icon_size 32
#define crit_size 128
#define icon_dimensions 16
#define crit_dimensions 32
#define icon_start 0
#define crit_start 384

//ANIMATION NAMES
#define ani_egg_idle 1
#define ani_wibbur_idle 2
#define ani_wibbur_eat 3
#define ani_wibbur_play 4
#define ani_tribbur_idle 5
#define ani_tribbur_eat 6

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
