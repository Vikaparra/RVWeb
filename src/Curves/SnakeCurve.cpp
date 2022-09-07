#include "SnakeCurve.hpp"

std::vector<std::vector<double>> AbstractCurve::generateTraversedMatrix(
    std::vector<std::vector<double>> &originalMatrix) {
  for (int i = 0; i < this->dimension.getX(); i++) {
    if (i % 2 != 0) {
      std::reverse(originalMatrix.at(i).begin(), originalMatrix.at(i).end());
    }
  }
  return originalMatrix;
}
