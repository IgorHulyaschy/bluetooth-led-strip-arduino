#include "Led.h"

Led::Led(int ledNumber, RGB color, PixelWrapper& pixelLib)
    : ledNumber(ledNumber), color(color), pixelLib(pixelLib) {}

void Led::setColor() {
  this->pixelLib.setPixelColor(ledNumber, this->color.getRed(), this->color.getGreen(), this->color.getBlue());
}

void Led::update(int r, int g, int b) {
  this->color = RGB(r, g, b);
}

void Led::show() {
  this->pixelLib.show();
}

// unix Led::getTime() {
//   return this->executeAt;
// }

bool Led::isOff() {
  return this->color.getRed() == 0 && this->color.getGreen() == 0 && this->color.getBlue() == 0;
}

RGB Led::getColor() {
  return this->color;
}

// bool Led::checkTime(unix now) {
//   return now >= this->executeAt;
// }