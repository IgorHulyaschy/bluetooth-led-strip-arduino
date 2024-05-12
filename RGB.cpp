#include "RGB.h"

RGB::RGB() : red(0), green(0), blue(0) {}
RGB::RGB(int red, int green, int blue): red(red), green(green), blue(blue) {}

int RGB::getRed() {
  return this->red;
}
int RGB::getGreen() {
  return this->green;
}
int RGB::getBlue() {
  return this->blue;
}

void RGB::setNewColor(int r, int g, int b) {
  this->red = r;
  this->green = g;
  this->blue = b;
}