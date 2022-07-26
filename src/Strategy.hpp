#include <iostream>
#include <string>
#include <vector>
#include <boost/regex.hpp>

using std::string; using std::vector;

class Strategy {
    private:
        std::string name;
        std::string path;
    public:
        Strategy(vector<string> sSplit);
        // std::string getRoot() { return (this->root); }
        // void getProperties() { std::cout << (this->properties) << std::endl; }
        // void getStrategies() { std::cout << (this->strategies) << std::endl; }
};
