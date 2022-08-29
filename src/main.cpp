#include "CSVParser.hpp"
#include "Metadata.hpp"
#include "Pixelization.hpp"
#include "SnakeCurve.hpp"
#include <fstream>
#include <functional>
#include <iostream>

Metadata *Metadata::instance = 0;

int main(int argc, char *argv[]) {
  CSVParser csvParser{argv[1]};
  Metadata *bf = bf->getInstance();
  Pixelization pixelize;
  std::string filePath = argv[1];
  std::string property = argv[2];

  std::vector<std::vector<double>> data;
  std::vector<double> vector;

  bf->setPropertyColumn(csvParser.readSpecificColumn(property));
  csvParser.generate(bf->getPropertyColumn());

  bf->map();

  std::map<int, std::vector<double>> test =
      pixelize.generatePixelizatedMatrix(bf->getMap());

  for (const auto &pair : test) {
    std::cout << pair.first << ": ";
    for (const auto &value : pair.second) {
      std::cout << value << " - ";
    }
    std::cout << pair.second.size() << std::endl;
  }

  return 0;
}
