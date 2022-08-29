#include "WellList.hpp"

#include <type_traits>

WellList::WellList(string strategy) { this->strategyName = strategy; };

void WellList::loadFile(string path) {
  ifstream input{path};
  vector<string> values;
  string wellName;
  string wellType;
  string line;
  Well well; // CONSERTAR
  Well *nullWell = &well;
  nullWell = NULL;

  while (getline(input, line, ';')) {
    boost::split(values, line, boost::is_any_of(";"));
    if (starts_with(line, "PRD") || starts_with(line, "INJ") ||
        starts_with(line, "PRODUCER") || starts_with(line, "INJECTOR")) {
      wellName = values[1];
      wellType = values[0];

      switch (wellType[0]) {
      case 'P':
        wellType = "PRODUCER";
        break;
      case 'I':
        wellType = "INJECTOR";
        break;
      default:
        wellType = "UNDEFINED";
        break;
      }

      nullWell = new Well(wellName, wellType);
      (*nullWell).getName();
    } else {
      int i = stoi(values[0]);
      int j = stoi(values[1]);
      int model = stoi(values[2]);
      IJKKey key("UNDEFINED", i, j, model);
      (*nullWell).addCoordinates(key);
      (*nullWell).getName();
    }
  }
  if (nullWell == NULL) {
    (*nullWell).updateBorders();
    this->wellList.push_back(well);
  }
};
