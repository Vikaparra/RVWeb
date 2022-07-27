#include "CSVParser.hpp"
#include "Metadata.hpp"
#include <functional>
#include <iostream>
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

Metadata *Metadata::instance = 0;

int main(int argc, char *argv[])
{
  CSVParser csvParser;
  Metadata *bf = bf->getInstance();
  std::string filePath = argv[1];
  // std::string column = argv[2];

  std::vector<std::vector<double>> data;
  std::vector<double> vector;

  // Tests
  csvParser.readSpecificColumn(filePath, "I", &vector);
  bf->addToMatrix(vector);
  vector.clear();

  csvParser.readSpecificColumn(filePath, "J", &vector);
  bf->addToMatrix(vector);
  vector.clear();

  csvParser.readSpecificColumn(filePath, "ArithmeticMean", &vector);
  bf->addToMatrix(vector);
  vector.clear();

  // Generate .csv file
  csvParser.generate(bf->getData());

  return 0;
};
