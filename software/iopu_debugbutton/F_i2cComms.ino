void receiveEvent() { //The master has sent something to you!
  while (Wire.available()) {
    readByte = Wire.read();
    switch (readByte) {
      case debugSet:
        readByte = Wire.read();
        debugMode = !debugMode;
        readByte = RESET;
        break;
      case hrtSend:
        readByte = Wire.read();
        digitalWrite(hrt_pin, readByte);
        readByte = RESET;
        break;
      case beepSend:
        beepMode = Wire.read();
        if (!beepMode) // Beep mode is 0 = Mute beeper
          beepMute = true;
        if (beepMode == 1) {
          beepMute = false;
          beepMode = beep_HiLo1;
        }
        beepStage = RESET;
        readByte = RESET;
        break;
      case buzzSend:
        buzzMode = Wire.read();
        if (!buzzMode) // buzz mode is 0 = Mute buzzer
          buzzMute = true;
        if (buzzMode == 1) {
          buzzMute = false;
          buzzMode = buzz_Long;
        }
        buzzStage = RESET;
        readByte = RESET;
        break;
      case deviceID:
        break;
      case updateParam:
        switch (Wire.read()) {
          case X_metabolism:
            metabolism = Wire.read();
            break;
          case X_baseHRT_speed:
            baseHRT_speed = Wire.read();
            break;
        }
        break;
      case gimmeButtons:
        getButton();
        break;
      case wutuwant:
        break;
      default:
        //Serial.println(F("Unknown command!"));
        readByte = RESET;
        break;
    }
  }
}

void requestEvent() { //The master is asking you for bytes!
  //request Events should aways have a receive event immediately before.
  //readByte is the command you were given from that receive event.
  //This tells us what kind of information the master is asking for and how to reply
  switch (readByte) {
    case deviceID: //If the master is asking us what type of device this is
      //Then tell the master what we are...?
      Wire.write(devicetype);
      break;
    case gimmeButtons: //If the master is asking us which buttons are pressed
      /* This used to send 8 bytes of 0 or 1 over i2c. Left here for legacy purposes
        //      for (int i = 0; i < 8; i++) {
        //        if (debugMode) {
        //          if (i <= 2)
        //          Serial.print(butNOW[i]);
        //        }
        //        Wire.write(butNOW[i]);
        //      }
        //      if (debugMode)
        //        Serial.println("");
      */
      Wire.write(buttbyte);
      break;
    case wutuwant: //If the master is asking us what information we need.
      // This code is totally defunct. Just here for when I tackle this later.
      //      for (int i = 0; i < max_requests; i++) {
      //        //TinyWireS.send(Qrequests[i]);
      //        TinyWireS.send(Qrequests[0]);
      //      }
      //      while (!TinyWireS.available()); //Wait for response
      //      while (TinyWireS.available()) {
      //
      //        metabolism = TinyWireS.receive();
      //        Serial.println(metabolism);
      //
      //      }
      break;
    default:
      //Serial.println(F("Unknown request!"));
      break;
  }
}

void add2Q(byte addThis) {
  //We use this to find a spot on the Q that's empty
  //Then we put that request into the Q at the end

  byte index = 0;

  while (Qrequests[index] != 0) {
    //If it's not empty, move the index to the next slot
    index++;
    //This loop will break when it finds an empty spot
  }

  if (index < max_requests) {
    //Make sure the queue isn't full
    //Then add the parameter we want to request to the list
    Qrequests[index] = addThis;
  }

}
