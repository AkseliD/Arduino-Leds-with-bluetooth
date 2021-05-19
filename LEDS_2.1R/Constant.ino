void constant() {
  if (!noRepeat) {
    FastLED.showColor(CRGB(R, G, B));
    /*
      Serial.print("RGB : ");
      Serial.print(R);
      Serial.print(", ");
      Serial.print(G);
      Serial.print(", ");
      Serial.println(B);
    */
  }
}

void extinction() {
  if (!noRepeat) {
    FastLED.showColor(CRGB::Black);
    //Serial.print("Noir");
  }
}
