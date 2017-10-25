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

  //If the board has buttons attached that it can read, read those first
  if (mcuinputs) {
    butREAD[0] = digitalRead(Abut_pin);  //Set the current state to the button state
    butREAD[1] = digitalRead(Bbut_pin);
    butREAD[2] = digitalRead(Cbut_pin);

    for (int i = 0; i <= 2; i++) {
      if (butREAD[i] != butTHEN[i]) //If the current physical state of then button is not what it was
      {
        CLK[sleepCLK] = millis();
        butTHEN[i] = butREAD[i]; //Set the "previous state" to the button state
        butNOW[i] = butREAD[i];  //Set the current state to the button state
      }
    }
  }
  //If the boardis designed to only work with an IOPU and has one attached
  else if (IOPUattached) {
    // Send the command to the IO Handler, and give it the command to
    Wire.beginTransmission(IOPUaddress); //Select the device's address
    Wire.write(gimmeButtons);  //Send the data
    Wire.endTransmission();    // stop transmitting

    Wire.requestFrom(int(IOPUaddress), int(1)); //Request the button state byte

    while (Wire.available()) { // slave may send less than requested
      buttbyte = Wire.read();
    }

    for (int i = 0; i <= 7; i++) {
      butREAD[i] = (buttbyte >> i) % 2;
      if (butREAD[i] != butTHEN[i]) //If the current physical state of then button is not what it was
      {
        CLK[sleepCLK] = millis();
        butTHEN[i] = butREAD[i]; //Set the "previous state" to the button state
        butNOW[i] = butREAD[i];  //Set the current state to the button state
      }
    }
  }
}

void sendhrtpin() {
  if (mcuinputs) {
    digitalWrite(hrt_pin, heartbeats % 2);
  }
  else if (IOPUattached) {
    // Send the command to the IO Handler, and give it the command to
    Wire.beginTransmission(IOPUaddress); // Select the device's address
    Wire.write(hrtSend); // Send the command
    Wire.write(byte((heartbeats % 2)));  // Send the data
    Wire.endTransmission();    // stop transmitting
  }
}

void beep(byte beepMode) {
  if (!beepMute) {
    if (mcuinputs) {
      switch (beepMode)
      {
        case 0:
          break;
        case 1:
          break;
        case beep_UpChirp: // Upwards chirp
          if (beepStage == 0)
          {
            CLK[beepCLK] = CLK[baseCLK];
            beepStage = 1;
          }
          else if (CLK[baseCLK] - CLK[beepCLK] > (baseHRT_speed / 2) * metabolism)
          {
            noTone(beeper_pin);
            beepMode = RESET;
            beepStage = RESET;
          }
          else
          {
            tone(beeper_pin, 1000 + ((CLK[baseCLK]) - CLK[beepCLK]) * (100 / metabolism));
          }
          break;
        case beep_DnChirp: // Downwards chirp
          if (beepStage == 0)
          {
            CLK[beepCLK] = CLK[baseCLK];
            beepStage = 1;
          }
          else if (CLK[baseCLK] - CLK[beepCLK] > (baseHRT_speed / 2) * metabolism)
          {
            noTone(beeper_pin);
            beepMode = RESET;
            beepStage = RESET;
          }
          else
          {
            tone(beeper_pin, 2000 - ((CLK[baseCLK]) - CLK[beepCLK]) * (100 / metabolism));
          }
          break;
        case beep_HiLo1: // HiLo Twitter x 1
          if (beepStage == 0)
          {
            CLK[beepCLK] = CLK[baseCLK];
            beepStage = 1;
          }
          else if (CLK[baseCLK] - CLK[beepCLK] > (baseHRT_speed / 2) * metabolism)
          {
            noTone(beeper_pin);
            beepMode = RESET;
            beepStage = RESET;
          }
          else
          {
            beepStage = 1 + ((CLK[baseCLK] - CLK[beepCLK]) / ((baseHRT_speed / 4) * metabolism));
            if (beepStage % 2 == 1)
              tone(beeper_pin, 2000);
            else
              tone(beeper_pin, 1000);
          }
          break;
        case beep_HiLo3: // HiLo Twitter x 3
          if (beepStage == 0)
          {
            CLK[beepCLK] = CLK[baseCLK];
            beepStage = 1;
          }
          else if (CLK[baseCLK] - CLK[beepCLK] > (baseHRT_speed * 1.5) * metabolism)
          {
            noTone(beeper_pin);
            beepMode = RESET;
            beepStage = RESET;
          }
          else
          {
            beepStage = 1 + ((CLK[baseCLK] - CLK[beepCLK]) / ((baseHRT_speed / 4) * metabolism));
            if (beepStage % 2 == 1)
              tone(beeper_pin, 2000);
            else
              tone(beeper_pin, 1000);
          }
          break;
        case beep_PosBeep:
          if (beepStage == 0)
          {
            CLK[beepCLK] = CLK[baseCLK];
            beepStage = 1;
          }
          if (beepStage == 1)
          {
            if (CLK[baseCLK] - CLK[beepCLK] > 100)
            {
              noTone(beeper_pin);
              beepMode = RESET;
              beepStage = RESET;
            }
            else
            {
              tone(beeper_pin, 2000);
            }
          }
          break;
        case beep_NegBeep:
          if (beepStage == 0)
          {
            CLK[beepCLK] = CLK[baseCLK];
            beepStage = 1;
          }
          if (beepStage == 1)
          {
            if (CLK[baseCLK] - CLK[beepCLK] > 100)
            {
              noTone(beeper_pin);
              beepMode = RESET;
              beepStage = RESET;
            }
            else
            {
              tone(beeper_pin, 1000);
            }
          }
          break;
        case beep_Bip: //bip
          if (beepStage == 0)
          {
            CLK[beepCLK] = CLK[baseCLK];
            beepStage = 1;
          }
          if (beepStage == 1)
          {
            if (CLK[baseCLK] - CLK[beepCLK] > 10)
            {
              noTone(beeper_pin);
              beepMode = RESET;
              beepStage = RESET;
            }
            else
            {
              tone(beeper_pin, 1500);
            }
          }
          break;
        case beep_Bop: //bop
          if (beepStage == 0)
          {
            CLK[beepCLK] = CLK[baseCLK];
            beepStage = 1;
          }
          if (beepStage == 1)
          {
            if (CLK[baseCLK] - CLK[beepCLK] > 10)
            {
              noTone(beeper_pin);
              beepMode = RESET;
              beepStage = RESET;
            }
            else
            {
              tone(beeper_pin, 750);
            }
          }
          break;
        case beep_Tick: //Tick
          if (beepStage == 0)
          {
            CLK[beepCLK] = CLK[baseCLK];
            beepStage = 1;
          }
          if (beepStage == 1)
          {
            if (CLK[baseCLK] - CLK[beepCLK] > 1)
            {
              noTone(beeper_pin);
              beepMode = RESET;
              beepStage = RESET;
            }
            else
            {
              tone(beeper_pin, 1500);
            }
          }
          break;

        default:
          break;
      }
    }
    else if (IOPUattached) {
      // Send the command to the IO Handler, and give it the command to
      Wire.beginTransmission(IOPUaddress); // Select the device's address
      Wire.write(beepSend); // Send the command
      Wire.write(beepMode);  // Send the data
      Wire.endTransmission();    // stop transmitting
    }
  }
}

