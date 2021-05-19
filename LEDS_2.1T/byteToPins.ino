void valueToPins(uint8_t value) {
  for (int i = 7; i >= 0; i--) {
    uint8_t z[8] = {1, 2, 4, 8, 16, 32, 64, 128};
   /*mySerial.print("z : ");
    mySerial.print(z[i]);
    mySerial.print("||| value : ");
    mySerial.print(value);
    mySerial.print("||| value >= z ? :");
    mySerial.println(value >= z[i]);*/
    if (value >= z[i]) {
      digitalWrite(i + 2, HIGH); //Pins start from D2 so we add 2 to the pins number
      //mySerial.print("broche ON : D");
      //mySerial.println(i + 2);
      value -= z[i];
    }
  }
  /*if (!value) { //logiquement on retombe à 0
    mySerial.println("VALEUR : Ecriture OK !");
  } else { //sinon bah...
    mySerial.println("VALEUR : Ecriture ERRONEE !");
  }*/
}

void paramToPins(uint8_t param) {
  short myPins[4] = {A1, A2, A3, A4};
  //String SmyPins[4] = {"A1", "A2", "A3", "A4"};
  for (int i = 3; i >= 0; i--) {
    uint8_t z[4] = {1, 2, 4, 8};
    /*mySerial.print("z : ");
    mySerial.print(z[i]);
    mySerial.print("||| param : ");
    mySerial.print(param);
    mySerial.print("||| param >= z ? :");
    mySerial.println(param >= z[i]);*/
    if (param >= z[i]) {
      digitalWrite(myPins[i], HIGH); //Pins start from D2 so we add 2 to the pins number
      //mySerial.print("broche ON : ");
      //mySerial.println(SmyPins[i]);
      param -= z[i];
    }
  }
  /*if (!param) { //logiquement on retombe à 0
    mySerial.println("PARAMETRE : Ecriture OK !");
  } else { //sinon bah...
    mySerial.println("PARAMETRE : Ecriture ERRONEE !");
  }*/
}

void resetPins() {
  int del = 7; //delay en ms pour laisser le temps aux arduinos de se comprendre
  delay(del);
  digitalWrite(VP1, LOW);
  digitalWrite(VP2, LOW);
  digitalWrite(VP3, LOW);
  digitalWrite(VP4, LOW);
  digitalWrite(VP5, LOW);
  digitalWrite(VP6, LOW);
  digitalWrite(VP7, LOW);
  digitalWrite(VP8, LOW);

  digitalWrite(PP1, LOW);
  digitalWrite(PP2, LOW);
  digitalWrite(PP3, LOW);
  digitalWrite(PP4, LOW);
  delay(del);
}
