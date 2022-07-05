#include "CSVParser.hpp"
#include <algorithm>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>
// TODO: serialize the vector

std::vector<double> CSVParser::readFile(const std::string &pathToCsv) {
  std::ifstream input{pathToCsv};

  // Check if the file is open
  if (!input.is_open()) {
    throw std::runtime_error("Could not open file");
  }

  while (getline(input, this->line, ';')) {
    std::istringstream iss{this->line};
    std::vector<std::string> results{std::istream_iterator<std::string>(iss),
                                     std::istream_iterator<std::string>()};
    for (auto &result : results) {

      std::stringstream ss(result);
      ss >> this->value;
      ss.str() == "NaN" ? addToVector(std::numeric_limits<double>::quiet_NaN())
                        : addToVector(this->value);
    }
  }

  // Close the file
  input.close();
  return getVector();
}

int CSVParser::getHeader(const std::string &pathToCsv,
                         std::string desiredHeader) {
  std::ifstream input{pathToCsv};
  int count = 0;

  while (getline(input, this->line, ';')) {
    std::istringstream ss{this->line};
    ss >> this->property;
    if (this->property.compare(desiredHeader) == 0) {
      return count;
    }
    count++;
  }

  return -1;
}

std::vector<double> CSVParser::readSpecificColumn(const std::string &pathToCsv,
                                                  std::string column) {
  int rowNumber = this->getHeader(pathToCsv, column);
  std::ifstream input{pathToCsv};

  // Check if the file is open. If so, get rid of the header of the file;
  !input.is_open() ? throw std::runtime_error("Could not open file")
                   : getline(input, this->line);

  while (getline(input, this->line)) {
    std::istringstream ss{this->line};
    std::vector<double> temp;

    for (int i = 0; i <= rowNumber; i++) {
      std::string result;
      std::getline(ss, result, ';');
      std::stringstream ss(result);
      ss >> this->value;
      result.compare("NaN") == 0
          ? temp.push_back(std::numeric_limits<double>::quiet_NaN())
          : temp.push_back(this->value);
    }

    addToVector(temp[rowNumber]);
    temp.clear();
  }

  input.close();
  return getVector();
}

void CSVParser::printVector(const std::vector<double> &vector) {
  for (auto &i : vector) {
    std::cout << i << " " << std::endl;
  }
  std::cout << std::endl;
}
