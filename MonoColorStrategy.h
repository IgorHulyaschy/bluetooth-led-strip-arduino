#ifndef MONO_COLOR_STRATEGY_H
#define MONO_COLOR_STRATEGY_H

#include "global-vars.h"
#include "Led.h"
#include "RGB.h"
#include "PixelWrapper.h"
#include "StrategyInterface.h"

class MonoColorStrategy final : public StrategyInterface {
  public:
  MonoColorStrategy(PixelWrapper& pixelWrapper);

  void loop() override;
  void setup() override;
  void off() override;
  bool isSetuped() override;
  void setLeds(Led* leds[NUMPIXELS]) override;
  void handleCommand(int numCommand) override;

  virtual ~MonoColorStrategy() = default;
  private:
  PixelWrapper& pixelWrapper;
  Led* leds[NUMPIXELS];
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