#include <Arduino.h>

#include "global-vars.h"
#include "RGB.h"
#include "Bluetooth.h"
#include "Led.h"
#include "PixelWrapper.h"
#include "DynamicColorStrategy.h"
#include "MonoColorStrategy.h"
#include "GradientStrategy.h"
#include "Timer.h"


// Led* ledsForGradient[COUNT_OF_LEDS];
Led* leds[COUNT_OF_LEDS];
Adafruit_NeoPixel adafruit_NeoPixel = Adafruit_NeoPixel(COUNT_OF_LEDS, LED_PIN);
PixelWrapper pixelWrapper = PixelWrapper(adafruit_NeoPixel);
Bluetooth bluetooth = Bluetooth();
// MonoColorStrategy monoColorStrategy = MonoColorStrategy(pixelWrapper);
GradientStrategy gradientStrategy = GradientStrategy(pixelWrapper);


// TODO implement
// DynamicColorStrategy dynamicColorStrategy = DynamicColorStrategy(pixelWrapper);

void setup() {
  Serial.begin(9600);
  // Initiating hm-10 module
  bluetooth.begin(9600);
  // Leds init
  for (int i = 0; i < COUNT_OF_LEDS; i++) {
    RGB rgb = RGB(0, 0, 0);
    // ledsForGradient[i] = new Led(i, rgb, pixelWrapper);
    leds[i] = new Led(i, 0, rgb, pixelWrapper);
  }

  // monoColorStrategy.setLeds(leds);
  gradientStrategy.setLeds(leds);
  // gradientStrategy->setLeds(ledsForGradient);
  // dynamicColorStrategy.setLeds(leds);
  // Leds strip lib init
  initiateTimer();
  pixelWrapper.begin();
}

void loop() {
	char command = bluetooth.read();
  Serial.println("loop");
  if(command != '\0') {
    switch (command) {
      case '0':
        // gradientStrategy->off();
        // monoColorStrategy.off();
        break;
      case '8':
        if(!gradientStrategy.isSetuped()) {
          // monoColorStrategy.off();
          gradientStrategy.setup();
        }
        break;
      default:
        // int index = command - '0';
        // monoColorStrategy.handleCommand(index-1);
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