void rumble(byte rumbleMode) {
  if (!rumbleMute) {
    if (mcuinputs) {
      switch (rumbleMode)
      {
        case 0:
          break;
        case rumble_Alert:
          if (rumbleStage == 0)
          {
            CLK[rumbleCLK] = CLK[baseCLK];
            rumbleStage = 1;
          }
          else if (CLK[baseCLK] - CLK[rumbleCLK] > (baseHRT_speed * 1.5) * metabolism)
          {
            noTone(rumble_pin);
            rumbleMode = RESET;
            rumbleStage = RESET;
          }
          else
          {
            rumbleStage = 1 + ((CLK[baseCLK] - CLK[rumbleCLK]) / ((baseHRT_speed / 4) * metabolism));
            if (rumbleStage % 2 == 1)
              analogWrite(rumble_pin, 128);
            else
              analogWrite(rumble_pin, 0);
          }
        case rumble_Long: // Default
          if (rumbleStage == 0)
          {
            CLK[rumbleCLK] = CLK[baseCLK];
            rumbleStage = 1;
          }
          else if (CLK[baseCLK] - CLK[rumbleCLK] > (baseHRT_speed / 2))
          {
            analogWrite(rumble_pin, 0);
            rumbleMode = RESET;
          }
          else
          {
            analogWrite(rumble_pin, 128);
          }
          break;
        case rumble_Short:
          if (rumbleStage == 0)
          {
            CLK[rumbleCLK] = CLK[baseCLK];
            rumbleStage = 1;
          }
          else if (CLK[baseCLK] - CLK[rumbleCLK] > (baseHRT_speed / 4))
          {
            analogWrite(rumble_pin, 0);
            rumbleMode = RESET;
          }
          else
          {
            analogWrite(rumble_pin, 128);
          }
          break;
        default:
          //Serial.println(F("Invalid rumble!"));
          break;
      }
    }
    else if (IOPUattached) {
      // Send the command to the IO Handler, and give it the command to
      Wire.beginTransmission(IOPUaddress); // Select the device's address
      Wire.write(rumbleSend); // Send the command
      Wire.write(rumbleMode);  // Send the data
      Wire.endTransmission();    // stop transmitting
    }
  }
}
