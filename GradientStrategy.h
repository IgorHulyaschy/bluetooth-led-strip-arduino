#ifndef GRADIENT_STRATEGY_H
#define GRADIENT_STRATEGY_H

#include <Arduino.h>

#include "global-vars.h"
#include "Timer.h"
#include "PixelWrapper.h"
#include "Led.h"

class GradientStrategy {
public:
  GradientStrategy(PixelWrapper& pixelWrapper);

  bool isSetuped();
  void off();
  void setup();
  void loop();
  void handleCommand(int numCommand);
  void generateGradientColor(float position);
  void initLeds();

private:
  bool isSetupDone = false;
  float step = 0.0025;
  PixelWrapper& pixelWrapper;
  Led leds[NUMPIXELS];
  int rd = 0;
  int gr = 0;
  int bl = 0;
};

#endif