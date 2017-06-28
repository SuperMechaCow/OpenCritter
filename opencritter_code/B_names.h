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
#define aniCLK  4 //Animation clock
#define beepCLK 5 //beeper clock
#define buzzCLK 6 //beeper clock
#define cryCLK 7 //time between crying for attention
#define gameCLK 8 //game clock

//BEEPER NAMES
#define UpChirp 1
#define DnChirp 2
#define HiLo1 3
#define HiLo3 4
#define PosBeep 5
#define NegBeep 6

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

//ANIMATION NAMES
#define ani_egg_idle 1
#define ani_wibbur_idle 2
#define ani_wibbur_eat 3
#define ani_wibbur_play 4
#define ani_tribbur_idle 5
#define ani_tribbur_eat 6

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
