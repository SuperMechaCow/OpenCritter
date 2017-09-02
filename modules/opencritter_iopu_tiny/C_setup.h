#define versionnum "0.01"
#define branchnum "0.00"
#define release "070717"

// This device
#define i2c_addr          10
#define devicetype        IOPU_Atmega328

bool debugMode = false;

// Beeper functions
bool beepMute = 0;
byte beepMode = 0;
byte beepStage = 0;

// Buzzing functions
bool buzzMute = false;
byte buzzMode = 0;
byte buzzStage = 0;

unsigned long CLK[7] = {0}; //See clock array names

//Button states, Then and Now
bool butNOW[8] = {0};
bool butTHEN[8] = {0};

byte readByte = 0;
byte sendByte = 0;

int baseHRT_speed = 20;
byte metabolism = 50;

byte Qrequests[max_requests] = {0};

//void readQ(byte incoming) {
//  switch (incoming) {
//    
//  }
//}

