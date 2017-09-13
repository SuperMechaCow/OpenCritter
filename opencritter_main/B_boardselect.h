//ocLite on an Arduino standalone
#ifdef __Atmega328__
//Load ocLite
#endif

//oc on ESP-01 with Arduino I/O Processing Unit
#ifdef ESP8266
//i2c and uart comms
#define i2cSDA 0
#define i2cSCL 2
#define serialbaud 115200
#endif

//oc on NodeMCU standalone
// THERE IS NO CODE FOR HANDLING INPUT AND OUTPUT WITHOUT AN IOPU YET!
#ifdef ARDUINO_ESP8266_NODEMCU
#define oc_nodemcu true
//Input/Output Pins
#define hrt_pin     D5   //D5 14
#define Abut_pin    D0   //D0 16
#define Bbut_pin    D1   //D1 5
#define Cbut_pin    D3   //D2 4
#define beeper_pin  D4   //D6 12
#define rumble_pin  D8   //D8 13
//i2c and uart comms
#define i2cSDA      D6
#define i2cSCL      D7
#define serialbaud 115200
#endif
