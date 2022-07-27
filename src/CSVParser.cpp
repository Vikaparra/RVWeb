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

int CSVParser::getHeader(const std::string &pathToCsv, std::string desiredHeader)
{
  std::ifstream input{pathToCsv};
  std::string property;
  int count = 0;

  while (getline(input, this->line, ';'))
  {
    std::istringstream ss{this->line};
    ss >> property;
    if (property.compare(desiredHeader) == 0)
    {
      return count;
    }
    count++;
  }

  return -1;
}

void CSVParser::readSpecificColumn(const std::string &pathToCsv, std::string column, std::vector<double> *vector)
{
  int rowNumber = this->getHeader(pathToCsv, column);
  std::ifstream input{pathToCsv};

  // Check if the file is open. If so, get rid of the header of the file;
  !input.is_open() ? throw std::runtime_error("Could not open file")
                   : getline(input, this->line);

  while (getline(input, this->line))
  {
    std::istringstream ss{this->line};
    std::vector<double> temp;

    for (int i = 0; i <= rowNumber; i++)
    {
      std::string result;
      std::getline(ss, result, ';');
      std::stringstream ss(result);
      ss >> this->value;
      result.compare("NaN") == 0
          ? temp.push_back(std::numeric_limits<double>::quiet_NaN())
          : temp.push_back(this->value);
    }

    addToVector(*vector, temp[rowNumber]);
    temp.clear();
  }

  input.close();
}

void CSVParser::printVector(const std::vector<double> &vector)
{
  for (auto &i : vector)
  {
    std::cout << i << " " << std::endl;
  }
  std::cout << std::endl;
}

void CSVParser::generate(const std::vector<std::vector<double>> &data)
{
  std::ofstream finalCsv("intermediary_file.csv");
  finalCsv << "I, J, ArithmeticMean" << std::endl;
  for (int i = 0; i < data[0].size(); i++)
  {
    for (int j = 0; j < data.size(); j++)
    {
      finalCsv << data[j][i] << ", ";
    }
    finalCsv << "\n";
  }
  finalCsv.close();
}
