//
// Created by izael on 4/14/22.
//
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#ifndef RESERVOIR_TEST_CSVPARSER_H
#define RESERVOIR_TEST_CSVPARSER_H

class CSVParser
{
private:
  char separator;
  double value;
  std::vector<double> data;
  std::string line;
  std::string property;

public:
  int getHeader(const std::string &pathToCsv, std::string desiredHeader);                   // Get the number of the desired column
  void printVector(const std::vector<double> &vector);                                      // Print the generated vector
  void addToVector(double value) { this->data.push_back(value); }                           // Add a value to the row
  std::vector<double> readFile(const std::string &pathToCsv);                               // Read the specified file
  std::vector<double> getVector() { return this->data; }                                    // Getter for row
  std::vector<double> readSpecificColumn(const std::string &pathToCsv, std::string column); // Get the desired column
};

#endif // RESERVOIR_TEST_CSVPARSER_H
