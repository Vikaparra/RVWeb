#include <string>
#include <iostream>

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
        std::string properties;
        std::string strategies;
        std::string allModels;
        std::string hlModels;
    public:
        Configuration::Configuration(std::string root, std::string benchmark, std::string folder2d, std::string folderDistMatr, std::string chartType, std::string layoutCurve, std::string clustMethod, std::string distMatrix, std::string minClusters, std::string maxClusters, std::string numIterations, std::string properties, std::string strategies, std::string allModels, std::string hlModels);
        std::string getRoot() { return (this->root); }
};