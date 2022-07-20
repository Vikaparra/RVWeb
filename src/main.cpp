#include "CSVParser.hpp"
#include "Metadata.hpp"
#include <functional>
#include <iostream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

Metadata *Metadata::instance = 0;

int main(int argc, char *argv[])
{
  CSVParser csvParser;
  Metadata *bf = bf->getInstance();
  std::string filePath = argv[1];
  std::string column = argv[2];

  std::vector<double> vector;

  bf->setEnsembleName("Triage");

  csvParser.readSpecificColumn(filePath, "I", &vector);
  bf->setIColumn(vector);
  bf->setMaxI(vector);

  csvParser.readSpecificColumn(filePath, "J", &vector);
  bf->setJColumn(vector);
  bf->setMaxJ(vector);

  csvParser.readSpecificColumn(filePath, "Model", &vector);
  bf->setModelColumn(vector);

  // csvParser.printVector(vector);
  std::cout << "This is the last I element: " << bf->getMaxI() << std::endl;
  std::cout << "This is the last J element: " << bf->getMaxJ() << std::endl;

  std::ofstream ofs("intermediary_file.dat", std::ios::binary);

  {
    boost::archive::binary_oarchive oa(ofs);
    oa << bf;
  }

  return 0;
};
