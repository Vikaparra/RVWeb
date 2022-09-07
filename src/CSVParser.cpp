#include "CSVParser.hpp"

int CSVParser::getHeader(std::string desiredProperty) {
  int count = 0;
  std::string line;
  std::string property;

  std::ifstream input{this->path};
  getline(input, line);
  std::istringstream ss{line};

  while (getline(ss, property, this->separator)) {
    if (property.compare(desiredProperty) == 0) {
      bf->setPropertyName(property);
      return count;
    }
    count++;
  }

  return std::numeric_limits<int>::quiet_NaN();
}

std::vector<double> CSVParser::readSpecificColumn(std::string column) {

  int rowNumber = this->getHeader(column);
  double value;
  std::string line;
  std::vector<double> vectorOfColumn;

  std::ifstream input{this->path};

  // Check if the file is open. If so, get rid of the header of the file;
  !input.is_open() ? throw std::runtime_error(
                         "Could not open file. This is a CSVParser error.")
                   : getline(input, line);

  while (getline(input, line)) {
    std::istringstream ss{line};
    std::vector<double> temp;

    for (int i = 0; i <= rowNumber; i++) {
      std::string result;
      std::getline(ss, result, this->separator);
      std::stringstream ss(result);
      ss >> value;

      result.compare("NaN") == 0
          ? temp.push_back(std::numeric_limits<double>::quiet_NaN())
          : temp.push_back(value);
    }
    vectorOfColumn.push_back(temp.at(rowNumber));
    temp.clear();
  }

  input.close();
  return vectorOfColumn;
}

void CSVParser::generate(const std::vector<double> &data) {
  std::ofstream intermediaryCsv("test/intermediary_file.csv");
  intermediaryCsv << bf->getProperty() << std::endl;
  for (const auto &value : data) {
    intermediaryCsv << value << "\n";
  }
  intermediaryCsv.close();
}
