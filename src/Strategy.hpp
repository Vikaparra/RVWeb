#include <iostream>
#include <string>
#include <vector>

using std::string; using std::vector;

class Strategy {
    private:
        std::string name;
        std::string path;
    public:
        Strategy(string configs);
        // std::string getRoot() { return (this->root); }
        // void getProperties() { std::cout << (this->properties) << std::endl; }
        // void getStrategies() { std::cout << (this->strategies) << std::endl; }
};
