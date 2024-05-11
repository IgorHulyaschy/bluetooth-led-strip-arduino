// TODO implement

// #include "DynamicColorStrategy.h"

// DynamicColorStrategy::DynamicColorStrategy(PixelWrapper& pixelWrapper): pixelWrapper(pixelWrapper) {}

// void DynamicColorStrategy::setLeds(Led* ledsArr[NUMPIXELS]) {
//   for (int i = 0; i < NUMPIXELS; i++) {
//     this->leds[i] = ledsArr[i];
//   }
// }

// void DynamicColorStrategy::loop() {
//   if(this->isOn) return;

//   for (int i = 0; i < NUMPIXELS; i++) {
//     this->leds[i]->setColor();
//   }
//   this->pixelWrapper.show();
//   this->isOn = true;
// }

// void DynamicColorStrategy::handleCommand(int r, int g, int b) {
//   if(this->isOn) return;

//   for (int i = 0; i < NUMPIXELS; i++) {
//     this->leds[i]->update(r, g, b);
//     this->leds[i]->setColor();
//   }
// }

// void DynamicColorStrategy::setup() {}

// void DynamicColorStrategy::off() {
//   if (this->isOn) {
//     for (int i = 0; i < NUMPIXELS; i++) {
//       this->leds[i]->update(0, 0, 0);
//       this->leds[i]->setColor();
//     }
//     this->pixelWrapper.show();
//     this->isOn = false;
//   }
// }