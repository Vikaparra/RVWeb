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
  Metadata *bf = bf->getInstance();
  char separator;
  std::string path;

public:
  CSVParser(std::string path, char separator = ';') {
    this->path = path;
    this->separator = separator;
    bf->setIColumn(this->readSpecificColumn("I"));
    bf->setJColumn(this->readSpecificColumn("J"));
    bf->setModelColumn(this->readSpecificColumn("Model"));
  }

  int getHeader(std::string desiredProperty);
  void generate(const std::vector<double> &data);
  std::string getPath() { return this->path; }
  std::vector<double> readSpecificColumn(std::string column);

  // Map
  // std::map<int, std::vector<double>> generateMap();
};

#endif // RVWEB_CSVPARSER_H
