/*
 * Handles evolution of critters.
 * 
 * Barebones functionality right now. Finished version will have a complete system.
 */

void evolveHandler()
{
  //Hacked up temporary evolution handler
  if (heartbeats > 60 && breed < 1)
  {
    beepMode = HiLo3;
    breed = wibbur;
    aniModeSet(breed, a_idle);
  }
}
