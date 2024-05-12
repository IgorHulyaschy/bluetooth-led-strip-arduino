#ifndef MONO_COLOR_STRATEGY_H
#define MONO_COLOR_STRATEGY_H

#include "global-vars.h"
#include "Led.h"
#include "RGB.h"
#include "PixelWrapper.h"

class MonoColorStrategy {
  public:
  MonoColorStrategy(PixelWrapper& pixelWrapper);

  void loop();
  void setup();
  void off();
  bool isSetuped();
  void handleCommand(int numCommand);

  private:
  PixelWrapper& pixelWrapper;
  bool isOn = false;
  RGB rgbs[7] = {
    //white
    RGB(255, 150, 100),
    // red
    RGB(255, 0, 0),
    //yellow
    RGB(246, 130, 6),
    // magenta
    RGB(139, 0, 255),
    // green
    RGB(3, 203, 17),
    //philetoviy
    RGB(255, 0, 107),
    //blue
    RGB(37, 3, 255)
  };
};

#endif