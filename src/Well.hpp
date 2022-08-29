#include "IJKKey.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

#ifndef RVWEB_WELL_H
#define RVWEB_WELL_H

class Well {
private:
  string type;
  string name;
  vector<IJKKey> coordinates;
  int iMin; // o que isso significa???
  int iMax;
  int jMin;
  int jMax;

public:
  Well(string name, string type);
  Well();
  void addCoordinates(IJKKey coordinates);
  void getName() { std::cout << "NOME: " << this->name; }
  void updateBorders();
};

#endif
