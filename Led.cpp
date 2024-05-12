#include "Led.h"

Led::Led() : ledNumber(0), executeAt(0), color(new RGB()) {}

Led::Led(int ledNumber, unix executeAt , RGB* color)
    : ledNumber(ledNumber), executeAt(executeAt), color(color) {}

int Led::getNum() {
  return this->ledNumber;
}

void Led::update(int r, int g, int b, unix time) {
  this->color->setNewColor(r, g, b);
  this->executeAt = time;
}

unix Led::getTime() {
  return this->executeAt;
}

bool Led::checkTime(unix now) {
  return now >= this->executeAt;
}

bool Led::isOff() {
  return this->color->getRed() == 0 && this->color->getGreen() == 0 && this->color->getBlue() == 0;
}

