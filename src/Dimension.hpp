#ifndef RVWEB_DIMENSION_H
#define RVWEB_DIMENSION_H

class Dimension {
private:
  int x;
  int y;

public:
  // Constructor
  Dimension(int x, int y) : x{x}, y{y} {}
  int getX() { return this->x; }
  int getY() { return this->y; }
};

#endif
