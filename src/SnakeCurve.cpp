#include "SnakeCurve.hpp"

Dimension SnakeCurve::defineDimension(int numberOfElements) {
  int value = std::ceil(std::sqrt(numberOfElements));
  return Dimension(value, value);
}

std::vector<std::vector<double>> SnakeCurve::generateTraversedMatrix(
    std::vector<std::vector<double>> &originalMatrix) {
  for (int i = 0; i < this->dimension.getX(); i++) {
    if (i % 2 != 0) {
      std::reverse(originalMatrix.at(i).begin(), originalMatrix.at(i).end());
    }
  }
  return originalMatrix;
}
