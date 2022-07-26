#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
#include <boost/serialization/vector.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

#ifndef RVWEB_METADATA_H
#define RVWEB_METADATA_H

class Metadata
{
protected:
  static Metadata *instance;

private:
  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive &ar, const unsigned int version)
  {
    ar &iColumn;
    ar &jColumn;
    ar &modelColumn;
    ar &ensembleName;
    ar &maxI;
    ar &maxJ;
  }

  std::vector<double> iColumn;
  std::vector<double> jColumn;
  std::vector<double> modelColumn;
  std::string ensembleName;
  int maxI;
  int maxJ;

public:
  static Metadata *getInstance()
  {
    if (!instance)
      instance = new Metadata;
    return instance;
  }

  // Getters
  int getMaxI() { return this->maxI; }
  int getMaxJ() { return this->maxJ; }
  std::string getEnsembleName() { return this->ensembleName; }
  std::vector<double> getIColumn() { return this->iColumn; }
  std::vector<double> getJColumn() { return this->jColumn; }
  std::vector<double> getModelColumn() { return this->modelColumn; }

  // Setters
  void setModelColumn(std::vector<double> vector) { this->modelColumn = vector; }
  void setIColumn(std::vector<double> vector) { this->iColumn = vector; }
  void setJColumn(std::vector<double> vector) { this->jColumn = vector; }
  void setMaxI(std::vector<double> &vector)
  {
    this->maxI = vector[vector.size() - 1];
  }

  void setMaxJ(std::vector<double> &vector)
  {
    this->maxJ = vector[vector.size() - 1];
  }

  void setEnsembleName(std::string ensembleName) { this->ensembleName = ensembleName; }
};

#endif