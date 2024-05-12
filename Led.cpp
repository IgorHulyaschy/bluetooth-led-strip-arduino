#include "Led.h"

Led::Led() : ledNumber(0), executeAt(0) {}

Led::Led(int ledNumber, unix executeAt)
    : ledNumber(ledNumber), executeAt(executeAt) {}

int Led::getNum() {
  return this->ledNumber;
}

void Led::updateExecuteAt(unix time) {
  this->executeAt = time;
}

unix Led::getTime() {
  return this->executeAt;
}

bool Led::checkTime(unix now) {
  return now >= this->executeAt;
}
