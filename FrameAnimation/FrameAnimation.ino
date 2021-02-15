/*
  NeoPixel Arrays Spark Challenge
  Cameron Acton
*/

//Hello World Test for an 8x8 NeoPixel array
//This test was designed to make a simple animation using a multi-dimensional array to address each pixel of the matrix
//This animation depicts a simple frog bouncing into and out of frame, causing a splash  

#include <Adafruit_NeoPixel.h>
#include "frames.h"

Adafruit_NeoPixel strip(64, 6);

int frame = 0;

int colors[4][3] {
  {0, 0, 0}, 
  {0, 255, 0},
  {0, 0, 255},
  {0, 255, 255}
};

void setup() {
  strip.begin();
  strip.clear();

  strip.setBrightness(25);
}

void loop() {
  for (int i = 0; i < strip.numPixels(); i++) {
    int whichCol = animation[frame][i];
    
    int r = colors[whichCol][0];
    int g = colors[whichCol][1]; 
    int b =  colors[whichCol][2];
    
    strip.setPixelColor(i, r, g, b);
  }
  strip.show();

  frame = (frame + 1) % 6;
  delay(500);
}
