#include "Well.hpp"
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using boost::starts_with;
using std::ifstream;
using std::string;
using std::vector;

class WellList {
private:
  string strategyName;
  vector<Well> wellList;

public:
  WellList(string strategyName);
  void loadFile(string path);
};
