#include "RVConfig.hpp"
#include <iostream>
#include <string>
#include <vector>

#include <boost/algorithm/string/classification.hpp> // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp>

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
        //separar cada elemento de strats (ainda como char* e aplicar só o delim ";;" pra cada um deles, 
        //então pra cada um deles criaria um strategy e só depois usa o ";;", algo do tipo)
        // string delim = ", ";
        // vector<string> configs{};
        string stringStrats(strats);
        // size_t pos = 0;

        // stringStrats.erase(0,2);
        // stringStrats.erase(stringStrats.size()-1,2);

        // while ((pos = stringStrats.find(delim)) != string::npos) {
        //         configs.push_back(stringStrats.substr(0, pos));
        //         stringStrats.erase(0, pos + delim.length());
        // }

        // for (const auto &w : configs) {
        //         cout << w << endl;
        // }
        //Strategy strategy(configs[0]);

        std::vector<std::string> words;
        std::string s;
        boost::split(words, stringStrats, boost::is_any_of("', "), boost::token_compress_on);
        cout << stringStrats << endl;
        

}