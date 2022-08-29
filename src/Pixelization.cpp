#include "Pixelization.hpp"

std::map<int, std::vector<double>> Pixelization::generatePixelizatedMatrix(
    std::map<int, std::vector<double>> data) {

  std::map<int, std::vector<double>> map;
  std::vector<double> temporary;
  std::map<int, std::vector<double>>::iterator itr = data.begin();

  for (int i = 0; i < itr->second.size(); i++) {
    for (const auto &pair : data) {
      temporary.push_back(pair.second.at(i));
    }
    map.insert({i, temporary});
    temporary.clear();
  }
  return map;
}

void Pixelization::setCurve(std::string curve) {
  if (curve.compare("snakecurve") == 0) {
    this->curve = SnakeCurve{bf->getNumOfModels()};
  }
}
