/*
  NeoPixel Arrays Spark Challenge
  Cameron Acton
*/

//Hello World Test for an 8x8 NeoPixel array
//This test was designed to turn the entire matrix of LEDs

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
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 255, 0, 255);
  }
  strip.show();
}
