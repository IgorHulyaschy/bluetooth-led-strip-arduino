#ifndef LED_H
#define LED_H

#include <Arduino.h>

#include "PixelWrapper.h"
#include "Timer.h"


class Led {
public:
  Led();
  Led(int ledNumber, unix executeAt);

  void updateExecuteAt(unix time);
  unix getTime();
  int getNum();
  bool checkTime(unix now);

private:
  int ledNumber;
  unix executeAt;
};

#endif