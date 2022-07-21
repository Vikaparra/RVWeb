#include <iostream>
#include <string>
#include <vector>
#include "Property.hpp"
#include "Strategy.hpp"

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
        void setStrategies(char* strats);

        // void getProperties() { std::cout << (this->properties) << std::endl; }
        // void getStrategies() { std::cout << (this->strategies) << std::endl; }
};
