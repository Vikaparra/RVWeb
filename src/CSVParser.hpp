//
// Created by izael on 4/14/22.
//
#include "Metadata.hpp"
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#ifndef RVWEB_CSVPARSER_H
#define RVWEB_CSVPARSER_H

class CSVParser
{
private:
  Metadata *bf = bf->getInstance();
  char separator;
  double value;
  double *nullValue = NULL;
  std::string line;

public:
  // Get the number of the desired column
  int getHeader(const std::string &pathToCsv, std::string desiredHeader);
  // Print the generated vector
  void printVector(const std::vector<double> &vector);
  // Add a value to the row
  void addToVector(std::vector<double> &vector, double value) { vector.push_back(value); }
  // Getter for row
  std::vector<double> getVector(std::vector<double> vector) { return vector; }
  // Get the desired column
  void readSpecificColumn(const std::string &pathToCsv, std::string column, std::vector<double> *vector);
};

#endif // RVWEB_CSVPARSER_H
