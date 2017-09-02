
//ocLite on an Arduino standalone
#ifdef __Atmega328__
//Load ocLite
#endif

//oc on ESP-01 with Arduino I/O Processing Unit
#ifdef ESP8266
//Load ESP-01 with Atmega328 IOPU
//i2c and uart comms
#define i2cSDA 0
#define i2cSCL 2
#define serialbaud 115200
#endif

//oc on NodeMCU standalone
//THIS IS TEMPORARILY SET UP FOR NODEMCU WITH IOPU
#ifdef ARDUINO_ESP8266_NODEMCU
#define ocp_node01 true

//Load all code with pins for IO
//#define hrt_pin D0
//#define Abut_pin D5
//#define Bbut_pin D2
//#define Cbut_pin D1
//#define buzzer_pin D8
//#define beeper_pin D6
//#define GPIO_pin D7

//i2c and uart comms
#define i2cSDA D3
#define i2cSCL D4
#define serialbaud 115200
#endif

//Options for loading more advanced GPUs
