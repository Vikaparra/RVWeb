#include <iostream>
#include <string>
#include <vector>
#include "Well.hpp"

using std::string; using std::vector;

class WellList : private vector<Well>  {
    private:
        string strategyName;
    public:
        WellList(string strategyName);
};
