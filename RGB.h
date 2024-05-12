#ifndef RGB_H
#define RGB_H

class RGB {
public:
  RGB();
  RGB(int red, int green, int blue);

  int getRed();
  int getGreen();
  int getBlue();
  void setNewColor(int r, int g, int b);

private:
  int red;
  int green;
  int blue;
};
#endif