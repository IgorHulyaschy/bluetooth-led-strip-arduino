#ifndef LED_H
#define LED_H

#include <Arduino.h>

#include "PixelWrapper.h"
#include "RGB.h"
#include "Timer.h"


class Led {
public:
  Led();
  Led(int ledNumber, unix executeAt, RGB* color);

  void update(int r, int g, int b, unix time);
  unix getTime();
  bool isOff();
  int getNum();
  bool checkTime(unix now);

private:
  RGB* color;
  int ledNumber;
  unix executeAt;
};

#endif