#include <iostream>
#include <string>
#include <vector>
#include <boost/regex.hpp>
#include "Property.hpp"
#include "Strategy.hpp"
#include "WellList.hpp"
#include "Clustering.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stoi;

#define RVWEB_RVCONFIG_H

class Configuration
{
private:
    string root;
    string benchmark;
    string folder2d;
    string folderDistMatr;
    string chartType;
    string layoutCurve;
    Clustering clusteringConfig(string clustMethod, string distMatrix, int minClusters, int maxClusters,int numIterations);
    vector<Property> properties;
    vector<Strategy> strategies;
    string allModels;
    string hlModels;

public:
    Configuration(char **configs);
    string getRoot() { return (this->root); }
    void regexFirst(char *strats, string type);
    void regexSecond(string strats, string type);
    vector<WellList> createWellList();
    void settingDrawConfigs(vector<WellList> estrategias);
};
