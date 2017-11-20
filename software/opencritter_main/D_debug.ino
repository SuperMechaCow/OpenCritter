
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
      //3 - Change heart keyframes
      //  0 - beat_health
      //  1 - beat_sick
      //  2 - beat_cry
      //  3 - beat_hatch
      //  4 - beat_evolve
      //  5 - beat_energy

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
        case 3:
        Serial.println(F("change keyframe: "));
        while (!Serial.available())
        {
        }
        switch (Serial.parseInt())
        {
          case 1: //health
            Serial.print(F(" health: "));
            Serial.print(beat_health);
            Serial.println(F(" new val:"));
            while (!Serial.available())
            {
            }
            beat_health  = Serial.parseFloat();
            Serial.print(F("changed: "));
            Serial.println(beat_health);
            break;
          case 2: //sick
            Serial.print(F(" sick: "));
            Serial.print(beat_sick);
            Serial.println(F(" new val:"));
            while (!Serial.available())
            {
            }
            beat_sick = Serial.parseFloat();
            Serial.print(F("changed: "));
            Serial.println(beat_sick);
            break;
          case 3: //cry
            Serial.print(F(" cry: "));
            Serial.print(beat_cry);
            Serial.println(F(" new val:"));
            while (!Serial.available())
            {
            }
            beat_cry = Serial.parseFloat();
            Serial.print(F("changed: "));
            Serial.println(beat_cry);
            break;
          case 4: //hatch
            Serial.print(F(" hatch: "));
            Serial.print(beat_hatch);
            Serial.println(F(" new val:"));
            while (!Serial.available())
            {
            }
            beat_hatch = Serial.parseFloat();
            Serial.print(F("changed: "));
            Serial.println(beat_hatch);
            break;
          case 5: //evolve
            Serial.print(F(" evolve: "));
            Serial.print(beat_evolve);
            Serial.println(F("  new val:"));
            while (!Serial.available())
            {
            }
            beat_evolve = Serial.parseFloat();
            Serial.print(F("changed: "));
            Serial.println(beat_evolve);
            break;
          case 6: //energy
            Serial.print(F(" energy: "));
            Serial.print(beat_energy);
            Serial.println(F(" new val:"));
            while (!Serial.available())
            {
            }
            beat_energy = Serial.parseFloat();
            Serial.print(F("changed: "));
            Serial.println(beat_energy);
            break;
        }
        break;
      default:
        break;
    }
  }
}
