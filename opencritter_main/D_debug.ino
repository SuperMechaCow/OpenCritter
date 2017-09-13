
/*

   If debug is enabled in setup.h, it creates a debug menu that can be accessed over serial.

   This is designed to use numerical commands only.

*/


void debug()
{
  if (Serial.available())
  {
    switch (Serial.parseInt())
    {

      //serial commands:
      //1 - change menu
      //2 - change stat
      //3 - test sound

      case 1:
        Serial.println(F("Which menu?"));
        while (!Serial.available()) {}
        switch (Serial.parseInt()) {
          case 0:
            Serial.println(F("0: Clock Menu"));
            CLK[timeCLK] = CLK[baseCLK];
            selMenu = clockM;
            display.clearDisplay();
            break;
          case 1:
            Serial.println(F("1: Stats Menu"));
            CLK[timeCLK] = CLK[baseCLK];
            selMenu = statsM;
            display.clearDisplay();
            break;
          case 8:
            Serial.println(F("8: Main Menu"));
            selMenu = mainM;
            display.clearDisplay();
          default:
            break;
        }
        break;
      case 2:
        Serial.println(F("Change what stat?"));
        while (!Serial.available())
        {
        }
        switch (Serial.parseInt())
        {
          case 1: //metabolism
            Serial.print(F(" Metabolism: "));
            Serial.print(metabolism);
            Serial.println(F("  New value:"));
            while (!Serial.available())
            {
            }
            metabolism = Serial.parseFloat();
            Serial.print(F("Changed to: "));
            Serial.println(metabolism);
            break;
          case 2: //hunger
            Serial.print(F(" Hunger: "));
            Serial.print(hun);
            Serial.println(F("  New value:"));
            while (!Serial.available())
            {
            }
            hun = Serial.parseFloat();
            Serial.print(F("Changed to: "));
            Serial.println(hun);
            break;
          case 3: //Happiness
            Serial.print(F(" Happiness: "));
            Serial.print(hap);
            Serial.println(F("  New value:"));
            while (!Serial.available())
            {
            }
            hap = Serial.parseFloat();
            Serial.print(F("Changed to: "));
            Serial.println(hap);
            break;
          case 4: //boredom
            Serial.print(F(" Boredom: "));
            Serial.print(bor);
            Serial.println(F("  New value:"));
            while (!Serial.available())
            {
            }
            bor = Serial.parseFloat();
            Serial.print(F("Changed to: "));
            Serial.println(bor);
            break;
          case 5: //breed
            Serial.print(F(" Breed: "));
            Serial.print(breed);
            Serial.println(F("  New value:"));
            while (!Serial.available())
            {
            }
            breed  = Serial.parseFloat();
            Serial.print(F("Changed to: "));
            Serial.println(breed);
            break;
        }
        break;
      case 3:
        byte addrspot;
        Serial.println(F("Test which sound?"));
        while (!Serial.available())
        {
        }
        beep(Serial.parseInt());
        break;
      case 4:
        Serial.println(F("Testing rumble: "));
        rumbleMode = 1;
        break;
      //      case 5:
      //        Serial.println(F("Write what address?"));
      //        while (!Serial.available())
      //        {
      //        }
      //        addrspot = Serial.parseInt();
      //        Serial.print(F("Writing 'weight' to EEPROM address "));
      //        Serial.println(addrspot);
      //        EEPROM.write(weight, addrspot);
      //        Serial.println(weight);
      //        break;
      //      case 6:
      //        Serial.println(F("What address?"));
      //        while (!Serial.available())
      //        {
      //        }
      //        addrspot = Serial.parseInt();
      //        Serial.print(F("Reading 'weight' from EEPROM address "));
      //        Serial.println(addrspot);
      //        weight = EEPROM.read(addrspot);
      //        Serial.println(weight);
      //        break;
      default:
        break;
    }
  }
}
