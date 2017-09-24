//void updateIOPU() {
//  Wire.beginTransmission(IOPUaddress); //Select the device's address
//  Wire.write(updateParam);  //Send the data
//  Wire.write(X_metabolism);
//  Wire.write(metabolism);
//  Wire.endTransmission();    // stop transmitting
//  Wire.beginTransmission(IOPUaddress); //Select the device's address
//  Wire.write(updateParam);  //Send the data
//  Wire.write(X_baseHRT_speed);
//  Wire.write(baseHRT_speed);
//  Wire.endTransmission();    // stop transmitting
//}
//
//void getButtons() { //Game-wide handling of reading button input
//
//  butREAD[0] = digitalRead(Abut_pin);  //Set the current state to the button state
//  butREAD[1] = digitalRead(Bbut_pin);
//  butREAD[2] = digitalRead(Cbut_pin);
//  Serial.println("BEFORE");
//  Serial.print(butREAD[0]);
//  Serial.print(butREAD[1]);
//  Serial.println(butREAD[2]);
//  Serial.print(butTHEN[0]);
//  Serial.print(butTHEN[1]);
//  Serial.println(butTHEN[2]);
//  Serial.print(butNOW[0]);
//  Serial.print(butNOW[1]);
//  Serial.println(butNOW[2]);
//
//  if (butREAD[0] != butTHEN[0]) //If the current physical state of then button is not what it was
//  {
//    butTHEN[0] = butREAD[0]; //Set the "previous state" to the button state
//    butNOW[0] = butREAD[0];  //Set the current state to the button state
//  }
//  if (butREAD[1] != butTHEN[1]) //If the current physical state of then button is not what it was
//  {
//    butTHEN[1] = butREAD[1]; //Set the "previous state" to the button state
//    butNOW[1] = butREAD[1];  //Set the current state to the button state
//  }
//  if (butREAD[2] != butTHEN[2]) //If the current physical state of then button is not what it was
//  {
//    butTHEN[2] = butREAD[2]; //Set the "previous state" to the button state
//    butNOW[2] = butREAD[2];  //Set the current state to the button state
//  }
//  if (butREAD[3] != butTHEN[3]) //If the current physical state of then button is not what it was
//  {
//    butTHEN[3] = butREAD[3]; //Set the "previous state" to the button state
//    butNOW[3] = butREAD[3];  //Set the current state to the button state
//  }
//  if (butREAD[4] != butTHEN[4]) //If the current physical state of then button is not what it was
//  {
//    butTHEN[4] = butREAD[4]; //Set the "previous state" to the button state
//    butNOW[4] = butREAD[4];  //Set the current state to the button state
//  }
//  if (butREAD[5] != butTHEN[5]) //If the current physical state of then button is not what it was
//  {
//    butTHEN[5] = butREAD[5]; //Set the "previous state" to the button state
//    butNOW[5] = butREAD[5];  //Set the current state to the button state
//  }
//  if (butREAD[6] != butTHEN[6]) //If the current physical state of then button is not what it was
//  {
//    butTHEN[6] = butREAD[6]; //Set the "previous state" to the button state
//    butNOW[6] = butREAD[6];  //Set the current state to the button state
//  }
//  if (butREAD[7] != butTHEN[7]) //If the current physical state of then button is not what it was
//  {
//    butTHEN[7] = butREAD[7]; //Set the "previous state" to the button state
//    butNOW[7] = butREAD[7];  //Set the current state to the button state
//  }
//
//  Serial.println("AFTER");
//  Serial.print(butREAD[0]);
//  Serial.print(butREAD[1]);
//  Serial.println(butREAD[2]);
//  Serial.print(butTHEN[0]);
//  Serial.print(butTHEN[1]);
//  Serial.println(butTHEN[2]);
//  Serial.print(butNOW[0]);
//  Serial.print(butNOW[1]);
//  Serial.println(butNOW[2]);
//}
//
//void sendhrtpin() {
//  digitalWrite(hrt_pin, heartbeats % 2);
//}
//
//void beep(byte beepMode) {
//  if (!beepMute) {
//    switch (beepMode)
//    {
//      /*
//        case 0:
//        break;
//        case 1:
//        break;
//        case beep_UpChirp: // Upwards chirp
//        if (beepStage == 0)
//        {
//          CLK[beepCLK] = CLK[baseCLK];
//          beepStage = 1;
//        }
//        else if (CLK[baseCLK] - CLK[beepCLK] > (baseHRT_speed / 2) * metabolism)
//        {
//          noTone(beeper_pin);
//          beepMode = RESET;
//          beepStage = RESET;
//        }
//        else
//        {
//          tone(beeper_pin, 1000 + ((CLK[baseCLK]) - CLK[beepCLK]) * (100 / metabolism));
//        }
//        break;
//        case beep_DnChirp: // Downwards chirp
//        if (beepStage == 0)
//        {
//          CLK[beepCLK] = CLK[baseCLK];
//          beepStage = 1;
//        }
//        else if (CLK[baseCLK] - CLK[beepCLK] > (baseHRT_speed / 2) * metabolism)
//        {
//          noTone(beeper_pin);
//          beepMode = RESET;
//          beepStage = RESET;
//        }
//        else
//        {
//          tone(beeper_pin, 2000 - ((CLK[baseCLK]) - CLK[beepCLK]) * (100 / metabolism));
//        }
//        break;
//        case beep_HiLo1: // HiLo Twitter x 1
//        if (beepStage == 0)
//        {
//          CLK[beepCLK] = CLK[baseCLK];
//          beepStage = 1;
//        }
//        else if (CLK[baseCLK] - CLK[beepCLK] > (baseHRT_speed / 2) * metabolism)
//        {
//          noTone(beeper_pin);
//          beepMode = RESET;
//          beepStage = RESET;
//        }
//        else
//        {
//          beepStage = 1 + ((CLK[baseCLK] - CLK[beepCLK]) / ((baseHRT_speed / 4) * metabolism));
//          if (beepStage % 2 == 1)
//            tone(beeper_pin, 2000);
//          else
//            tone(beeper_pin, 1000);
//        }
//        break;
//        case beep_HiLo3: // HiLo Twitter x 3
//        if (beepStage == 0)
//        {
//          CLK[beepCLK] = CLK[baseCLK];
//          beepStage = 1;
//        }
//        else if (CLK[baseCLK] - CLK[beepCLK] > (baseHRT_speed * 1.5) * metabolism)
//        {
//          noTone(beeper_pin);
//          beepMode = RESET;
//          beepStage = RESET;
//        }
//        else
//        {
//          beepStage = 1 + ((CLK[baseCLK] - CLK[beepCLK]) / ((baseHRT_speed / 4) * metabolism));
//          if (beepStage % 2 == 1)
//            tone(beeper_pin, 2000);
//          else
//            tone(beeper_pin, 1000);
//        }
//        break;
//        case beep_PosBeep:
//        if (beepStage == 0)
//        {
//          CLK[beepCLK] = CLK[baseCLK];
//          beepStage = 1;
//        }
//        if (beepStage == 1)
//        {
//          if (CLK[baseCLK] - CLK[beepCLK] > 100)
//          {
//            noTone(beeper_pin);
//            beepMode = RESET;
//            beepStage = RESET;
//          }
//          else
//          {
//            tone(beeper_pin, 2000);
//          }
//        }
//        break;
//        case beep_NegBeep:
//        if (beepStage == 0)
//        {
//          CLK[beepCLK] = CLK[baseCLK];
//          beepStage = 1;
//        }
//        if (beepStage == 1)
//        {
//          if (CLK[baseCLK] - CLK[beepCLK] > 100)
//          {
//            noTone(beeper_pin);
//            beepMode = RESET;
//            beepStage = RESET;
//          }
//          else
//          {
//            tone(beeper_pin, 1000);
//          }
//        }
//        break;
//        case beep_Bip: //bip
//        if (beepStage == 0)
//        {
//          CLK[beepCLK] = CLK[baseCLK];
//          beepStage = 1;
//        }
//        if (beepStage == 1)
//        {
//          if (CLK[baseCLK] - CLK[beepCLK] > 10)
//          {
//            noTone(beeper_pin);
//            beepMode = RESET;
//            beepStage = RESET;
//          }
//          else
//          {
//            tone(beeper_pin, 1500);
//          }
//        }
//        break;
//        case beep_Bop: //bop
//        if (beepStage == 0)
//        {
//          CLK[beepCLK] = CLK[baseCLK];
//          beepStage = 1;
//        }
//        if (beepStage == 1)
//        {
//          if (CLK[baseCLK] - CLK[beepCLK] > 10)
//          {
//            noTone(beeper_pin);
//            beepMode = RESET;
//            beepStage = RESET;
//          }
//          else
//          {
//            tone(beeper_pin, 750);
//          }
//        }
//        break;
//        case beep_Tick: //Tick
//        if (beepStage == 0)
//        {
//          CLK[beepCLK] = CLK[baseCLK];
//          beepStage = 1;
//        }
//        if (beepStage == 1)
//        {
//          if (CLK[baseCLK] - CLK[beepCLK] > 1)
//          {
//            noTone(beeper_pin);
//            beepMode = RESET;
//            beepStage = RESET;
//          }
//          else
//          {
//            tone(beeper_pin, 1500);
//          }
//        }
//        break;
//      */
//      default:
////        if (beepStage == 0)
////        {
////          CLK[beepCLK] = CLK[baseCLK];
////          beepStage = 1;
////        }
////        else if (CLK[baseCLK] - CLK[beepCLK] > (baseHRT_speed / 2) * metabolism)
////        {
////          analogWrite(beeper_pin, RESET);
////          beepMode = RESET;
////          beepStage = RESET;
////        }
////        else
////        {
////          analogWriteFreq(1000 + ((CLK[baseCLK]) - CLK[beepCLK]) * (100 / metabolism));
////          analogWrite(beeper_pin, 512);
////        }
//        break;
//    }
//  }
//}
//
//void rumble(byte rumbleMode) {
////  if (!rumbleMute) {
////    switch (rumbleMode)
////    {
////      case 0:
////        break;
////      case rumble_Alert:
////        if (rumbleStage == 0)
////        {
////          CLK[rumbleCLK] = CLK[baseCLK];
////          rumbleStage = 1;
////        }
////        else if (CLK[baseCLK] - CLK[rumbleCLK] > (baseHRT_speed * 1.5) * metabolism)
////        {
////          noTone(rumble_pin);
////          rumbleMode = RESET;
////          rumbleStage = RESET;
////        }
////        else
////        {
////          rumbleStage = 1 + ((CLK[baseCLK] - CLK[rumbleCLK]) / ((baseHRT_speed / 4) * metabolism));
////          if (rumbleStage % 2 == 1)
////            analogWrite(rumble_pin, 128);
////          else
////            analogWrite(rumble_pin, 0);
////        }
////      case rumble_Long: // Default
////        if (rumbleStage == 0)
////        {
////          CLK[rumbleCLK] = CLK[baseCLK];
////          rumbleStage = 1;
////        }
////        else if (CLK[baseCLK] - CLK[rumbleCLK] > (baseHRT_speed / 2))
////        {
////          analogWrite(rumble_pin, 0);
////          rumbleMode = RESET;
////        }
////        else
////        {
////          analogWrite(rumble_pin, 128);
////        }
////        break;
////      case rumble_Short:
////        if (rumbleStage == 0)
////        {
////          CLK[rumbleCLK] = CLK[baseCLK];
////          rumbleStage = 1;
////        }
////        else if (CLK[baseCLK] - CLK[rumbleCLK] > (baseHRT_speed / 4))
////        {
////          analogWrite(rumble_pin, 0);
////          rumbleMode = RESET;
////        }
////        else
////        {
////          analogWrite(rumble_pin, 128);
////        }
////        break;
////      default:
////        //Serial.println(F("Invalid rumble!"));
////        break;
////    }
////  }
//}
