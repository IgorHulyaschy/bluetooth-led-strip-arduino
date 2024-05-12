#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "global-vars.h"
#include "RGB.h"
#include "Bluetooth.h"
#include "Led.h"
#include "PixelWrapper.h"
#include "DynamicColorStrategy.h"
#include "MonoColorStrategy.h"
#include "GradientStrategy.h"
#include "Timer.h"

PixelWrapper pixelWrapper = PixelWrapper();

Bluetooth bluetooth = Bluetooth();
MonoColorStrategy monoColorStrategy = MonoColorStrategy(pixelWrapper);
GradientStrategy gradientStrategy = GradientStrategy(pixelWrapper);

// TODO implement
// DynamicColorStrategy dynamicColorStrategy = DynamicColorStrategy(pixelWrapper);

void setup() {
  Serial.begin(9600);
  // Initiating hm-10 module
  bluetooth.begin(9600);

  gradientStrategy.initLeds();
  // // dynamicColorStrategy.setLeds(leds);
  // // Leds strip lib init
  initiateTimer();
  pixelWrapper.begin();
}

void loop() {
	char command = bluetooth.read();
  if(command != '\0') {
    switch (command) {
      case '0':
        gradientStrategy.off();
        monoColorStrategy.off();
        break;
      case '8':
        monoColorStrategy.off();
        if(!gradientStrategy.isSetuped()) {
          gradientStrategy.setup();
        }
        break;
      default:
        int index = command - '0';
        gradientStrategy.off();
        monoColorStrategy.handleCommand(index-1);
        break;
    }
  }

  if(gradientStrategy.isSetuped()) {
    gradientStrategy.loop();
  }
}

// TODO implement

// RGB parseRGB(String command) {
//   // Because command starts with R
//   String red = command.substring(1, command.indexOf(";"));
//   command = command.substring(command.indexOf(";") + 1);
//   String green = command.substring(0, command.indexOf(";"));
//   command = command.substring(command.indexOf(";") + 1);
//   String blue = command.substring(0, command.indexOf(";"));
//   Serial.println("red " + red);
//   Serial.println("gr " + green);
//   Serial.println("gr " + blue);
//   return RGB(red.toInt(), green.toInt(), blue.toInt());
// }
