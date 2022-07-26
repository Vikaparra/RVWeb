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
    // this->properties = configs[12];
    // this->strategies = configs[13];
    this->allModels = configs[14];
    this->hlModels = configs[15];

    this->regexFirst(configs[12], "Property");
    this->regexFirst(configs[13], "Strategy");

};

void Configuration::regexFirst(char* strats, string type){

    string stringStrats(strats);

    boost::regex regex("(?<=\')[^',]+(?=\')");

    boost::sregex_token_iterator iter(stringStrats.begin(), stringStrats.end(),regex,0);
    boost::sregex_token_iterator end;

    std::vector<std::string> stratsSplit(iter, end);
    
    for (const auto &s : stratsSplit){
        regexSecond(s, type);
    }
    
}

void Configuration::regexSecond(string strats, string type){
    boost::regex regex("[^;]+");

    boost::sregex_token_iterator iter(strats.begin(), strats.end(),regex,0);
    boost::sregex_token_iterator end;

    vector<string> sSplit(iter, end);

    if(type == "Strategy"){
        Strategy strategy(sSplit);
        this->strategies.push_back(strategy);
    }
    else if(type == "Property"){
        Property property(sSplit);
        this->properties.push_back(property);
    }
}