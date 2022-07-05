#include "CSVParser.hpp"
#include "IJKKey.hpp"
#include <functional>
#include <iostream>

int main(int argc, char *argv[]) {
  std::string filePath = argv[1];
  std::string column = argv[2];
  // std::string filePath = "/home/izael/Documents/Git/RVWeb/test/"
  // "PERMJIGUAL800_0.0_DEFAULT_MATRIX_K.csv";

  CSVParser csvParser;
  std::vector<double> vector = csvParser.readSpecificColumn(filePath, column);
  csvParser.printVector(vector);
  // IJKKey key("hey", 1312, 25123, 3554);

  return 0;
};
