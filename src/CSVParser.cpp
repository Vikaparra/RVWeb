#include "CSVParser.hpp"

int CSVParser::getHeader(std::string desiredProperty) {
  std::ifstream input{this->path};
  std::string property;
  std::string line;
  int count = 0;

  getline(input, line);
  std::istringstream ss{line};

  while (getline(ss, property, this->separator)) {
    if (property.compare(desiredProperty) == 0) {
      bf->setPropertyName(property);
      return count;
    }
    count++;
  }

  return -1;
}

std::vector<double> CSVParser::readSpecificColumn(std::string column) {

  std::vector<double> vector;

  int rowNumber = this->getHeader(column);
  std::ifstream input{this->path};

  // Check if the file is open. If so, get rid of the header of the file;
  !input.is_open() ? throw std::runtime_error("Could not open file")
                   : getline(input, line);

  while (getline(input, line)) {
    std::istringstream ss{line};
    std::vector<double> temp;

    for (int i = 0; i <= rowNumber; i++) {
      std::string result;
      std::getline(ss, result, this->separator);
      std::stringstream ss(result);
      ss >> this->value;
      result.compare("NaN") == 0
          ? temp.push_back(std::numeric_limits<double>::quiet_NaN())
          : temp.push_back(this->value);
    }
    vector.push_back(temp[rowNumber]);
    temp.clear();
  }

  input.close();
  return vector;
}

void CSVParser::generate(const std::vector<double> &data) {
  std::ofstream finalCsv("intermediary_file.csv");
  finalCsv << bf->getProperty() << std::endl;
  for (int i = 0; i < data.size(); i++) {
    finalCsv << data[i] << "\n";
  }
  finalCsv.close();
}
