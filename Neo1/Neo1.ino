/*
NeoPixel Arrays Spark Challenge
Cameron Acton
*/

//Hello World Test for an 8x8 NeoPixel array
//This test was designed to turn on a single LED

#include <Adafruit_NeoPixel.h>

//NeoPixel strip init
const int stripPin = 6;
Adafruit_NeoPixel strip(64, stripPin);
 
void setup() {
  strip.begin();
  strip.clear();

  strip.setBrightness(50);
}

void loop() {
  strip.setPixelColor(0, 255, 0, 255);
  strip.show();
}
