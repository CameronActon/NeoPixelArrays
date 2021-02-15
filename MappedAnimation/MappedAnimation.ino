/*
  NeoPixel Arrays Spark Challenge
  Cameron Acton
*/

//Hello World Test for an 8x8 NeoPixel array
//This test was designed to make a simple mapped animation using a multi-dimensional array to address each pixel of the matrix
//This animation was contrained to a simple star-shaped cardboard overlay on top of the matrix

#include <Adafruit_NeoPixel.h>
#include "frames.h"

Adafruit_NeoPixel strip(64, 6);

int frame = 0;

int colors[4][3] {
  {255, 255, 0},
  {255, 255, 255},
  };

void setup() {
  strip.begin();
  strip.clear();

  strip.setBrightness(25);
}

void loop() {
  for (int i = 0; i < strip.numPixels(); i++) {
    int pixAddress = pixelMap[i];
    int whichCol = animation[frame][i];

    int r = colors[whichCol][0];
    int g = colors[whichCol][1];
    int b = colors[whichCol][2];

    if (pixAddress != -1) {
      strip.setPixelColor(pixAddress, r, g, b);
    }
  }
  strip.show();
  delay(500);
  frame = (frame + 1) % 6;

}
