#include "Property.hpp"
#include "Strategy.hpp"
#include <iostream>
#include <string>
#include <vector>
<<<<<<< Updated upstream
#include <boost/regex.hpp>
#include "Property.hpp"
#include "Strategy.hpp"
#include "WellList.hpp"
#include "Clustering.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stoi;
=======
>>>>>>> Stashed changes

#ifndef RVWEB_RVCONFIG_H
#define RVWEB_RVCONFIG_H

<<<<<<< Updated upstream
class Configuration
{
private:
    string root;
    string benchmark;
    string folder2d;
    string folderDistMatr;
    string chartType;
    string layoutCurve;
    vector<Property> properties;
    vector<Strategy> strategies;
    string allModels;
    string hlModels;

public:
    Clustering clusteringConfig;
    Configuration(char **configs);
    string getRoot() { return ( root ); }
    void regexFirst(char *strats, string type);
    void regexSecond(string strats, string type);
    vector<WellList> createWellList();
    void settingDrawConfigs(vector<WellList> estrategias);
=======
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
  Configuration(char **configs);
  std::string getRoot() { return (this->root); }
  void setStrategies(char *strats);

  // void getProperties() { std::cout << (this->properties) << std::endl; }
  // void getStrategies() { std::cout << (this->strategies) << std::endl; }
>>>>>>> Stashed changes
};

#endif
