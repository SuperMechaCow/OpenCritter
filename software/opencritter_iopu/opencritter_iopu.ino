#include <Wire.h>

//Include custom files
#include "A_labels.h"
#include "B_boardselect.h"
#include "C_setup.h"

void setup()
{
  //Spin up a comm port
  if (debugMode)
    Serial.begin(serialbaud);

  //Start the I2C slave and give it an address
  Wire.begin(i2c_addr);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);

  //Set pin modes for the input tactile switches
  pinMode(Abut_pin, INPUT);
  pinMode(Bbut_pin, INPUT);
  pinMode(Cbut_pin, INPUT);

  //Set the heartbeat, speaker, and rumble motor to outputs
  pinMode(hrt_pin, OUTPUT);
  pinMode(beeper_pin, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);

  beepMode = beep_UpChirp;

}

void loop()
{
  CLK[baseCLK] = millis(); //Update clock to the current millisecond

  //add2Q(Q_metabolism);
  Qrequests[0] = Q_metabolism;

  if (!beepMute)
    beep();
  if (!buzzMute)
    buzz();
  //if (debugMode)
  //debug();
}

