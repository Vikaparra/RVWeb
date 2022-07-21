#include <iostream>
#include <string>

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
        char* properties;
        char* strategies;
        std::string allModels;
        std::string hlModels;
    public:
        Configuration(char** configs);
        std::string getRoot() { return (this->root); }
        void getProperties() { std::cout << (this->properties) << std::endl; }
        void getStrategies() { std::cout << (this->strategies) << std::endl; }
};
