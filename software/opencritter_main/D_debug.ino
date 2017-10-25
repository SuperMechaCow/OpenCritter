
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
      //  0 - Main
      //  1 - Clock
      //  2 - Health
      //  3 - Food
      //  4 - Games
      //  5 - Config
      //2 - change stat
      //  1 - breed
      //  2 - hun
      //  3 - hap
      //  4 - bor
      //  5 - Ath
      //  6 - Dis
      //  7 - Int
      //  8 - heartbeats
      //  9 - distressbeats

      case 1:
        Serial.println(F("Which menu?"));
        while (!Serial.available()) {}
        switch (Serial.parseInt()) {
          case 0:
            Serial.println(F("Main"));
            selMenu = m_main;
            display.clearDisplay();
            break;
          case 1:
            Serial.println(F("Clock"));
            CLK[timeCLK] = CLK[baseCLK];
            selMenu = m_clockset;
            display.clearDisplay();
            break;
          case 2:
            Serial.println(F("Health"));
            CLK[timeCLK] = CLK[baseCLK];
            selMenu = m_stats;
            display.clearDisplay();
            break;
          case 3:
            Serial.println(F("Food"));
            CLK[timeCLK] = CLK[baseCLK];
            selMenu = m_food;
            display.clearDisplay();
            break;
          case 4:
            Serial.println(F("Games"));
            CLK[timeCLK] = CLK[baseCLK];
            selMenu = m_play;
            display.clearDisplay();
            break;
          case 5:
            Serial.println(F("Config"));
            CLK[timeCLK] = CLK[baseCLK];
            selMenu = m_conf;
            display.clearDisplay();
            break;
          default:
            break;
        }
        break;
      case 2:
        Serial.println(F("change parameter: "));
        while (!Serial.available())
        {
        }
        switch (Serial.parseInt())
        {
          case 1: //breed
            Serial.print(F(" breed: "));
            Serial.print(breed);
            Serial.println(F(" new val:"));
            while (!Serial.available())
            {
            }
            breed  = Serial.parseFloat();
            Serial.print(F("changed: "));
            Serial.println(breed);
            break;
          case 2: //hunger
            Serial.print(F(" hun: "));
            Serial.print(hun);
            Serial.println(F(" new val:"));
            while (!Serial.available())
            {
            }
            hun = Serial.parseFloat();
            Serial.print(F("changed: "));
            Serial.println(hun);
            break;
          case 3: //Happiness
            Serial.print(F(" hap: "));
            Serial.print(hap);
            Serial.println(F(" new val:"));
            while (!Serial.available())
            {
            }
            hap = Serial.parseFloat();
            Serial.print(F("changed: "));
            Serial.println(hap);
            break;
          case 4: //boredom
            Serial.print(F(" bor: "));
            Serial.print(bor);
            Serial.println(F(" new val:"));
            while (!Serial.available())
            {
            }
            bor = Serial.parseFloat();
            Serial.print(F("changed: "));
            Serial.println(bor);
            break;
          case 5: //Ath
            Serial.print(F(" Ath: "));
            Serial.print(Ath);
            Serial.println(F("  new val:"));
            while (!Serial.available())
            {
            }
            Ath = Serial.parseFloat();
            Serial.print(F("changed: "));
            Serial.println(Ath);
            break;
          case 6: //Dis
            Serial.print(F(" Dis: "));
            Serial.print(Dis);
            Serial.println(F(" new val:"));
            while (!Serial.available())
            {
            }
            Dis = Serial.parseFloat();
            Serial.print(F("changed: "));
            Serial.println(Dis);
            break;
          case 7: //Int
            Serial.print(F(" Int: "));
            Serial.print(Int);
            Serial.println(F(" new val:"));
            while (!Serial.available())
            {
            }
            Int = Serial.parseFloat();
            Serial.print(F("changed: "));
            Serial.println(Int);
            break;
          case 8: //heartbeats
            Serial.print(F(" beats: "));
            Serial.print(heartbeats);
            Serial.println(F(" new val:"));
            while (!Serial.available())
            {
            }
            heartbeats = Serial.parseFloat();
            Serial.print(F("changed: "));
            Serial.println(heartbeats);
            break;
          case 9: //distressbeats
            Serial.print(F(" dbeats: "));
            Serial.print(distressbeats);
            Serial.println(F(" new val:"));
            while (!Serial.available())
            {
            }
            distressbeats = Serial.parseFloat();
            Serial.print(F("changed: "));
            Serial.println(distressbeats);
        }
        break;
      default:
        break;
    }
  }
}
