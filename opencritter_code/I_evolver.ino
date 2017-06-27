void evolveHandler() {
  //Hacked up temporary evolution handler
  if (heartbeats > 60 && breed < 1)
  {
    beepMode = HiLo3;
    breed = wibbur;
    aniModeSet(breed, a_idle);
  }
}

