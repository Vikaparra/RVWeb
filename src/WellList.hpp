#include <iostream>
#include <string>
#include <vector>
#include "Well.hpp"
#include <fstream>

using std::string; using std::vector; using std::ifstream;

class WellList : private vector<Well>  {
    private:
        string strategyName;
        vector<Well> wellList;
    public:
        WellList(string strategyName, vector<Well> wellList, string path);
        void loadFile(string path);
};
