#ifndef LED_H
#define LED_H

#include <Arduino.h>

#include "PixelWrapper.h"
#include "RGB.h"
// #include "Timer.h"


class Led {
public:
  Led(int ledNumber, RGB color, PixelWrapper& pixelLib);

  void setColor();
  void update(int r, int g, int b);
  // unix getTime();
  void show();
  bool isOff();
  RGB getColor();
  // bool checkTime(unix now);

private:
  RGB color;
  PixelWrapper& pixelLib;
  int ledNumber;
  // unix executeAt;
};

#endif