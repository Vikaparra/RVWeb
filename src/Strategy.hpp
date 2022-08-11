#include <iostream>
#include <string>
#include <vector>
#include <boost/regex.hpp>

using std::string;
<<<<<<< Updated upstream
using std::vector;

class Strategy
{
private:
    string name;
    string path;

public:
    Strategy(vector<string> sSplit);
    string getName() { return (this->name); }
    string getPath() { return (this->path); }
=======

#ifndef RVWEB_STRATEGY_H
#define RVWEB_STRATEGY_H

class Strategy {
private:
  std::string name;
  std::string path;

public:
  Strategy(string configs);
  // std::string getRoot() { return (this->root); }
  // void getProperties() { std::cout << (this->properties) << std::endl; }
  // void getStrategies() { std::cout << (this->strategies) << std::endl; }
>>>>>>> Stashed changes
};

#endif
