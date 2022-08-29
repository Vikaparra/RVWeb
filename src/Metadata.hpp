#include <algorithm>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/vector.hpp>
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
  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive &ar, const unsigned int version) {
    ar &iColumn;
    ar &jColumn;
    ar &modelColumn;
    ar &ensembleName;
    ar &numOfModels;
    ar &size;
  }

  std::vector<double> iColumn;
  std::vector<double> jColumn;
  std::vector<double> modelColumn;
  std::vector<double> propertyColumn;
  std::map<int, std::vector<double>> mapModelToValue;
  std::string ensembleName;
  int numOfModels = modelColumn.size() - 1;
  int size = std::ceil(std::sqrt(numOfModels));
  std::string property;
  std::string intermediaryFile =
      "/home/izael/Documents/git/RVWeb/intermediary_file.csv";

public:
  static Metadata *getInstance() {
    if (!instance)
      instance = new Metadata;
    return instance;
  }

  void map();
  void printMap();

  // Getters
  std::map<int, std::vector<double>> getMap() { return this->mapModelToValue; }
  int getNumOfModels() { return this->numOfModels; }
  int getSize() { return this->size; }
  std::string getEnsembleName() { return this->ensembleName; }
  std::vector<double> getIColumn() { return this->iColumn; }
  std::vector<double> getJColumn() { return this->jColumn; }
  std::vector<double> getModelColumn() { return this->modelColumn; }
  std::vector<double> getPropertyColumn() { return this->propertyColumn; }
  std::string getProperty() { return this->property; }
  std::string getIntermediaryFile() { return this->intermediaryFile; }
  int getMaxI() { return this->getIColumn().back(); }
  int getMaxJ() { return this->getJColumn().back(); }
  int getMaxModel() { return this->getModelColumn().size() - 1; }

  // Setters
  void setEnsembleName(std::string ensembleName) {
    this->ensembleName = ensembleName;
  }
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
