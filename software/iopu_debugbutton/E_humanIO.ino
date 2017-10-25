void getButton() {
  buttbyte = 0;
  buttbyte += 1 * digitalRead(Abut_pin);  //Add this bit to the button byte if the button is being pressed
  buttbyte += 2 * digitalRead(Bbut_pin);
  buttbyte += 4 * digitalRead(Cbut_pin);
  buttbyte += 8 * digitalRead(Dbut_pin);
  //  buttbyte += 16 * 0;
  //  buttbyte += 32 * 0;
  //  buttbyte += 64 * 0;
  //  buttbyte += 128 * 0;
}

void beep() {
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
    case beep_noise: //noise
      if (beepStage == 0)
      {
        CLK[beepCLK] = CLK[baseCLK];
        beepStage = 1;
      }
      if (beepStage == 1)
      {
        if (CLK[baseCLK] - CLK[beepCLK] > 200)
        {
          noTone(beeper_pin);
          beepMode = RESET;
          beepStage = RESET;
        }
        else
        {
          tone(beeper_pin, random(1000,2000));
        }
      }
      break;
    default:
      //Serial.println(F("Invalid beeper!"));
      break;
  }
}

void buzz() {
  switch (buzzMode)
  {
    case 0:
      break;
    case buzz_Alert:
      if (buzzStage == 0)
      {
        CLK[buzzCLK] = CLK[baseCLK];
        buzzStage = 1;
      }
      else if (CLK[baseCLK] - CLK[buzzCLK] > (baseHRT_speed * 1.5) * metabolism)
      {
        noTone(buzzer_pin);
        buzzMode = RESET;
        buzzStage = RESET;
      }
      else
      {
        buzzStage = 1 + ((CLK[baseCLK] - CLK[buzzCLK]) / ((baseHRT_speed / 4) * metabolism));
        if (buzzStage % 2 == 1)
          analogWrite(buzzer_pin, 128);
        else
          analogWrite(buzzer_pin, 0);
      }
    case buzz_Long: // Default
      if (buzzStage == 0)
      {
        CLK[buzzCLK] = CLK[baseCLK];
        buzzStage = 1;
      }
      else if (CLK[baseCLK] - CLK[buzzCLK] > (baseHRT_speed / 2))
      {
        analogWrite(buzzer_pin, 0);
        buzzMode = RESET;
      }
      else
      {
        analogWrite(buzzer_pin, 128);
      }
      break;
    case buzz_Short:
      if (buzzStage == 0)
      {
        CLK[buzzCLK] = CLK[baseCLK];
        buzzStage = 1;
      }
      else if (CLK[baseCLK] - CLK[buzzCLK] > (baseHRT_speed / 4))
      {
        analogWrite(buzzer_pin, 0);
        buzzMode = RESET;
      }
      else
      {
        analogWrite(buzzer_pin, 128);
      }
      break;
    default:
      //Serial.println(F("Invalid buzzer!"));
      break;
  }
}

