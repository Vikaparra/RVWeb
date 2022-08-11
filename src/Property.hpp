#include <iostream>
#include <string>
#include <vector>

<<<<<<< Updated upstream
using std::string;
using std::vector;

class Property
{
private:
    std::string root;
    std::string function;
    std::string folder2d;
    std::string fileDistMatr;
    std::string sortingAlgor;
    std::string fileFeatVect;

public:
    Property(vector<string> sSplit);
    int convertMeanType();
    // std::string getRoot() { return (this->root); }
    // void getProperties() { std::cout << (this->properties) << std::endl; }
    // void getStrategies() { std::cout << (this->strategies) << std::endl; }
=======
#ifndef RVWEB_PROPERTY_H
#define RVWEB_PROPERTY_H

class Property {
private:
  std::string root;
  std::string function;
  std::string folder2d;
  std::string fileDistMatr;
  std::string sortingAlgor;
  std::string fileFeatVect;

public:
  Property(char *configs);
  // std::string getRoot() { return (this->root); }
  // void getProperties() { std::cout << (this->properties) << std::endl; }
  // void getStrategies() { std::cout << (this->strategies) << std::endl; }
>>>>>>> Stashed changes
};

#endif
