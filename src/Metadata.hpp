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
  int numOfModels;
  int size;
  std::string ensembleName;
  std::string property;
  std::string intermediaryFile;
  std::vector<double> iColumn;
  std::vector<double> jColumn;
  std::vector<double> modelColumn;
  std::vector<double> propertyColumn;
  // std::map<int, std::vector<double>> mapModelToValue;
  std::vector<std::vector<double>> matrix;

public:
  // Singleton
  static Metadata *getInstance();

  // Map related methods
  // void map();
  void printMap();
  std::vector<std::vector<double>> map();
  std::vector<std::vector<std::vector<double>>>
  separateModel(std::vector<std::vector<double>> &data);

  // Getters
  int getNumOfModels();
  int getSize();
  int getMaxI();
  int getMaxJ();
  int getMaxModel();
  std::string getProperty();
  std::string getIntermediaryFile();
  std::string getEnsembleName();
  std::vector<double> getIColumn();
  std::vector<double> getJColumn();
  std::vector<double> getModelColumn();
  std::vector<double> getPropertyColumn();
  // std::map<int, std::vector<double>> getMap();
  std::vector<std::vector<double>> getMatrix();

  // Setters
  void setEnsembleName(std::string ensembleName);
  void setIColumn(std::vector<double> vector);
  void setJColumn(std::vector<double> vector);
  void setModelColumn(std::vector<double> vector);
  void setPropertyName(std::string property);
  void setPropertyColumn(std::vector<double> vector);
  void setIntermediaryFile(std::string intermediaryFile);
};

#endif
