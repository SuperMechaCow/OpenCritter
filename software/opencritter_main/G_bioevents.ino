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

/*========================================================================================================================*/

void sysShock() {
  // Major biological events, such as evovling and hatching, can shock the critter's system
  // This is mostly just to give players something to do.
  hun = hun * shockHealth;
  hap = hap * shockHealth;
  bor = bor * shockHealth;
  Ath = Ath * shockPower;
  Dis = Dis * shockPower;
  Int = Int * shockPower;
}

/*========================================================================================================================*/

void cryHandler() {
  if (breed != egg) { //Eggs can't cry
    //rollResult = random(max_sickChance);
    if (random(max_sickChance) >= ((hun + hap + bor) / 3) + (Dis * 2)) { //If a roll is higher than the average of the health stats plus the Dis "bonus"
      beep(beep_HiLo3); //Cry wolf!
      Alert = true; //Make the alert icon appear on the screen
      //Wake the device from sleep and reset the sleep timer
      CLK[sleepCLK] = millis();
      deviceSleep = false;
    }
  }
}

/*========================================================================================================================*/

void sickHandler() {
  if (breed != egg) {
    //rollResult = random(sick_thresh);
    if (random(sick_thresh) >= ((hun + hap + bor) / 3)) {
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
          display.drawBitmap((i % 8) * 16, ((i / 8) * 16), gfx_icon_sick, icon_dimensions, icon_dimensions, 1); //Show alert icon
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

/*========================================================================================================================*/

void poopHandler() {
  if (breed != egg) {
    //rollResult = random(max_poopChance);
    if (random(max_poopChance) + nominal_w <= weight) { //The fatter they are, the more they poops
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

/*========================================================================================================================*/

void clearAlert() {
  if (sickCount == 0 && poopCount == 0) {
    if (sick_thresh < ((hun + hap + bor) / 3)) {
      Alert = false;
    }
    else {
      selMenu = m_stats;
    }
  }
}

/*========================================================================================================================*/

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
  foodType = food_prot;
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
  foodType = food_fats;
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
  foodType = food_carb;
}

/*========================================================================================================================*/

void discovery() {
  //When the critter's Energy bar is full, the critter has a chance to do something on it's own
  //Some things include eating, training/playing by itself, or discovering a new tool or consumable
  //What it does is determined by it's health/power at random
  //Once it has finished the action, its Energy drops to it's current Health bar (maximum of 80% max health).
  //This means that more healthy/higher metabolism critters do more actions more frequently.

  if (getHealth() > max_health * 0.8)
    Energy = max_health * 0.8;
  else
    Energy = getHealth();

  bool foundItem = false;

  while (!foundItem) {
    byte discRoll = random(0, max_power);
    byte discType = random(0, 9);
    switch (discType) {
      case 0:
        if (discRoll < Ath) {
          Inventory[inv_meds_slot][inv_owned]++;
          foundItem = true;
        }
        break;
      case 1:
        if (discRoll < Dis) {
          Inventory[inv_soda_slot][inv_owned]++;
          foundItem = true;
        }
        break;
      case 2:
        if (discRoll < Int) {
          Inventory[inv_star_slot][inv_owned]++;
          foundItem = true;
        }
        break;
      case 3:
        if (discRoll > (max_power / 2) && discRoll < Ath && Inventory[inv_biok_slot][inv_owned] < 1) {
          Inventory[inv_biok_slot][inv_owned]++;
          foundItem = true;
        }
        break;
      case 4:
        if (discRoll > (max_power / 2) && discRoll < Dis && Inventory[inv_pedia_slot][inv_owned] < 1) {
          Inventory[inv_pedia_slot][inv_owned]++;
          foundItem = true;
        }
        break;
      case 5:
        if (discRoll > (max_power / 2) && discRoll < Int && Inventory[inv_labk_slot][inv_owned] < 1) {
          Inventory[inv_labk_slot][inv_owned]++;
          foundItem = true;
        }
        break;
      case 6:
        if (discRoll > Dis) {
          eatProtein();
          foundItem = true;
        }
        break;
      case 7:
        if (discRoll > Dis) {
          eatFat();
          foundItem = true;
        }
        break;
      case 8:
        if (discRoll > Dis) {
          eatCarbs();
          foundItem = true;
        }
        break;
    }
  }
  beep(beep_UpChirp);
}

/*========================================================================================================================*/

void evolveHandler() {
  //Steps to evolving should be:
  //Cancel all current animations and games,
  //check the current breed, check params that effect which new breed it will be,
  //beep, animate, change breed, change animation, change metaBonus, add breed abilities
  //Cut health (evolving is hungry work), play new breed animation

  float distresspercent = distressbeats / heartbeats;

  selMenu = m_main;
  gameStage = RESET;
  ocCursor = RESET;
  for (int i = 0; i < 32; i++) {
    display.fillRect((i % 8) * 16, ((i / 8) * 16), 16, 16, 1);
    display.display();
    delay(5);
  }
  display.clearDisplay();

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
    //Determine the breed by it's lowest power stat, and if that power stat is higher than 50%
    //You will get a critter based on it's top two health stats, plus how well taken care of it is
    case baby:
      if (Ath < Dis && Ath < Int) {
        breed = breed + 3;
        if (Ath < (max_power / 2))
          breed++;
      }
      else if (Int < Ath && Int < Dis) {
        breed = breed + 5;
        if (Int > (max_power / 2))
          breed++;
      }
      else {
        breed = breed + 4;
        if (random(0, 2) == 1)
          breed++;
      }
      metaBonus = teen_m;
      lifestage++;
      break;

    //If the critter is becoming an adult
    //Determine the breed by current breed, highest power stat, and distressbeat to heartbeat %
    case teen:
      //Round the breed down to the nearest even number
      breed = breed - (breed % 2);
      if (Int > Dis && Int > Ath) //If Int is highest
        breed = breed + 6;
      else if (Ath > Int && Ath > Dis) //Or if Ath is highest
        breed = breed + 10;
      else  //Otherwise Dis must be highest or they are equal
        breed = breed + 8;
      if (distresspercent < 0.10) //If it was distressed less than 10% of it's life
        breed++; //Give it the higher tier critter
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
