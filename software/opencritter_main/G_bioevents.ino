/*
   Handles evolution, sickness, and other game changes of critters.

   Barebones functionality right now. Finished version will have a complete system.
*/

byte getHealth() {
  return ((hun + hap + bor) / 3);
}

byte getPower() {
  return ((Ath + Dis + Int) / 3);
}

void evolveHandler() {
  //Steps to evolving should be:
  //Cancel all current animations and games,
  //check the current breed, check params that effect which new breed it will be,
  //beep, animate, change breed, change animation, change metaBonus, add breed abilities
  //Cut health (evolving is hungry work), play new breed animation

  selMenu = mainM;
  gameStage = RESET;
  ocCursor = RESET;
  for (int i = 0; i < 32; i++) {
    display.fillRect((i % 8) * 16, ((i / 8) * 16), 16, 16, 1);
    display.display();
    delay(5);
  }
  display.clearDisplay();
  //add a function here to play the animation. have the function return whether it is active or not. use that to determine if it should continue or not
  switch (lifestage) {

    //If the critter is an egg and is hatching
    //Determine the breed by the highest health stat
    //(This basically makes it random which baby you will get
    case egged:
      if (hun > hap && hun > bor) { //If hun is that highest health stat
        breed = xorby;
      }
      else if (bor > hun && bor > hap) {
        breed = goob;
      }
      else {
        breed = wibbur;
      }
      metaBonus = baby_m;
      lifestage++;
      break;
    //If the critter is a baby becoming a teen
    //Determine the breed by it's lowest power stat, and if that power stat is higher than 50
    //You will get a critter based on it's top two health stats, plus how well taken care of it is
    case baby:
      switch (breed) {

        //
        //goob can become a snek, shansy, or hwooty
        case goob:
          //If Ath is it's lowest power stat, it's farthest from the Ath critters
          if (Ath < Dis && Ath < Int) {
            if (Ath > 50) {
              breed = snek;
            }
            else {
              breed = shansy;
            }
          }
          //If Int is it's lowest power stat, then it's furthest from Int Critters
          else if (Int < Ath && Int < Dis) {
            if (Int > 50) {
              breed = shansy;
            }
            else {
              breed = hwooty;
            }
          }
          //If Dis is it's lowest power stat, then it stays in the middle
          else {
            breed = hwooty;
          }
          break;

        //
        //xorby can become lugerd, flip, or moops. Basically the polar opposite of goob
        case xorby:
          //If Ath is it's lowest power stat, it's farthest from the Ath critters
          if (Ath < Dis && Ath < Int) {
            if (Ath > 50) {
              breed = moops;
            }
            else {
              breed = flip;
            }
          }
          //If Int is it's lowest power stat, then it's furthest from Int Critters
          else if (Int < Ath && Int < Dis) {
            if (Int > 50) {
              breed = lugerd;
            }
            else {
              breed = flip;
            }
          }
          //If Dis is it's lowest power stat, then it stays in the middle
          else {
            breed = flip;
          }
          break;
        //
        //wibbur can become shansy, hwooty, moops, or flip
        case wibbur:
          //If Ath is it's lowest power stat, it's farthest from the Ath critters
          if (Ath < Dis && Ath < Int) {
            if (Ath > 50) {
              breed = shansy;
            }
            else {
              breed = hwooty;
            }
          }
          //If Int is it's lowest power stat, then it's furthest from Int Critters
          else if (Int < Ath && Int < Dis) {
            if (Int > 50) {
              breed = flip;
            }
            else {
              breed = moops;
            }
          }
          //If Dis is it's lowest power stat, then it stays in the middle...
          //... but the middle is two differnt critters! I did not think this out!
          else {
            if (random(0, 100) >= 50)
              breed = moops;
            else
              breed = hwooty;
          }
          break;
      }
      metaBonus = teen_m;
      lifestage++;
      break;

    case teen:
      breed = tribbur;
      metaBonus = adult_m;
      lifestage++;
      break;

    case adult:
      metaBonus = senior_m;
      lifestage = 4;
      break;

    default:
      break;
  }

  beep(beep_UpChirp);
  aniMode = a_idle;
  sysShock();

}

void sysShock() {
  // Major biological events, such as evovling and hatching, can shock the critter's system
  hun = hun / 2;
  hap = hap / 2;
  bor = bor / 2;
  Ath = Ath / 2;
  Dis = Dis / 2;
  Int = Int / 2;
}

