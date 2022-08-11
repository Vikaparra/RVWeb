#include <iostream>
#include <string>
#include <vector>
#include "Well.hpp"
#include <fstream>
#include <set>
#include <boost/algorithm/string.hpp>

using std::ifstream;
using std::string;
using std::vector;
using boost::starts_with;

class WellList
{
private:
    string strategyName;
    vector<Well> wellList;

public:
    WellList(string strategyName);
    void loadFile(string path);
};
