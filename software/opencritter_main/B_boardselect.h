//ocLite on an Arduino standalone
#ifdef __Atmega328__
//Load ocLite
#endif

//oc on ESP-01 with Arduino I/O Processing Unit
#ifdef ESP8266
#define oc_esp8266  true
#define mcuinputs  false
//load related libraries
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
//declare pin numbers
#define hrt_pin     0
#define Abut_pin    0
#define Bbut_pin    0
#define Cbut_pin    0
#define beeper_pin  0
#define rumble_pin  0
//i2c and uart comms
#define i2cSDA 0
#define i2cSCL 2
#define serialbaud 115200
#endif

//oc on NodeMCU standalone
#ifdef ARDUINO_ESP8266_NODEMCU
#define oc_esp8266 false
#define mcuinputs true
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

#ifdef __AVR_ATmega2560__
#define oc_esp8266 false
#define mcuinputs true
//Input/Output Pins
#define hrt_pin     10
#define Abut_pin    7
#define Bbut_pin    8
#define Cbut_pin    9
#define beeper_pin  6
#define rumble_pin  3
#define serialbaud 115200
#endif
