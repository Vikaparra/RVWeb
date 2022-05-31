//
// Created by izael on 4/14/22.
//
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
#include <sstream>

#ifndef RESERVOIR_TEST_CSVPARSER_H
#define RESERVOIR_TEST_CSVPARSER_H

class CSVParser
{
private:
    std::vector<double> data;
    std::string line;
    double value;

public:
    std::size_t size() const { return data.size() - 1; }

    std::vector<double> getVector() { return this->data; } // Getter for row

    std::vector<double> readFile(const std::string &pathToCsv); // Read the specified file

    void printVector(const std::vector<double> &vector); // Print the generated vector

    void addToVector(double value) { this->data.push_back(value); } // Add a value to the row
};

#endif // RESERVOIR_TEST_CSVPARSER_H
