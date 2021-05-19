#include <FastLED.h>
#include <EEPROM.h>

//Donnees LEDS
const int NUM_LEDS = 150;
const int LPin = 12;
CRGB leds[NUM_LEDS];

//Variables Tempos
unsigned long previousMicrosON = 0;
unsigned long previousMicrosOFF = 0;
unsigned long currentMicrosOFF = 0;
unsigned long currentMicrosON = 0;
float interval = 0;

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
uint8_t R, G, B, RSec, GSec, BSec;
int BRIGHTNESS = 255;
float decal = 0.0;
float incDec = 0.0;
const float incDecMin = 0.2;
const float incDecMax = 1.75;
float spe = 0.0;
float incSpe = 0.0;
const float incSpeMin = 0.0;
const float incSpeMax = 2.0;

//Modes
unsigned int Mode = 1;
//BPM
bool LedActive = 1;
int BPM = 60;

//Repetition actions
bool noRepeat = 0;
bool noReRead = 0;

//Receptions arduino
uint8_t Parametre;
uint8_t Value;

void setup() {
  FastLED.addLeds<WS2812B, LPin, GRB>(leds, NUM_LEDS);
  FastLED.showColor(CRGB::Black);

  //Serial.begin(38400);

  pinMode(VP1, INPUT);
  pinMode(VP2, INPUT);
  pinMode(VP3, INPUT);
  pinMode(VP4, INPUT);
  pinMode(VP5, INPUT);
  pinMode(VP6, INPUT);
  pinMode(VP7, INPUT);
  pinMode(VP8, INPUT);

  pinMode(PP1, INPUT);
  pinMode(PP2, INPUT);
  pinMode(PP3, INPUT);
  pinMode(PP4, INPUT);

  R = EEPROM.read(1);
  G = EEPROM.read(2);
  B = EEPROM.read(3);
  Mode = EEPROM.read(4);
  BRIGHTNESS = EEPROM.read(5);
  BPM = EEPROM.read(6);
  incDec = EEPROM.read(7);
  RSec = EEPROM.read(8);
  GSec = EEPROM.read(9);
  BSec = EEPROM.read(10);
  incSpe = EEPROM.read(11);

  if (BPM != 0) {
    interval = float((float(60) / float(BPM)) * float(1000000));
  }
  incDec = map_float(incDec, 0.0, 255.0, incDecMin, incDecMax);
  incSpe = map_float(incSpe, 0.0, 255.0, incSpeMin, incSpeMax);

}

void loop() {
  Parametre = paramToByte();

  if (!Parametre) {
    noReRead = 1;
  } else {
    Value = valueToByte();
    Parametre = paramToByte();

    receptArduino(Parametre, Value);
    noReRead = 0;
  }

  switch (Mode) {
    case 1:
      constant();
      break;
    case 2:
      metronome();
      break;
    case 3:
      rainbowFixe();
      break;
    case 4:
      rainbowWave();
      break;
    case 5 :
      extinction();
      break;
    case 6:
      pulseBetweenColors();
      break;
  }
  noRepeat = 1;
}

float map_float(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
