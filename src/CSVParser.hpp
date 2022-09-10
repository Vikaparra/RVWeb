//
// Created by izael on 4/14/22.
//
#include "Metadata.hpp"
#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#ifndef RVWEB_CSVPARSER_H
#define RVWEB_CSVPARSER_H

class CSVParser {
private:
  Metadata *metadata = metadata->getInstance();
  std::string path;
  std::string line;
  char separator;
  double *nullValue = NULL;
  double value;

public:
  CSVParser(std::string path, char separator = ';') {
    this->path = path;
    this->separator = separator;
    metadata->setIColumn(this->readSpecificColumn("I"));
    metadata->setJColumn(this->readSpecificColumn("J"));
    metadata->setModelColumn(this->readSpecificColumn("Model"));
  }

  // Get path
  std::string getPath() { return this->path; }

  // Get the number of the desired column
  int getHeader(std::string desiredProperty);

  // Get the desired column
  std::vector<double> readSpecificColumn(std::string column);

  // Create a new .csv file
  void generate(const std::vector<double> &data);
};

#endif // RVWEB_CSVPARSER_H
