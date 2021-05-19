void receptArduino(uint8_t param, uint8_t value) {
  //PARAMETRE :
  // 1 : Changement de couleur ROUGE
  // 2 : Changement de couleur VERT
  // 3 : Changement de couleur BLEU
  // 4 : Changement de MODE
  // 5 : Changement de BRIGHTNESS
  // 6 : Changement de BPM
  // 7 : Changement de DECAL
  // 8 : Changement ROUGE secondaire
  // 9 : Changement VERT secondaire
  // 10 : Changement BLEU secondaire
  // 11 : Changement de VITESSE
  if (noReRead) {
    /*
        Serial.print("valeur : ");
        Serial.println(value);
        Serial.print("paramètre : ");
        Serial.println(param);
    */
    EEPROM.put(param, value);

    switch (param) { //Quel paramètre faut-il changer ?
      case 1 : // 1 : Changement de couleur ROUGE PRINCIPAL
        R = value;

        break;
      /////////////
      case 2 : // 2 : Changement de couleur VERT PRINCIPAL
        G = value;

        break;
      /////////////
      case 3 : // 3 : Changement de couleur BLEU PRINCIPAL
        B = value;

        break;
      /////////////
      case 4 : // 4 : Changement de MODE
        Mode = value;

        break;
      /////////////
      case 5 : // 5 : Changement de BRIGHTNESS
        BRIGHTNESS = value;

        break;
      /////////////
      case 6 : // 6 : Changement de BPM
        BPM = value;
        if (BPM != 0) {
          interval = float((float(60) / float(BPM)) * float(1000000));
        }

        break;
      /////////////
      case 7 : // 7 : Changement de DECAL increase
        incDec = map_float((float)value, 0.0, 255.0, incDecMin, incDecMax);
        break;

      case 8 : // 8 : Changement de couleur ROUGE SECONDAIRE
        RSec = value;

        break;
      /////////////
      case 9 : // 9 : Changement de couleur VERT SECONDAIRE
        GSec = value;

        break;
      /////////////
      case 10 : // 10 : Changement de couleur BLEU SECONDAIRE
        BSec = value;

        break;

      case 11 : // 11 : Changement de VITESSE
        incSpe = map_float((float)value, 0.0, 255.0, incSpeMin, incSpeMax);

        break;

    }
    noRepeat = 0;
  }
}
