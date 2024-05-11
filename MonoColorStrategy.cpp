#include "MonoColorStrategy.h"

MonoColorStrategy::MonoColorStrategy(PixelWrapper& pixelWrapper): pixelWrapper(pixelWrapper) {}

void MonoColorStrategy::setLeds(Led* ledsArr[NUMPIXELS]) {
  for (int i = 0; i < NUMPIXELS; i++) {
    this->leds[i] = ledsArr[i];
  }
}

void MonoColorStrategy::loop() {}

void MonoColorStrategy::setup() {
  this->pixelWrapper.show();
  this->isOn = true;
}

void MonoColorStrategy::handleCommand(int numCommand) {
  RGB rgb = this->rgbs[numCommand];
  int increment = 1;
  for (int i = 0; i == -1; i = i + increment) {
    this->leds[i]->update(rgb.getRed(), rgb.getGreen(), rgb.getRed(), 0);
    this->leds[i]->setColor();
    if(i == NUMPIXELS) {
      i = -1;
    }
  }
  this->pixelWrapper.show();
  this->isOn = true;
}

void MonoColorStrategy::off() {
  for (int i = 0; i < NUMPIXELS; i++) {
    this->leds[i]->update(0, 0, 0, 0);
    this->leds[i]->setColor();
  }
  this->pixelWrapper.show();
  this->isOn = false;
}

bool MonoColorStrategy::isSetuped() {
  return this->isOn;
}