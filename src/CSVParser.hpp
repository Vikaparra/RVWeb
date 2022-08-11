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

class CSVParser {
private:
  Metadata *bf = bf->getInstance();
  std::string path;
  std::string line;
  char separator;
  double *nullValue = NULL;
  double value;

public:
  CSVParser(std::string path, char separator = ';') {
    this->path = path;
    this->separator = separator;
  }

  // Get the number of the desired column
  std::vector<int> getHeader(const std::vector<std::string> &desiredHeaders);

  // Get path
  std::string getPath() { return this->path; }

  // Get the desired column
  void readSpecificColumn(std::vector<std::string> &column,
                          std::vector<std::vector<double>> *vector);

  // Create a new .csv file
  void generate(const std::vector<std::vector<double>> &data);
};

#endif // RVWEB_CSVPARSER_H
