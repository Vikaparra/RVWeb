#include "Strategy.hpp"
#include <vector>
#include <iostream>
#include <string>

using std::string; using std::vector;

Strategy::Strategy(string strats)
{
    string delim = ";;";
    vector<string> configs{};
    strats.erase(0,2);
    strats.erase(strats.size()-1,2);
    size_t pos = 0;
    while ((pos = strats.find(delim)) != string::npos) {
        configs.push_back(strats.substr(0, pos));
        strats.erase(0, pos + delim.length());
    }

    this->name = configs[0];
    this->path = configs[1];

    // std::cout << this->name << std::endl;
    // std::cout << this->path << std::endl;
    std::cout << strats[0] << std::endl;
    std::cout << strats[1] << std::endl;
};