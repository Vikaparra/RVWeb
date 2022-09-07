#include "CSVParser.hpp"
#include "Metadata.hpp"
#include "Pixelization.hpp"
#include <fstream>
#include <functional>
#include <iostream>
#include <unistd.h>

Metadata *Metadata::instance = 0;

int main(int argc, char *argv[]) {
  std::string filePath = argv[1];
  std::string fileName = argv[2];
  std::string property = argv[3];
  std::string path = filePath + fileName;

  CSVParser csvParser{path};
  Metadata *bf = bf->getInstance();
  Pixelization pixelize;

  csvParser.generate(csvParser.readSpecificColumn(property));

  bf->setIntermediaryFile(filePath + "/intermediary_file.csv");
  std::cout << filePath + "/intermediary_file" << std::endl;

  std::vector<std::vector<double>> data;
  std::vector<double> vector;

  bf->setPropertyColumn(csvParser.readSpecificColumn(property));
  csvParser.generate(bf->getPropertyColumn());

  data = bf->map();
  // bf->printMap();
  std::vector<std::vector<std::vector<double>>> test = bf->separateModel(data);
  pixelize.generatePixelizatedMatrix(test);

  // for (const auto &first : test) {
  //   std::cout << "Array: ";
  //   for (const auto &elements : first) {
  //     std::cout << elements << " - ";
  //   }
  //   std::cout << std::endl;
  // }

  //  std::map<int, std::vector<double>> test =
  //      pixelize.generatePixelizatedMatrix(bf->getMap());

  //  for (const auto &pair : test) {
  //    std::cout << pair.first << ": ";
  //    for (const auto &value : pair.second) {
  //      std::cout << value << " - ";
  //    }
  //    std::cout << pair.second.size() << std::endl;
  //  }

  return 0;
}
