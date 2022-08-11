#include "AbstractCurve.hpp"
#include "CSVParser.hpp"
#include "Metadata.hpp"
#include "SnakeCurve.hpp"
#include <fstream>
#include <functional>
#include <iostream>

Metadata *Metadata::instance = 0;

int main(int argc, char *argv[]) {
  CSVParser csvParser{argv[1]};
  Metadata *bf = bf->getInstance();
  std::string filePath = argv[1];
  SnakeCurve snake{atoi(argv[1])};

  std::vector<std::vector<double>> vector = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  snake.generateTraversedMatrix(vector);

  for (int i = 0; i < snake.getDimension().getX(); i++) {
    for (int j = 0; j < snake.getDimension().getX(); j++) {
      std::cout << vector.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  }
  // CSVParser csvParser{argv[1]};
  // std::vector<std::string> headers = {"I", "J", "Max", "Sum"};
  // std::vector<std::vector<double>>
  //     matrix; // std::vector<int> data = csvParser.getHeader(headers);

  // Metadata *bf = bf->getInstance();
  // // std::string filePath = argv[1];
  // // // std::string column = argv[2];

  // std::vector<std::vector<double>> data;
  // std::vector<double> vector;
  // csvParser.readSpecificColumn(headers, &matrix);

  // // // Tests
  // csvParser.readSpecificColumn("I", &vector);
  // bf->addToMatrix(vector);
  // vector.clear();

  // csvParser.readSpecificColumn("J", &vector);
  // bf->addToMatrix(vector);
  // vector.clear();

  // csvParser.readSpecificColumn("ArithmeticMean", &vector);
  // bf->addToMatrix(vector);
  // vector.clear();

  // // // Generate .csv file
  // csvParser.generate(bf->getData());
  // csvParser.generate(matrix);

  return 0;
}
