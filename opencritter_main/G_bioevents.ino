
/*
   Handles evolution, sickness, and other game changes of critters.

   Barebones functionality right now. Finished version will have a complete system.
*/

void evolveHandler()
{
  //Steps to evolving should be:
  //Cancel all current animations and games,
  //check the current breed, check params that effect which new breed it will be,
  //beep, animate, change breed, change animation, change metaBonus, add breed abilities
  //Cut stats (evolving is hungry work), play new breed animation


  selMenu = mainM;
  display.clearDisplay();
  //aniModeSet(EVOLVEANIMAITONHERE);
  gameStage = RESET;
  ocCursor = RESET;

  switch (breed) {
    case egg:
      breed = wibbur;
      metaBonus = baby_m;
      lifestage++;
      break;
    case wibbur:
      breed = snek;
      metaBonus = teen_m;
      lifestage++;
      break;
    case snek:
      breed = tribbur;
      metaBonus = adult_m;
      lifestage++;
      break;
    case tribbur:
      metaBonus = senior_m;
      lifestage = 4;
      break;
    default:
      break;
  }

  beep(beep_UpChirp);
  aniModeSet(breed, a_idle);
  hun = hun / 2;
  hap = hap / 2;
  bor = bor / 2;

}

void cryHandler() {
  if (breed != egg) { //Eggs can't cry
    rollResult = random(max_sickChance);
    if (debugMode) {
      Serial.print("CRY  ");
      Serial.print(rollResult);
      Serial.print(" >= ");
      Serial.println(((hun + hap + bor) / 3) + (Dis * 2));
    }
    if (rollResult >= ((hun + hap + bor) / 3) + (Dis * 2)) { //If a roll is higher than the average of the stats plus the Dis "bonus"
      beep(beep_HiLo3); //Cry wolf!
      Alert = true; //Make the alert icon appear on the screen
    }
  }
}

void sickHandler() {

  if (breed != egg) {
    rollResult = random(sick_thresh);
    if (debugMode) {
      Serial.print("SICK ");
      Serial.print(rollResult);
      Serial.print(" >= ");
      Serial.println((hun + hap + bor) / 3);
    }
    if (rollResult >= ((hun + hap + bor) / 3)) {
      if (sickCount < 4) {//Four is the max number of illnesses
        sickCount++; //Add additional illness
        beep(beep_DnChirp); //Alert the player
        Alert = true;
      }
    }
    else if (sick_thresh >= ((hun + hap + bor) / 3)) {
      //Cry for attention! I didn't get sick but I could!
      beep(beep_HiLo3); //Alert the player
      Alert = true;
    }
  }
}

void poopHandler() {
  if (breed != egg) {
    rollResult = random(max_poopChance);
    if (debugMode) {
      Serial.print("POOP ");
      Serial.print(rollResult + nominal_w);
      Serial.print(" <= ");
      Serial.println(weight);
    }
    if (rollResult + nominal_w <= weight) { //The fatter they are, the more they poops
      if (poopCount < 4) {//Four is the max number of poops
        poopCount++; //Add additional poops
        beep(beep_DnChirp); //Alert the player
        Alert = true;
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
    }
  }
}
