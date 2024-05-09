#ifndef MONO_COLOR_STRATEGY_H
#define MONO_COLOR_STRATEGY_H

#include "global-vars.h"
#include "Led.h"
#include "PixelWrapper.h"
#include "StrategyInterface.h"

class MonoColorStrategy final : public StrategyInterface {
  public:
  MonoColorStrategy(PixelWrapper& pixelWrapper);

  void loop() override;
  void setup() override;
  void off() override;
  bool isSetuped() override;
  void setLeds(Led* ledsArr[COUNT_OF_LEDS]) override;
  void handleCommand(int r, int g, int b) override;

  virtual ~MonoColorStrategy() = default;
  private:
  PixelWrapper& pixelWrapper;
  Led* leds[COUNT_OF_LEDS];
  bool isOn = false;
};

#endif