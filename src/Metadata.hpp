#include <algorithm>
#include <cmath>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <vector>

#ifndef RVWEB_METADATA_H
#define RVWEB_METADATA_H

class Metadata {
protected:
  static Metadata *instance;

private:
  std::vector<double> iColumn;
  std::vector<double> jColumn;
  std::vector<double> modelColumn;
  std::vector<double> propertyColumn;
  std::string property;

public:
  static Metadata *getInstance() {
    if (!instance)
      instance = new Metadata;
    return instance;
  }
  // Getters
  int getMaxI() { return this->getIColumn().back(); }
  int getMaxJ() { return this->getJColumn().back(); }
  int getMaxModel() { return this->getModelColumn().back(); }
  std::string getProperty() { return this->property; }
  std::vector<double> getIColumn() { return this->iColumn; }
  std::vector<double> getJColumn() { return this->jColumn; }
  std::vector<double> getModelColumn() { return this->modelColumn; }
  std::vector<double> getPropertyColumn() { return this->propertyColumn; }

  // Setters
  void setIColumn(std::vector<double> vector) { this->iColumn = vector; }
  void setJColumn(std::vector<double> vector) { this->jColumn = vector; }
  void setModelColumn(std::vector<double> vector) {
    this->modelColumn = vector;
  }
  void setPropertyName(std::string property) { this->property = property; }
  void setPropertyColumn(std::vector<double> vector) {
    this->propertyColumn = vector;
  }
};

#endif
