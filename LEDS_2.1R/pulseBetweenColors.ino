void pulseBetweenColors() {
  uint8_t pR, pG, pB;
  pR = map(quadwave8(spe+=incSpe), 0, 255, R, RSec);
  pG = map(quadwave8(spe+=incSpe), 0, 255, G, GSec);
  pB = map(quadwave8(spe+=incSpe), 0, 255, B, BSec);
  FastLED.showColor(CRGB(pR, pG, pB));
}
