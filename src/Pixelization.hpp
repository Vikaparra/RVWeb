//#include "Curves/SnakeCurve.hpp"
#include "Metadata.hpp"
#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

#ifndef RVWEB_PIXELIZATION_H
#define RVWEB_PIXELIZATION_H

class Pixelization {
private:
  Metadata *bf = bf->getInstance();
  // AbstractCurve curve;
  std::vector<std::vector<double>> pixelizatedMatrix;

public:
  void setCurve(std::string curve);
  void generatePixelizatedMatrix(
      std::vector<std::vector<std::vector<double>>> &data);
  void generateFinalFile(std::map<int, std::vector<double>> &map);
};

#endif
