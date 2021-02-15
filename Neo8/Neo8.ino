/*
  NeoPixel Arrays Spark Challenge
  Cameron Acton
*/

//Hello World Test for an 8x8 NeoPixel array
//This test was designed to make the entire matrix of LEDs cycle through a smooth rainbow gradient

#include <Adafruit_NeoPixel.h>

//NeoPixel strip init
const int stripPin = 6;
Adafruit_NeoPixel strip(64, stripPin);

int color = 0;

void setup() {
  strip.begin();
  strip.clear();

  strip.setBrightness(50);
}

void loop() {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, Wheel(color));
  }
  delay(20);

  color = (color + 1) % 255;
  strip.show();
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
