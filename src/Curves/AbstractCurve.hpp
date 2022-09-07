#include "Dimension.hpp"
#include <algorithm>
#include <cmath>
#include <vector>

#ifndef RVWEB_ABSTRACTCURVE_H
#define RVWEB_ABSTRACTCURVE_H

class AbstractCurve {
  int numberOfElements;
  Dimension dimension;

public:
  AbstractCurve(int numberOfElements);
  AbstractCurve(int numberOfElements, Dimension dimension);
  virtual int getNumberOfElements() = 0;
  virtual Dimension getDimension() = 0;
  virtual Dimension defineDimension(int size) = 0;
  virtual std::vector<std::vector<double>>
  generateTraversedMatrix(std::vector<std::vector<double>> &originalMatrix) = 0;
};

#endif
