void rainbowFixe() {
  FastLED.showColor(CHSV(spe+=incSpe, 255, BRIGHTNESS));
  /*Serial.print("HSV : ");
  Serial.println(decal);*/
}

void rainbowWave() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(decal+=incDec, 255, BRIGHTNESS);
  }
  decal -= (incDec * (NUM_LEDS)) + incSpe; 
  FastLED.show();
}