void cryHandler() {
  if (breed != egg) { //Eggs can't cry
    rollResult = random(max_sickChance);
    if (rollResult >= ((hun + hap + bor) / 3) + (Dis * 2)) { //If a roll is higher than the average of the health stats plus the Dis "bonus"
      beep(beep_HiLo3); //Cry wolf!
      Alert = true; //Make the alert icon appear on the screen
      //Wake the device from sleep and reset the sleep timer
      CLK[sleepCLK] = millis();
      deviceSleep = false;
    }
  }
}

void sickHandler() {
  if (breed != egg) {
    rollResult = random(sick_thresh);
    if (rollResult >= ((hun + hap + bor) / 3)) {
      if (sickCount < 4) {//Four is the max number of illnesses
        sickCount++; //Add additional illness
        beep(beep_DnChirp); //Alert the player
        Alert = true;
        //Wake the device from sleep and reset the sleep timer
        CLK[sleepCLK] = millis();
        deviceSleep = false;
      }
      else if (sickCount == 4) {
        //Wake the device from sleep and reset the sleep timer
        CLK[sleepCLK] = millis();
        deviceSleep = false;
        deadcritter = true; //Make it dead
        beep(beep_DnChirp);
        display.clearDisplay();
        for (int i = 0; i < 32; i++) {
          display.drawBitmap((i % 8) * 16, ((i / 8) * 16), gfx_icon_sick, 16, 16, 1); //Show alert icon
          display.display();
          delay(5);
        }
        display.display();
      }
    }
    else if (sick_thresh >= ((hun + hap + bor) / 3)) {
      //Cry for attention! I didn't get sick but I could!
      beep(beep_HiLo3); //Alert the player
      Alert = true;
      //Wake the device from sleep and reset the sleep timer
      CLK[sleepCLK] = millis();
      deviceSleep = false;
    }
  }
}

void poopHandler() {
  if (breed != egg) {
    rollResult = random(max_poopChance);
    //    if (debugMode) {
    //      Serial.print("POOP ");
    //      Serial.print(rollResult + nominal_w);
    //      Serial.print(" <= ");
    //      Serial.println(weight);
    //    }
    if (rollResult + nominal_w <= weight) { //The fatter they are, the more they poops
      if (poopCount < 4) {//Four is the max number of poops
        poopCount++; //Add additional poops
        beep(beep_DnChirp); //Alert the player
        Alert = true;
        //Wake the device from sleep and reset the sleep timer
        CLK[sleepCLK] = millis();
        deviceSleep = false;
        if (random(100) < Ath) //More athletic critters are more likely to...
          if (weight > 10) // ... -- if they are overweight -- ...
            weight--; //... lose weight from pooping
      }
    }
  }
}

void clearAlert() {
  if (sickCount == 0) {
    if (poopCount == 0) {
      if (sick_thresh < ((hun + hap + bor) / 3)) {
        Alert = false;
      }
      else {
        selMenu = statsM;
      }
    }
  }
}

void eatProtein() {
  if (hun <= max_health - foodbonus)
    hun += foodbonus;
  else
    hun = max_health;
  if (random(0, 101) >= Ath)
    weight += 1;
  if (weight >= (nominal_w * 2))
    weight = nominal_w * 2;
  aniStage = RESET;
  aniLast = RESET;
  aniMode = a_eat;
}

void eatFat() {
  if (hap <= max_health - (foodbonus * 2))
    hap += foodbonus * 2;
  else
    hap = max_health;
  if (random(0, 101) >= Ath)
    weight += 1;
  weight += 1;
  if (weight >= (nominal_w * 2))
    weight = nominal_w * 2;
  if (Dis > 0)
    Dis -= 1;

  aniStage = RESET;
  aniLast = RESET;
  aniMode = a_eat;
}

void eatCarbs() {
  if (bor <= max_health - (foodbonus * 2))
    bor += foodbonus  * 2;
  else
    bor = max_health;
  if (random(0, 101) >= Ath)
    weight += 1;
  weight += 1;
  if (weight >= (nominal_w * 2))
    weight = nominal_w * 2;
  if (Int > 0)
    Int -= 1;

  aniStage = RESET;
  aniLast = RESET;
  aniMode = a_eat;
}

void discovery() {
  //When the critter's Energy bar is full, the critter has a chance to do something on it's own
  //Some things include eating, training/playing by itself, or discovering a new tool or consumable
  //What it does is determined by it's health/power at random
  //Once it has finished the action, its Energy drops to it's current Health param.
  //This means that more healthy/higher metabolism critters do more actions more frequently.

  Energy = getHealth();
  Inventory[inv_meds_slot][inv_owned]++;
  beep(beep_UpChirp);

}

