#include "Metadata.hpp"

Metadata *Metadata::getInstance() {
  if (!instance)
    instance = new Metadata;
  return instance;
}

int Metadata::getSize() { return this->size; }
int Metadata::getMaxI() { return this->getIColumn().back(); }
int Metadata::getMaxJ() { return this->getJColumn().back(); }
int Metadata::getMaxModel() { return this->getModelColumn().size() - 1; }
int Metadata::getNumOfModels() { return this->numOfModels; }
std::string Metadata::getProperty() { return this->property; }
std::string Metadata::getIntermediaryFile() { return this->intermediaryFile; }
std::string Metadata::getEnsembleName() { return this->ensembleName; }
std::vector<double> Metadata::getIColumn() { return this->iColumn; }
std::vector<double> Metadata::getJColumn() { return this->jColumn; }
std::vector<double> Metadata::getModelColumn() { return this->modelColumn; }
std::vector<double> Metadata::getPropertyColumn() {
  return this->propertyColumn;
}
std::vector<std::vector<double>> Metadata::getMatrix() { return this->matrix; }
// std::map<int, std::vector<double>> Metadata::getMap() {
//   return this->mapModelToValue;
// }
void Metadata::setEnsembleName(std::string ensembleName) {
  this->ensembleName = ensembleName;
}
void Metadata::setIColumn(std::vector<double> vector) {
  this->iColumn = vector;
}
void Metadata::setJColumn(std::vector<double> vector) {
  this->jColumn = vector;
}
void Metadata::setModelColumn(std::vector<double> vector) {
  this->modelColumn = vector;
}
void Metadata::setPropertyName(std::string property) {
  this->property = property;
}
void Metadata::setPropertyColumn(std::vector<double> vector) {
  this->propertyColumn = vector;
}
void Metadata::setIntermediaryFile(std::string intermediaryFile) {
  this->intermediaryFile = intermediaryFile;
}

// void Metadata::map() {
//   int count = 0;
//   int model = 1;
//   std::string line;
//   std::vector<double> data;
//
//   std::ifstream input{this->getIntermediaryFile()};
//   !input.is_open()
//       ? throw std::runtime_error(
//             "Could not open file. This is a Metadata error.")
//       : getline(input, line); // Get rid of the first line of the file;
//
//   while (getline(input, line)) {
//     count++;
//     double value;
//     std::istringstream ss{line};
//     ss >> value;
//     data.push_back(value);
//     if (count == this->getMaxI() * this->getMaxJ()) {
//       count = 0;
//       this->mapModelToValue.insert({model, data});
//       data.clear();
//       model++;
//     }
//   }
// }

std::vector<std::vector<double>> Metadata::map() {
  int count = 0;
  std::string line;
  std::vector<double> data;

  std::ifstream input{this->getIntermediaryFile()};

  !input.is_open()
      ? throw std::runtime_error(
            "Could not open file. This is a Metadata error.")
      : getline(input, line); // Get rid of the first line of the file;

  while (getline(input, line)) {
    count++;
    double value;
    std::istringstream ss{line};
    ss >> value;
    data.push_back(value);

    if (count == this->getMaxI() * this->getMaxJ()) {
      count = 0;
      this->matrix.push_back(data);
      std::cout << data.size() << std::endl;
      data.clear();
      std::cout << data.size() << std::endl;
    }
  }

  std::cout << this->matrix.size() << std::endl;
  std::cout << this->matrix.at(0).size() << std::endl;
  std::cout << this->matrix.at(1).at(1) << std::endl;
  return this->matrix;
}

std::vector<std::vector<std::vector<double>>>
Metadata::separateModel(std::vector<std::vector<double>> &data) {
  std::vector<std::vector<std::vector<double>>> result;
  std::vector<std::vector<double>> temp2d;
  std::vector<double> temp;

  for (int i = 0; i < data.size(); i++) {
    for (int j = 0; j < data.at(i).size(); j++) {
      temp.push_back(data.at(i).at(j));
      if ((j + 1) % 3 == 0) {
        temp2d.push_back(temp);
        temp.clear();
      }
    }
    result.push_back(temp2d);
    temp2d.clear();
  }

  for (int i = 0; i < data.size(); i++) {
    for (int j = 0; j < data.at(i).size(); j++) {
      std::cout << data.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "--------------------------------------------------------------"
            << std::endl;

  for (int i = 0; i < data.size(); i += 3) {
    for (int j = 0; j < 3; j += 1 + i) {
      for (int k = 0; k < data.at(i).size(); k++) {
        std::cout << data.at(k).at(j) << " ";
      }
      std::cout << std::endl;
    }
  }

  //  for (int i = 0; i < data.at(0).size(); i++) {
  //    for (int j = 0; j < data.size(); j += i) {
  //      std::cout << data.at(j).at(i) << " ";
  //    }
  //    std::cout << std::endl;
  //  }

  return result;
}

// NOTE: Only for visual and debugging purposes;
// void Metadata::printMap() {
//  for (const auto &pair : this->mapModelToValue) {
//    std::cout << pair.first << ": {";
//    for (const double value : pair.second) {
//      std::cout << value << " ";
//    }
//    std::cout << "}" << std::endl;
//  }
//}
