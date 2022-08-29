#include "Metadata.hpp"

void Metadata::map() {
  std::ifstream input{this->getIntermediaryFile()};
  std::string line;
  int count = 0;
  int model = 1;
  std::vector<double> data;
  !input.is_open()
      ? throw std::runtime_error("Could not open file. Check the path.")
      : getline(input, line); // Get rid of the first line of the file;

  while (getline(input, line)) {
    count++;
    double value;
    std::istringstream ss{line};
    ss >> value;
    data.push_back(value);
    if (count == this->getMaxI() * this->getMaxJ()) {
      count = 0;
      this->mapModelToValue.insert({model, data});
      std::cout << "size: " << data.size() << std::endl;
      data.clear();
      std::cout << "Finished Model " << model << std::endl;
      model++;
    }
  }
}

void Metadata::printMap() {
  std::map<int, std::vector<double>>::iterator itr;
  for (itr = this->mapModelToValue.begin(); itr != this->mapModelToValue.end();
       ++itr) {
    std::cout << itr->first << "----";
    std::cout << itr->second.at(1) << std::endl;
  }
}
