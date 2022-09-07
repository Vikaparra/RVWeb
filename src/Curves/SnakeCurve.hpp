#include "AbstractCurve.hpp"

#ifndef RVWEB_SNAKECURVE_H
#define RVWEB_SNAKECURVE_H

class SnakeCurve : public AbstractCurve {
private:
  int numberOfElements{};
  Dimension dimension = defineDimension(numberOfElements);

public:
  SnakeCurve(int numberOfElements) : AbstractCurve{numberOfElements} {}
  SnakeCurve(int numberOfElements, Dimension dimension)
      : AbstractCurve{numberOfElements, dimension} {}

  Dimension getDimension() override { return this->dimension; }
  Dimension defineDimension(int size) override {
    return Dimension(size, size);
  };
};

#endif
