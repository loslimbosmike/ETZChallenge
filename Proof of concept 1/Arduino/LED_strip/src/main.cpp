#include <Arduino.h>
#include <FastLED.h>
#include <SoftwareSerial.h>

#define NUM_LEDS 60
#define DATA_PIN 7
#define COLOR_ORDOR GRB
#define STRIP_TYPE WS2812B

#define ENDCHAR '#'


CRGBArray<NUM_LEDS> leds;
SoftwareSerial userInput (10,11);


void readMessage();

typedef enum
{
  Wave,
  Flash,
  Red,
  Green,
  Blue,
  Even,
  Odd,
  None
}Commands;


void setup (){

  FastLED.addLeds<STRIP_TYPE,DATA_PIN,COLOR_ORDOR>(leds, NUM_LEDS);
  FastLED.setBrightness(59);

  Serial.begin(9600);

  userInput.begin(115200);
}

void loop (){
  readMessage();
}

void readMessage(){

  int buffer;
  int msg;
  int backwards = NUM_LEDS -1;
  

   while (userInput.available() > 0){
     buffer = userInput.read();
     msg = buffer;
     Serial.println(msg);
   }

  switch(msg)
  {
    case 0:
      for(int i = 0; i < NUM_LEDS; i++){
      leds[i] = CRGB(0,255,0);
      FastLED.show();
      delay(200);
    }
    for(int i = NUM_LEDS; i >= 0; i--){
      leds[i] = CRGB(255,0,0);
      FastLED.show();
      delay(200);
    }
    break;
  case 1:
    for (int j = 0; j < 20; j++){
      fill_solid(leds, NUM_LEDS, CRGB(255,255,255));
      FastLED.show();
      delay(1000);
      fill_solid(leds, NUM_LEDS, CRGB(0,0,0));
      FastLED.show();
    }
  break;
  case 2:
    fill_solid(leds, NUM_LEDS, CRGB(255,0,0));
    FastLED.show();
    break;
  case 3:
    fill_solid(leds, NUM_LEDS, CRGB(0,255,0));
    FastLED.show();
    break;
  case 4:
    fill_solid(leds, NUM_LEDS, CRGB(0,0,255));
    FastLED.show();
    break;
  case 5:
    if (NUM_LEDS % 2 == 0){
      for(int i = 1; i < NUM_LEDS; i += 2){
        leds[i] = CRGB(0,255,0);
        FastLED.show();
        delay(200);
      }
      for(int i = backwards; i > 0; i -= 2){
        leds[i] = CRGB(255,0,0);
        FastLED.show();
        delay(200);
      }
    }
    break;
  case 6:
    if (!NUM_LEDS % 2 == 0){
      for(int i = 0; i < NUM_LEDS; i += 2){
        leds[i] = CRGB(0,255,0);
        FastLED.show();
        delay(200);
      }
      for(int i = NUM_LEDS; i > 0; i -= 2){
        leds[i] = CRGB(255,0,0);
        FastLED.show();
        delay(200);
      }
    }
    break;
  case 7:
    fill_solid(leds, NUM_LEDS, CRGB(0,0,0));
    FastLED.show();
    break;
  }
}