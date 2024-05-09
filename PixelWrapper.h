#ifndef PIXEL_WRAPPER_H
#define PIXEL_WRAPPER_H

#include <Adafruit_NeoPixel.h>
#include "global-vars.h"

class PixelWrapper {
public:
  void setPixelColor(int index, int r, int g, int b);
  void show();
  void off(int ledNumber);
  void begin();

private:
  Adafruit_NeoPixel lib = Adafruit_NeoPixel(COUNT_OF_LEDS, LED_PIN);
};

#endif