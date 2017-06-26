void beep()
{
  switch (beepMode)
  {
    case 0:
      break;
    case 1: // Upwards chirp
      if (beepStage == 0)
      {
        Serial.print(F("beeper 1: Upwards chirp at: "));
        Serial.println(metabolism);
        CLK[beepCLK] = CLK[baseCLK];
        beepStage = 1;
      }
      else if (CLK[baseCLK] - CLK[beepCLK] > (baseHRT_speed / 2) * metabolism)
      {
        noTone(beeper_pin);
        beepMode = RESET;
      }
      else
      {
        tone(beeper_pin, 1000 + ((CLK[baseCLK]) - CLK[beepCLK]) * (1 / metabolism));
      }
      break;
    case 2: // Downwards chirp
      if (beepStage == 0)
      {
        Serial.print(F("beeper 1: Upwards chirp at: "));
        Serial.println(metabolism);
        CLK[beepCLK] = CLK[baseCLK];
        beepStage = 1;
      }
      else if (CLK[baseCLK] - CLK[beepCLK] > (baseHRT_speed / 2) * metabolism)
      {
        noTone(beeper_pin);
        beepMode = RESET;
      }
      else
      {
        tone(beeper_pin, 2000 - ((CLK[baseCLK]) - CLK[beepCLK]) * (1 / metabolism));
      }
      break;
    case 3: // HiLo Twitter x 1
      if (beepStage == 0)
      {
        Serial.print(F("beeper 3: HiLo Twitter x 1 at: "));
        Serial.println(metabolism);
        CLK[beepCLK] = CLK[baseCLK];
        beepStage = 1;
      }
      else if (CLK[baseCLK] - CLK[beepCLK] > (baseHRT_speed / 2) * metabolism)
      {
        noTone(beeper_pin);
        beepMode = RESET;
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
    case 4: // HiLo Twitter x 3
      if (beepStage == 0)
      {
        Serial.print(F("beeper 4: HiLo Twitter x 3 at: "));
        Serial.println(metabolism);
        CLK[beepCLK] = CLK[baseCLK];
        beepStage = 1;
      }
      else if (CLK[baseCLK] - CLK[beepCLK] > (baseHRT_speed * 1.5) * metabolism)
      {
        noTone(beeper_pin);
        beepMode = RESET;
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
    case 5:
      Serial.println(F("Buuzer 5: PosiBlip"));
      tone(beeper_pin, 2000);
      delay(100);
      noTone(beeper_pin);
      beepMode = RESET;
      break;
    case 6:
      Serial.println(F("Buuzer 6: NegaBlip"));
      tone(beeper_pin, 1000);
      delay(100);
      noTone(beeper_pin);
      beepMode = RESET;
      break;
    default:
      Serial.println(F("Invalid beeper!"));
      break;
  }
}
