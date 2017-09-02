
void updateIOPU() {
  Wire.beginTransmission(IOPUaddress); //Select the device's address
  Wire.write(updateParam);  //Send the data
  Wire.write(X_metabolism);
  Wire.write(metabolism);
  Wire.endTransmission();    // stop transmitting
  Wire.beginTransmission(IOPUaddress); //Select the device's address
  Wire.write(updateParam);  //Send the data
  Wire.write(X_baseHRT_speed);
  Wire.write(baseHRT_speed);
  Wire.endTransmission();    // stop transmitting
}

void getButtons() { //Game-wide handling of reading button input

  byte readByte = 0;

  // Send the command to the IO Handler, and give it the command to
  Wire.beginTransmission(IOPUaddress); //Select the device's address
  Wire.write(gimmeButtons);  //Send the data
  Wire.endTransmission();    // stop transmitting






  // This code is set to read 8 individual bytes from the the IOPU, however the IOPU only sends a 1 or 0 in each byte.
  // To reduce chatter on the i2c bus, these 8 bytes should be reduced to 8-bits
  // Additional bytes should be added to send analog data

  Wire.requestFrom(int(IOPUaddress), int(8));






  while (Wire.available()) { // slave may send less than requested
    butREAD[readByte] = Wire.read();
    readByte++;
  }
  readByte = RESET;

  if (butREAD[0] != butTHEN[0]) //If the current physical state of then button is not what it was
  {
    butTHEN[0] = butREAD[0]; //Set the "previous state" to the button state
    butNOW[0] = butREAD[0];  //Set the current state to the button state
  }
  if (butREAD[1] != butTHEN[1]) //If the current physical state of then button is not what it was
  {
    butTHEN[1] = butREAD[1]; //Set the "previous state" to the button state
    butNOW[1] = butREAD[1];  //Set the current state to the button state
  }
  if (butREAD[2] != butTHEN[2]) //If the current physical state of then button is not what it was
  {
    butTHEN[2] = butREAD[2]; //Set the "previous state" to the button state
    butNOW[2] = butREAD[2];  //Set the current state to the button state
  }
  if (butREAD[3] != butTHEN[3]) //If the current physical state of then button is not what it was
  {
    butTHEN[3] = butREAD[3]; //Set the "previous state" to the button state
    butNOW[3] = butREAD[3];  //Set the current state to the button state
  }
  if (butREAD[4] != butTHEN[4]) //If the current physical state of then button is not what it was
  {
    butTHEN[4] = butREAD[4]; //Set the "previous state" to the button state
    butNOW[4] = butREAD[4];  //Set the current state to the button state
  }
  if (butREAD[5] != butTHEN[5]) //If the current physical state of then button is not what it was
  {
    butTHEN[5] = butREAD[5]; //Set the "previous state" to the button state
    butNOW[5] = butREAD[5];  //Set the current state to the button state
  }
  if (butREAD[6] != butTHEN[6]) //If the current physical state of then button is not what it was
  {
    butTHEN[6] = butREAD[6]; //Set the "previous state" to the button state
    butNOW[6] = butREAD[6];  //Set the current state to the button state
  }
  if (butREAD[7] != butTHEN[7]) //If the current physical state of then button is not what it was
  {
    butTHEN[7] = butREAD[7]; //Set the "previous state" to the button state
    butNOW[7] = butREAD[7];  //Set the current state to the button state
  }


}

void sendhrtpin() {

  // Send the command to the IO Handler, and give it the command to
  Wire.beginTransmission(IOPUaddress); // Select the device's address
  Wire.write(hrtSend); // Send the command
  Wire.write(byte((heartbeats % 2)));  // Send the data
  Wire.endTransmission();    // stop transmitting
}

void beep(byte beepMode) {

  // Send the command to the IO Handler, and give it the command to
  Wire.beginTransmission(IOPUaddress); // Select the device's address
  Wire.write(beepSend); // Send the command
  Wire.write(beepMode);  // Send the data
  Wire.endTransmission();    // stop transmitting
}

void buzz(byte buzzMode) {

  // Send the command to the IO Handler, and give it the command to
  Wire.beginTransmission(IOPUaddress); // Select the device's address
  Wire.write(buzzSend); // Send the command
  Wire.write(buzzMode);  // Send the data
  Wire.endTransmission();    // stop transmitting

}
