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

