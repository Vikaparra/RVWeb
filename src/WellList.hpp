#include <iostream>
#include <string>
#include <vector>
#include "Well.hpp"
#include <fstream>
#include <set>

using std::ifstream;
using std::string;
using std::vector;

class WellList : private Well
{
private:
    string strategyName;
    vector<Well> wellList;

public:
    WellList(string strategyName);
    void loadFile(string path);
};
