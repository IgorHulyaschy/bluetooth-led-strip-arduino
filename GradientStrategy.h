// #pragma once
// #ifndef GRADIENT_STRATEGY_H
// #define GRADIENT_STRATEGY_H

// #include <Arduino.h>

// #include "global-vars.h"
// #include "Timer.h"
// #include "StrategyInterface.h"
// #include "PixelWrapper.h"
// #include "Led.h"

// class GradientStrategy final : public StrategyInterface {
// public:
//   GradientStrategy(PixelWrapper& pixelWrapper);

//   bool isSetuped() override;
//   void off() override;
//   void setup() override;
//   void loop() override;
//   void handleCommand(int r, int g, int b) override;
//   void generateGradientColor(float position);
//   void setLeds(Led* ledsArr[COUNT_OF_LEDS]) override;

//   virtual ~GradientStrategy() override = default;
// private:
//   bool isSetupDone = false;
//   float step = 0.0025;
//   PixelWrapper& pixelWrapper;
//   Led* leds[COUNT_OF_LEDS];
//   int rd = 0;
//   int gr = 0;
//   int bl = 0;
// };

// #endif