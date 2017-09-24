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

  // Send the command to the IO Handler, and give it the command to
  Wire.beginTransmission(IOPUaddress); //Select the device's address
  Wire.write(gimmeButtons);  //Send the data
  Wire.endTransmission();    // stop transmitting

  Wire.requestFrom(int(IOPUaddress), int(1)); //Request the button state byte

  while (Wire.available()) { // slave may send less than requested
    buttbyte = Wire.read();
  }

  for (int i = 1; i <= 8; i++) {
    if ((buttbyte / i) % 2 != butTHEN[i - 1]) //If the current physical state of then button is not what it was
    {
      butTHEN[i - 1] = (buttbyte / i) % 2; //Set the "previous state" to the button state
      butNOW[i - 1] = (buttbyte / i) % 2;  //Set the current state to the button state
    }
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
  if (!beepMute) {
    // Send the command to the IO Handler, and give it the command to
    Wire.beginTransmission(IOPUaddress); // Select the device's address
    Wire.write(beepSend); // Send the command
    Wire.write(beepMode);  // Send the data
    Wire.endTransmission();    // stop transmitting
  }
}

void rumble(byte rumbleMode) {
  if (!rumbleMute) {
    // Send the command to the IO Handler, and give it the command to
    Wire.beginTransmission(IOPUaddress); // Select the device's address
    Wire.write(rumbleSend); // Send the command
    Wire.write(rumbleMode);  // Send the data
    Wire.endTransmission();    // stop transmitting
  }
}
