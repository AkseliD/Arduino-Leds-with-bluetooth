void testSerie() {
  if (mySerial.available()) {
    digitalWrite(13, HIGH);
    while (mySerial.available()) {
      c = mySerial.read(); // Reads the data from the serial port
      if (c == '?') {
        mySerial.print("   ///message : "); //debug
        mySerial.println(string);
        analyseSerie(); //analyse de la trame
        break;
      } else {
        string += c;
      }
    }
  } else {
    digitalWrite(13, LOW);
    string = "";
  }
}
