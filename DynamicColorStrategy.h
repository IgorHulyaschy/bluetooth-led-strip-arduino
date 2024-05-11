// TODO implement

// #ifndef DYNAMIC_COLOR_STRATEGY_H
// #define DYNAMIC_COLOR_STRATEGY_H

// #include "global-vars.h"
// #include "Led.h"
// #include "PixelWrapper.h"
// #include "StrategyInterface.h"

// class DynamicColorStrategy final : public StrategyInterface {
//   public:
//   DynamicColorStrategy(PixelWrapper& pixelWrapper);

//   void loop() override;
//   void setup() override;
//   void off() override;
//   void setLeds(Led* ledsArr[NUMPIXELS]) override;
//   void handleCommand(int r, int g, int b) override;

//   virtual ~DynamicColorStrategy() = default;
//   private:
//   PixelWrapper& pixelWrapper;
//   Led* leds[NUMPIXELS];
//   bool isOn = false;
// };

// #endif