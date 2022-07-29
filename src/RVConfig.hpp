#include <iostream>
#include <string>
#include <vector>
#include <boost/regex.hpp>
#include "Property.hpp"
#include "Strategy.hpp"

using std::cout;
using std::endl; using std::string;
using std::vector;

#define RVWEB_RVCONFIG_H

class Configuration {
    private:
        std::string root;
        std::string benchmark;
        std::string folder2d;
        std::string folderDistMatr;
        std::string chartType;
        std::string layoutCurve;
        std::string clustMethod;
        std::string distMatrix;
        std::string minClusters;
        std::string maxClusters;
        std::string numIterations;
        std::vector<Property> properties;
        std::vector<Strategy> strategies;
        std::string allModels;
        std::string hlModels;
    public:
        Configuration(char** configs);
        std::string getRoot() { return (this->root); }
        void regexFirst(char* strats, string type);
        void regexSecond(string strats, string type);
        void addStrategiesWell();

        // void getProperties() { std::cout << (this->properties) << std::endl; }
        // void getStrategies() { std::cout << (this->strategies) << std::endl; }
};
