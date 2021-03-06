/*
  NeoPixel Arrays Spark Challenge
  Cameron Acton
*/

//Hello World Test for an 8x8 NeoPixel array
//This test was designed to make the entire matrix of LEDs turn on sequentially, then turn off sequentially

#include <Adafruit_NeoPixel.h>

//NeoPixel strip init
const int stripPin = 6;
Adafruit_NeoPixel strip(64, stripPin);

bool empty;

void setup() {
  strip.begin();
  strip.clear();

  strip.setBrightness(50);
}

void loop() {
  for (int i = 0; i < strip.numPixels(); i++) {
    if (empty) {
      strip.setPixelColor(i, 255, 0, 255);
    } else {
      strip.setPixelColor(i, 0, 0, 0);
    }
    delay(30);
    strip.show();
  }
  empty = !empty;
}
