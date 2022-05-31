#include "CSVParser.h"
#include <iterator>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>

std::vector<double> CSVParser::readFile(const std::string &pathToCsv)
{
  std::ifstream input{pathToCsv};

  // Check if the file is open

  if (!input.is_open())
  {
    throw std::runtime_error("Could not open file");
  }

  while (getline(input, this->line, ';'))
  {
    std::istringstream iss{this->line};
    std::vector<std::string> results{std::istream_iterator<std::string>(iss),
                                     std::istream_iterator<std::string>()};

    for (auto &result : results)
    {
      std::stringstream ss(result);
      ss >> this->value;
      ss.str() == "NaN" ? addToVector(-1) : addToVector(this->value);
    }
  }

  // Close the file
  input.close();

  return getVector();
}

void CSVParser::printVector(const std::vector<double> &vector)
{
  for (auto &i : vector)
  {
    std::cout << i << " " << std::endl;
  }
  std::cout << std::endl;
}