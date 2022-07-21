#include "RVConfig.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl; using std::string;
using std::vector;

Configuration::Configuration(char** configs)
{
        this->root = configs[1];
        this->benchmark = configs[2];
        this->folder2d = configs[3];
        this->folderDistMatr = configs[4];
        this->chartType = configs[5];
        this->layoutCurve = configs[6];
        this->clustMethod = configs[7];
        this->distMatrix = configs[8];
        this->minClusters = configs[9];
        this->maxClusters = configs[10];
        this->numIterations = configs[11];
        // this->properties = configs[12];
        // this->strategies = configs[13];
        this->allModels = configs[14];
        this->hlModels = configs[15];

        this->setStrategies(configs[13]);

};

void Configuration::setStrategies(char* strats){
        string delim = ", ";
        vector<string> configs{};
        string stringStrats(strats);
        size_t pos = 0;

        stringStrats.erase(0,2);
        stringStrats.erase(stringStrats.size()-1,2);

        while ((pos = stringStrats.find(delim)) != string::npos) {
                configs.push_back(stringStrats.substr(0, pos));
                stringStrats.erase(0, pos + delim.length());
        }

        for (const auto &w : configs) {
                cout << w << endl;
        }
        //Strategy strategy(configs[0]);
}