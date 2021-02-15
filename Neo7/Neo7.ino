/*
  NeoPixel Arrays Spark Challenge
  Cameron Acton
*/

//Hello World Test for an 8x8 NeoPixel array
//This test was designed to make every other NeoPixel of the matrix turn on in a Checkerboard fashion

#include <Adafruit_NeoPixel.h>

//NeoPixel strip init
const int stripPin = 6;
Adafruit_NeoPixel strip(64, stripPin);

bool empty = true;

void setup() {
  strip.begin();
  strip.clear();

  strip.setBrightness(10);
}

void loop() {
  for (int i = 0; i < strip.numPixels(); i++) {
      empty = !empty;

    if (i % 8 == 0) {
      empty = !empty;
    }
    
    if (empty) {
      strip.setPixelColor(i, 255, 0, 255);
    } else {
      strip.setPixelColor(i, 0, 0, 0);
    }
  
  }
  strip.show();
}
