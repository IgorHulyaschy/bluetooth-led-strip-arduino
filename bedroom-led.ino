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
Led* ledsForMono[COUNT_OF_LEDS];
PixelWrapper pixelWrapper = PixelWrapper();
Bluetooth bluetooth = Bluetooth();
RGB rgbs[7] = {
  //white
  RGB(255, 150, 100),
  // red
  RGB(255, 0, 0),
  //yellow
  RGB(246, 130, 6),
  // magenta
  RGB(139, 0, 255),
  // green
  RGB(3, 203, 17),
  //philetoviy
  RGB(255, 0, 107),
  //blue
  RGB(37, 3, 255)
};


// TODO implement
// DynamicColorStrategy dynamicColorStrategy = DynamicColorStrategy(pixelWrapper);
MonoColorStrategy monoColorStrategy = MonoColorStrategy(pixelWrapper);
// GradientStrategy* gradientStrategy = new GradientStrategy(pixelWrapper);

void setup() {
  Serial.begin(9600);
  // Initiating hm-10 module
  bluetooth.begin(9600);
  // Leds init
  for (int i = 0; i < COUNT_OF_LEDS; i++) {
    RGB rgb = RGB(0, 0, 0);
    // ledsForGradient[i] = new Led(i, rgb, pixelWrapper);
    ledsForMono[i] = new Led(i, rgb, pixelWrapper);
  }
  // Strategies init
  monoColorStrategy.setLeds(ledsForMono);
  // gradientStrategy->setLeds(ledsForGradient);
  // dynamicColorStrategy.setLeds(leds);
  // Leds strip lib init
  // initiateTimer();
  pixelWrapper.begin();
}

void loop() {
	char command = bluetooth.read();
  if(command != '\0') {
    bluetooth.waitForNextCommand(); 
    Serial.println(command);
    switch (command) {
      case '0':
        // gradientStrategy->off();
        monoColorStrategy.off();
        break;
      // case '8':
      //   if(!gradientStrategy->isSetuped()) {
      //     monoColorStrategy.off();
      //     gradientStrategy->setup();
      //   }
      //   break;
      default:
        Serial.println("here");
        // gradientStrategy.off();
        Serial.println("here1");
        int index = command - '0';
        RGB cursor = rgbs[index-1];
        monoColorStrategy.handleCommand(cursor.getRed(), cursor.getGreen(), cursor.getBlue());
        break;
    }
  }
  // if(gradientStrategy->isSetuped()) {
  //   gradientStrategy->loop();
  // }
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
