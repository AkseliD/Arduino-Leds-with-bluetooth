uint8_t valueToByte() {
  uint8_t value = 0;
  uint8_t z[8] = {1, 2, 4, 8, 16, 32, 64, 128};
  for (int i = 0; i < 8; i++) {
    value += digitalRead(i + 2) * z[i];
  }
  return value;
}

uint8_t paramToByte() {
  uint8_t param = 0;
  uint8_t z[8] = {1, 2, 4, 8};
  short myPins[4] = {A1, A2, A3, A4};
  for (int i = 0; i < 4; i++) {
    param += digitalRead(myPins[i]) * z[i];
  }
  return param;
}
