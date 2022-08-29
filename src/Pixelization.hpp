#include "Metadata.hpp"
#include "SnakeCurve.hpp"
#include <array>
#include <iostream>
#include <iterator>
#include <vector>

#ifndef RVWEB_PIXELIZATION_H
#define RVWEB_PIXELIZATION_H

class Pixelization {
private:
  Metadata *bf = bf->getInstance();
  AbstractCurve curve;
  std::vector<std::vector<double>> pixelizatedMatrix;

public:
  void setCurve(std::string curve);
  // std::vector<std::vector<double>>
  std::map<int, std::vector<double>>
  generatePixelizatedMatrix(std::map<int, std::vector<double>> data);
};

#endif
