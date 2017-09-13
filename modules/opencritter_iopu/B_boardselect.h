//#ifdef __AVR_ATmega328P__
// IO Pins
#define hrt_pin           10
#define Abut_pin          7       //These are switched for devkit1
#define Bbut_pin          8       
#define Cbut_pin          9       //These are switched for devkit1
#define buzzer_pin        6
#define beeper_pin        3
//Unused pins: 2, 4, 6 (11, 12, 13 for SPI)
// i2c and uart comms
#define i2c_addr          IOPU_Atmega328
#define serialbaud        115200
//#endif

