#include <SoftwareSerial.h>

//Variables BLUETOOTH
SoftwareSerial mySerial(11, 10); //RX, TX
char c;
String string = "";

//Variables Tempos
unsigned long currentMillisTransmition = 0;
unsigned long previousMillisTransmition = 0;

//Variables PIN digital
//Value Pins (VPx)
const unsigned short VP1 = 2;
const unsigned short VP2 = 3;
const unsigned short VP3 = 4;
const unsigned short VP4 = 5;
const unsigned short VP5 = 6;
const unsigned short VP6 = 7;
const unsigned short VP7 = 8;
const unsigned short VP8 = 9;

//Parameter Pins (PPx)
const unsigned short PP1 = A1;
const unsigned short PP2 = A2;
const unsigned short PP3 = A3;
const unsigned short PP4 = A4;

//Variables couleurs
int R = 255, G = 0, B = 0;
int BRIGHTNESS = 255;
float decal = 0.0;
int incDec = 0.0;
const float incDecMin = 0.2;
const float incDecMax = 5.0;
float spe = 0.0;
float incSpe = 0.0;
const float incSpeMin = 0.0;
const float incSpeMax = 5.0;

//Modes
unsigned int Mode = 1;
bool noRepeat = 0;
int BPM = 60;


void setup() {
  mySerial.begin(38400); // Default communication rate of the Bluetooth module

  pinMode(VP1, OUTPUT);
  pinMode(VP2, OUTPUT);
  pinMode(VP3, OUTPUT);
  pinMode(VP4, OUTPUT);
  pinMode(VP5, OUTPUT);
  pinMode(VP6, OUTPUT);
  pinMode(VP7, OUTPUT);
  pinMode(VP8, OUTPUT);

  pinMode(PP1, OUTPUT);
  pinMode(PP2, OUTPUT);
  pinMode(PP3, OUTPUT);
  pinMode(PP4, OUTPUT);

  resetPins();
  
  mySerial.write("setup done...");
}

void loop() {
  testSerie();
}

float map_float(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
