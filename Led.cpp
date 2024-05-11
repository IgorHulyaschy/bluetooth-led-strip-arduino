#include "Led.h"

Led::Led(int ledNumber, long executeAt , RGB color, PixelWrapper& pixelLib)
    : ledNumber(ledNumber), executeAt(executeAt), color(color), pixelLib(pixelLib) {}

void Led::setColor() {
  this->pixelLib.setPixelColor(ledNumber, this->color.getRed(), this->color.getGreen(), this->color.getBlue());
}

int Led::getNum() {
  return this->ledNumber;
}

void Led::update(int r, int g, int b, unix time) {
  this->color = RGB(r, g, b);
  this->executeAt = time;
}

unix Led::getTime() {
  return this->executeAt;
}

void Led::show() {
  this->pixelLib.show();
}

bool Led::checkTime(unix now) {
  return now >= this->executeAt;
}

bool Led::isOff() {
  return this->color.getRed() == 0 && this->color.getGreen() == 0 && this->color.getBlue() == 0;
}

RGB Led::getColor() {
  return this->color;
}
