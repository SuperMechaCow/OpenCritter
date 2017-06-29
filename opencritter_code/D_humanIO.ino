/*

   Handles all Input/Output for human interaction.

   Buttons, Speakers, Vibration Motors, and LEDs go here

*/

void getButton() //Game-wide handling of reading button input
{
  if (digitalRead(Abut_pin) != butTHEN[0]) //If the current physical state of then button is not what it was
  {
    butTHEN[0] = digitalRead(Abut_pin); //Set the "previous state" to the button state
    butNOW[0] = digitalRead(Abut_pin);  //Set the current state to the button state
  }
  if (digitalRead(Bbut_pin) != butTHEN[1])
  {
    butTHEN[1] = digitalRead(Bbut_pin);
    butNOW[1] = digitalRead(Bbut_pin);
  }
  if (digitalRead(Cbut_pin) != butTHEN[2])
  {
    butTHEN[2] = digitalRead(Cbut_pin);
    butNOW[2] = digitalRead(Cbut_pin);
  }
}

void beep()
{
  switch (beepMode)
  {
  case 0:
    break;
  case UpChirp: // Upwards chirp
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
      tone(beeper_pin, 1000 + ((CLK[baseCLK]) - CLK[beepCLK]) * (1 / metabolism));
    }
    break;
  case DnChirp: // Downwards chirp
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
      tone(beeper_pin, 2000 - ((CLK[baseCLK]) - CLK[beepCLK]) * (1 / metabolism));
    }
    break;
  case 3: // HiLo Twitter x 1
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
  case 4: // HiLo Twitter x 3
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
  case 5:
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
  case 6:
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
  case bip: //bip
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
  default:
    Serial.println(F("Invalid beeper!"));
    break;
  }
}

/*
void buzz() {
  switch (buzzMode)
  {
    case 0:
      break;
    case 1: // Default
      if (buzzStage == 0)
      {
        Serial.print(F("Testing buzzer "));
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
        analogWrite(buzzer_pin, 255);
      }
      break;
    default:
      Serial.println(F("Invalid buzzer!"));
      break;
  }
}
*/
