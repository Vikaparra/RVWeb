#include "RVConfig.hpp"

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
        this->properties = configs[12];
        this->strategies = configs[13];
        this->allModels = configs[14];
        this->hlModels = configs[15];

};