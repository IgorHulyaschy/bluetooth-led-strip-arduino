#include "MonoColorStrategy.h"

MonoColorStrategy::MonoColorStrategy(PixelWrapper& pixelWrapper): pixelWrapper(pixelWrapper) {}

void MonoColorStrategy::loop() {}

void MonoColorStrategy::setup() {
  this->pixelWrapper.show();
  this->isOn = true;
}

void MonoColorStrategy::handleCommand(int numCommand) {
  RGB rgb = this->rgbs[numCommand];
  for (int i = 0; i < NUMPIXELS; i++) {
    this->pixelWrapper.setPixelColor(i, rgb.getRed(), rgb.getGreen(), rgb.getBlue());
  }
  this->pixelWrapper.show();
  this->isOn = true;
}

void MonoColorStrategy::off() {
  for (int i = 0; i < NUMPIXELS; i++) {
    this->pixelWrapper.setPixelColor(i, 0, 0, 0);
  }
  this->pixelWrapper.show();
  this->isOn = false;
}

bool MonoColorStrategy::isSetuped() {
  return this->isOn;
}