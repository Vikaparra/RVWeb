#include "CSVParser.hpp"
#include "Metadata.hpp"
#include <fstream>
#include <functional>
#include <iostream>

Metadata *Metadata::instance = 0;

int main(int argc, char *argv[]) {
  CSVParser csvParser{argv[1]};
  Metadata *metadata = metadata->getInstance();
  std::cout << csvParser.getPath() << std::endl;

  std::string filePath = argv[1];
  std::string property = argv[2];

  metadata->setPropertyColumn(csvParser.readSpecificColumn(property));
  csvParser.generate(metadata->getPropertyColumn());

  return 0;
}
