void metronome() {
  currentMicrosON = micros();
  //int mR, mG, mB;

  if (currentMicrosON - previousMicrosON >= interval) {
    previousMicrosON = currentMicrosON;
    currentMicrosOFF = micros();

/*
    LedActive = abs(LedActive - 1);
    mR = R * LedActive;
    mG = G * LedActive;
    mB = B * LedActive;
*/
    FastLED.showColor(CRGB(R, G, B));
  }
  if (currentMicrosOFF - previousMicrosON >= interval * 0.1) {
    // save the last time you blinked the LED
    previousMicrosOFF = currentMicrosON;
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(0, 0, 0);
    }
    FastLED.show();
  }
}
