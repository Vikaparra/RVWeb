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
#include <vector>

std::vector<int>
CSVParser::getHeader(const std::vector<std::string> &desiredHeaders) {
  std::ifstream input{this->path};
  std::string property;
  std::string line;
  std::vector<int> indexes;

  getline(input, line);

  for (int i = 0; i < desiredHeaders.size(); i++) {
    int count = 0;
    std::istringstream ss{line};
    while (getline(ss, property, this->separator)) {
      if (property.compare(desiredHeaders.at(i)) == 0) {
        indexes.push_back(count);
      }
      count++;
    }
  }

  return indexes;
}

// void CSVParser::readSpecificColumn(std::vector<std::string> &columns,
//                                    std::vector<double> *vector) {
//   std::vector<int> rowNumber = this->getHeader(columns);
//   std::ifstream input{this->path};

//   // Check if the file is open. If so, get rid of the header of the file;
//   !input.is_open() ? throw std::runtime_error("Could not open file")
//                    : getline(input, line);

//   while (getline(input, line)) {
//     std::istringstream ss{line};
//     std::vector<double> temp;

//     for (int i = 0; i <= rowNumber; i++) {
//       std::string result;
//       std::getline(ss, result, this->separator);
//       std::stringstream ss(result);
//       ss >> this->value;
//       result.compare("NaN") == 0
//           ? temp.push_back(std::numeric_limits<double>::quiet_NaN())
//           : temp.push_back(this->value);
//     }
//     vector->push_back(temp[rowNumber]);
//     temp.clear();
//   }

//   input.close();
// }

// void CSVParser::readSpecificColumn(std::vector<std::string> &columns,
//                                    std::vector<std::vector<double>> *matrix)
//                                    {
//   std::vector<int> rows = this->getHeader(columns);
//   std::vector<double> vector;
//   std::ifstream input{this->path};
//   std::string value;

//   !input.is_open()
//       ? throw std::runtime_error("Could not open file. Please check the
//       path.") : getline(input, line);

//   while (getline(input, line)) {
//     std::istringstream ss{line};
//     while (getline(ss, value, this->separator)) {
//       if (rows.find)
//     }
//   }
// }

void CSVParser::generate(const std::vector<std::vector<double>> &data) {
  std::ofstream finalCsv("intermediary_file.csv");
  finalCsv << "I, J, ArithmeticMean" << std::endl;
  for (int i = 0; i < data[0].size(); i++) {
    for (int j = 0; j < data.size(); j++) {
      if (j + 1 != data.size()) {
        finalCsv << data[j][i] << ", ";
      } else {
        finalCsv << data[j][i];
      }
    }
    finalCsv << "\n";
  }
  finalCsv.close();
}
