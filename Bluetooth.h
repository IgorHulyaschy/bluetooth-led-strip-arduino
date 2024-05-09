#pragma once
#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "global-vars.h"

class Bluetooth {
  public:
  void begin(int baudRate);
  char read();
  void waitForNextCommand();

  private:
  SoftwareSerial HM10 = SoftwareSerial(BL_TX_PIN, BL_RX_PIN);
  bool isFullCommand = false;
};

#endif