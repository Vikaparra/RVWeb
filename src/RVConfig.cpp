#include "RVConfig.hpp"
#include <string>
#include <iostream>

Configuration::Configuration(std::string root, std::string benchmark, std::string folder2d, std::string folderDistMatr, std::string chartType, std::string layoutCurve, std::string clustMethod, std::string distMatrix, std::string minClusters, std::string maxClusters, std::string numIterations, std::string properties, std::string strategies, std::string allModels, std::string hlModels)
{
        this->root = root;
        this->benchmark = benchmark;
        this->folder2d = folder2d;
        this->folderDistMatr = folderDistMatr;
        this->chartType = chartType;
        this->layoutCurve = layoutCurve;
        this->clustMethod = clustMethod;
        this->distMatrix = distMatrix;
        this->minClusters = minClusters;
        this->maxClusters = maxClusters;
        this->numIterations = numIterations;
        this->properties = properties;
        this->strategies = strategies;
        this->allModels = allModels;
        this->hlModels = hlModels;
};