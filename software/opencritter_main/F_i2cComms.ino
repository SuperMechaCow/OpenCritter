
void i2c_scanbus() { // Run during setup(), called from in-game menu, and/or periodically to check for new devices
  //checks to see if IOPU, GPU, etc. is installed about loads appropriate software (turns off handling graphics/IO when devices plug in)

  byte readByte = 0;
  byte nDevices = 0;
  byte error = 0;

  Serial.println("Scanning I2C bus...");

  for (byte address = 1; address < 127; address++) {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {

      //Record the current address in the list.
      i2c_devices[nDevices] = address;

      nDevices++;

      // See what kind of device this is
      // For some reason, this code keeps putting ANY device's address into the IOPUaddress slot, even though there's already an IOPU found.
      //      Wire.beginTransmission(address); //Select the device's address
      //      Wire.write(deviceID);  //Send the data
      //      Wire.endTransmission();    // stop transmitting
      //      //delay(1);
      //      Wire.requestFrom(int(address), int(1));
      //
      //      while (!Wire.available()); //Wait until we have something to read
      //
      //      while (Wire.available()) { //Read while there's something to read, otherwise get the hell over it and move on with your life!
      //        readByte = Wire.read();
      //        if (readByte == IOPU_device) { //Is it a IOPU?
      //          if (IOPUaddress == 0) { //Is the IOPU spot empty?
      //            Serial.println(F("IOPU"));
      //            IOPUaddress = address; //If so, this is the new IOPU!
      //            IOPUattached = true;
      //          }
      //        }
      //      }

      Serial.println(IOPUaddress);

      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);

    }
    //    else if (error == 4)
    //    {
    //      if (i2c_devices[nDevices] < 16)
    //        Serial.print("0");
    //      Serial.println(i2c_devices[nDevices], HEX);
    //
    //    }

  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");
}

void theQ() { // This asks each scanned address what information it wants

  // The idea of this code is to ask each device once per loop if it needed any data from the master, and if so

  //  byte Qrequests[] = {0};
  //  byte readByte = 0;
  //
  //  for (int address = 0; address < sizeof(i2c_devices); address++) { //Loop for as many addresses as we have found with
  //
  //    if (i2c_devices[address] != 0) { //If the device index is not blank
  //
  //      Wire.beginTransmission(i2c_devices[address]); //Select the device's address for sending
  //      Wire.write(wutuwant); //Ask the device what it wants
  //
  //      //      if (Wire.endTransmission() == 4) { //If the device doesn't understand the command
  //      //        i2c_devices[address] = 0; //Then we'll make the address blank so we don't ask next time
  //      //      }
  //      Wire.endTransmission();
  //      //delay(1);
  //      Wire.requestFrom(int(i2c_devices[address]), int(max_requests)); //Ask the device for up to the max number of requests
  //
  //      while (!Wire.available()); //Wait for reply
  //
  //      while (Wire.available()) { // slave may send less than requested
  //        Qrequests[readByte] = Wire.read();
  //        readByte++;
  //      }
  //
  //      Wire.beginTransmission(i2c_devices[address]); //Select the device's address for sending
  //      for (byte i = 0; i < sizeof(Qrequests); i++ ) {
  //        switch (Qrequests[i]) {
  //          case Q_baseHRT_speed:
  //            Wire.write(baseHRT_speed); //Send it the correct variable
  //            break;
  //          case Q_weight:
  //            Wire.write(weight); //Send it the correct variable
  //            break;
  //          case Q_Ath:
  //            Wire.write(Ath); //Send it the correct variable
  //            break;
  //          case Q_Int:
  //            Wire.write(Int); //Send it the correct variable
  //            break;
  //          case Q_Dis:
  //            Wire.write(Dis); //Send it the correct variable
  //            break;
  //          case Q_hun:
  //            Wire.write(hun); //Send it the correct variable
  //            break;
  //          case Q_hap:
  //            Wire.write(hap); //Send it the correct variable
  //            break;
  //          case Q_bor:
  //            Wire.write(bor); //Send it the correct variable
  //            break;
  //          case Q_heartbeats:
  //            Wire.write(heartbeats); //Send it the correct variable
  //            break;
  //          case Q_metabolism:
  //            Wire.write(metabolism); //Send it the correct variable
  //            break;
  //          case Q_selMenu:
  //            Wire.write(selMenu); //Send it the correct variable
  //            break;
  //          case Q_ocCursor:
  //            Wire.write(ocCursor); //Send it the correct variable
  //            break;
  //          default:
  //            break;
  //        }
  //      }
  //      Wire.endTransmission();
  //    }
  //  }
}

