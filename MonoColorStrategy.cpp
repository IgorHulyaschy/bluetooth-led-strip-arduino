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

void MonoColorStrategy::handleCommand(int numCommand) {
  RGB rgb = this->rgbs[numCommand];
  for (int i = 0; i < COUNT_OF_LEDS; i++) {
    Serial.println(i);
    this->leds[i]->update(rgb.getRed(), rgb.getGreen(), rgb.getRed(), 0);
    this->leds[i]->setColor();
  }
  this->pixelWrapper.show();
  this->isOn = true;
}

void MonoColorStrategy::off() {
  for (int i = 0; i < COUNT_OF_LEDS; i++) {
    Serial.println(i);
    this->leds[i]->update(0, 0, 0, 0);
    this->leds[i]->setColor();
  }
  Serial.println("loopppp");
  this->pixelWrapper.show();
  this->isOn = false;
}

bool MonoColorStrategy::isSetuped() {
  return this->isOn;
}