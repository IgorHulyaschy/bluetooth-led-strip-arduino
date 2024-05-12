#include "Bluetooth.h"

void Bluetooth::begin(int baudRate) {
  this->HM10.begin(baudRate);
};

char Bluetooth::read() {
  if(this->HM10.available() > 0) {
    char c = this->HM10.read();
    return c;
  }
  return '\0';
};

void Bluetooth::waitForNextCommand() {
  this->isFullCommand = false;
}