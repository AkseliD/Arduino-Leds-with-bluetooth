void analyseSerie() {
  mySerial.println("Traitement de message");

  //-------------------------------------------------------------------------BPM
  if (string.indexOf("BPM=") > -1) { //Nouveau BPM
    mySerial.println("nouveau BPM...");
    string.remove(0, 4);
    BPM = string.toInt();
    if (BPM < 1) {
      BPM = 1;
    }
    if (BPM > 255) {
      BPM = 255;
    }

    valueToPins((uint8_t)BPM); //Transmission à l'arduino...
    paramToPins((uint8_t)6);
    resetPins();

    mySerial.println("fin nouveau BPM...");
    string = "";
  }

  //-------------------------------------------------------------------------BRIGHTNESS
  if (string.indexOf("BRI=") > -1) { //Nouvelle brightness
    mySerial.println("nouvelle luminosité...");
    string.remove(0, 4);
    BRIGHTNESS = string.toInt();
    BRIGHTNESS = abs(BRIGHTNESS);
    if (BRIGHTNESS > 255) {
      BRIGHTNESS = 255;
    }

    mySerial.print("Luminosite : ");
    mySerial.println(BRIGHTNESS);

    valueToPins((uint8_t)BRIGHTNESS); //Transmission à l'arduino...
    paramToPins((uint8_t)5);
    resetPins();

    mySerial.println("fin nouvelle luminosité...");
    string = "";
  }

  //-------------------------------------------------------------------------DEC
  if (string.indexOf("DEC=") > -1) { //Nouvelle brightness
    mySerial.println("nouveau decalage...");
    string.remove(0, 4);
    incDec = string.toInt();
    incDec = abs(incDec);
    if (incDec > 255) {
      incDec = 255;
    }

    mySerial.print("incDec : ");
    mySerial.println(incDec);

    mySerial.print("sera reçu : ");
    mySerial.println(map_float((float)incDec, 0.0, 255.0, incDecMin, incDecMax));

    valueToPins((uint8_t)incDec); //Transmission à l'arduino...
    paramToPins((uint8_t)7);
    resetPins();

    mySerial.println("fin nouvelle luminosité...");
    string = "";
  }

  //-------------------------------------------------------------------------SPEED
  if (string.indexOf("SPE=") > -1) { //Nouvelle speed
    mySerial.println("nouvelle vitesse...");
    string.remove(0, 4);
    incSpe = string.toInt();
    incSpe = abs(incSpe);
    if (incSpe > 255) {
      incSpe = 255;
    }

    mySerial.print("incSpe : ");
    mySerial.println(incSpe);

    mySerial.print("sera reçu : ");
    mySerial.println(map_float((float)incSpe, 0.0, 255.0, incSpeMin, incSpeMax));

    valueToPins((uint8_t)incSpe); //Transmission à l'arduino...
    paramToPins((uint8_t)11);
    resetPins();

    mySerial.println("fin nouvelle vitesse...");
    string = "";
  }

  //-------------------------------------------------------------------------MODE
  if (string.indexOf("MOD=") > -1) { //Mode sélectionné
    string.remove(0, 4);
    mySerial.println("nouveau mode...");
    if (string.indexOf("fi") > -1) {
      Mode = 1;
      mySerial.println("   --- Mode constant");
    }
    if (string.indexOf("me") > -1) {
      Mode = 2;
      mySerial.println("   --- Mode metronome");
    }
    if (string.indexOf("rf") > -1) {
      Mode = 3;
      mySerial.println("   --- Mode RGB fixe");
    }
    if (string.indexOf("rw") > -1) {
      Mode = 4;
      mySerial.println("   --- Mode RGB wave");
    }
    if (string.indexOf("off") > -1) {
      Mode = 5;
      mySerial.println("   --- Au revoir !");
    }
    if (string.indexOf("pbc") > -1) {
      Mode = 6;
      mySerial.println("   --- Mode pulse between colors");
    }
    valueToPins((uint8_t)Mode); //Transmission à l'arduino...
    paramToPins((uint8_t)4);
    resetPins();

    mySerial.println("fin nouveau mode");
    string = "";
  }

  //-------------------------------------------------------------------------COLOR (MANUALLY)
  if (string.indexOf("COLS") > -1) {
    mySerial.println("Nouvelle couleur");
    String strR = "";
    String strG = "";
    String strB = "";
    char z;

    mySerial.println("   Valeur R ?");
    while (z != 'R') {
      if (mySerial.available() > 0) {
        z = mySerial.read();
        if (z != 'R') strR += z;
      }
    }
    R = strR.toInt();
    mySerial.print("   Rouge : ");
    mySerial.println(R);

    mySerial.println("   Valeur G ?");
    while (z != 'G') {
      if (mySerial.available() > 0) {
        z = mySerial.read();
        if (z != 'G') strG += z;
      }
    }
    G = strG.toInt();
    mySerial.print("   Vert : ");
    mySerial.println(G);

    mySerial.println("   Valeur B ?");
    while (z != 'B') {
      if (mySerial.available() > 0) {
        z = mySerial.read();
        if (z != 'B') strB += z;
      }
    }
    B = strB.toInt();
    mySerial.print("   Bleu : ");
    mySerial.println(B);

    valueToPins((uint8_t)R); //Transmission à l'arduino...
    paramToPins((uint8_t)1);
    resetPins();

    valueToPins((uint8_t)G); //Transmission à l'arduino...
    paramToPins((uint8_t)2);
    resetPins();

    valueToPins((uint8_t)B); //Transmission à l'arduino...
    paramToPins((uint8_t)3);
    resetPins();
    mySerial.print("   Rouge : ");
    mySerial.println(R);
    mySerial.println("fin nouvelle couleur saisie manuelle");
    string = "";
  }
  //-------------------------------------------------------------------------COLOR (ALL AT ONCE)
  if (string.indexOf("PCOL=") > -1 || string.indexOf("SCOL=") > -1) { //nouvelle couleur (ex : COL=255R125G10B)
    bool k;
    if(string.indexOf("PCOL=") > -1) k = 0; //Couleur principale ?
    if(string.indexOf("SCOL=") > -1) k = 1; //Couleur secondaire ?
    
    string.remove(0, 5); //Enleve "XCOL=" et garde le reste
    mySerial.print("Trame de couleurs : ");
    mySerial.println(string);
    
    //string = "255R125G10B"
    String strR = "";
    String strG = "";
    String strB = "";
    mySerial.println("nouvelle couleur...");

    strR = string; //doit devenir "255R"
    strG = string; //doit devenir "125G"
    strB = string; //doit devenir "10B"


    if (strR.indexOf("R") > - 1) {
      int index = strR.indexOf("R"); //retourne la position du R (3)
      strR.remove(index, strR.length() - index); //enleve à partir de la 3eme pos 11-3=8chars
      mySerial.print("rouge :");
      R = strR.toInt();
      mySerial.println(R);
    }


    if (strG.indexOf("G") > - 1) {
      strG.remove(0, strR.length() + 1); //On enlève la chaîne rouge (255R)
      int index = strG.indexOf("G"); //On regarde où est le G (3)
      strG.remove(index, strG.length() - index); //On enleve 7-3=4chars à partir du 3eme
      mySerial.print("vert :");
      G = strG.toInt();
      mySerial.println(G);
    }


    if (strB.indexOf("B") > - 1) {
      strB.remove(0, strR.length() + 1 + strG.length() + 1);
      int index = strB.indexOf("B");
      strB.remove(index, strB.length() - index);
      mySerial.print("bleu :");
      B = strB.toInt();
      mySerial.println(B);
    }

    valueToPins((uint8_t)R); //Transmission à l'arduino...
    paramToPins((uint8_t)1 + (k*7)); //+7 au cas où c'est la couleur secondaire
    resetPins();

    valueToPins((uint8_t)G); //Transmission à l'arduino...
    paramToPins((uint8_t)2+ (k*7)); //+7 au cas où c'est la couleur secondaire
    resetPins();

    valueToPins((uint8_t)B); //Transmission à l'arduino...
    paramToPins((uint8_t)3+ (k*7)); //+7 au cas où c'est la couleur secondaire
    resetPins();

    mySerial.println("fin nouvelle couleur saisie entière");
  }
  string = "";
  noRepeat = 0;
}
