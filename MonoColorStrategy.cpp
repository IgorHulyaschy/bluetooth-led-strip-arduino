#include "MonoColorStrategy.h"

MonoColorStrategy::MonoColorStrategy(PixelWrapper& pixelWrapper): pixelWrapper(pixelWrapper) {}

void MonoColorStrategy::setLeds(Led* ledsArr[COUNT_OF_LEDS]) {
  for (int i = 0; i < COUNT_OF_LEDS; i++) {
    this->leds[i] = ledsArr[i];
  }
}

void MonoColorStrategy::loop() {}

void MonoColorStrategy::setup() {
  this->pixelWrapper.show();
  this->isOn = true;
}

void MonoColorStrategy::handleCommand(int r, int g, int b) {
  Serial.println("for");

  for (int i = 0; i < COUNT_OF_LEDS; i++) {
    this->leds[i]->update(r, g, b);
    this->leds[i]->setColor();
  }
  Serial.println("setuped");
  this->pixelWrapper.show();
  this->isOn = true;
}

void MonoColorStrategy::off() {
  if (this->isOn) {
    for (int i = 0; i < COUNT_OF_LEDS; i++) {
      this->leds[i]->update(0, 0, 0);
      this->leds[i]->setColor();
    }
    this->pixelWrapper.show();
    this->isOn = false;
  }
}

bool MonoColorStrategy::isSetuped() {
  return this->isOn;
}