#include "AbstractCurve.hpp"
#include <algorithm>
#include <vector>

#ifndef RVWEB_SNAKECURVE_H
#define RVWEB_SNAKECURVE_H

class SnakeCurve : public AbstractCurve {
private:
  int numberOfElements{};
  Dimension dimension = defineDimension(numberOfElements);

public:
  SnakeCurve(int numberOfElements) : numberOfElements{numberOfElements} {}
  SnakeCurve(int numberOfElements, Dimension dimension)
      : numberOfElements{numberOfElements}, dimension{dimension} {}

  Dimension getDimension() { return this->dimension; }
  Dimension defineDimension(int size) { return Dimension(size, size); };

  std::vector<std::vector<double>>
  generateTraversedMatrix(std::vector<std::vector<double>> &originalMatrix);
};

#endif
