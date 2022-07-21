#include <iostream>
#include <string>

class Property {
    private:
        std::string root;
        std::string function;
        std::string folder2d;
        std::string fileDistMatr;
        std::string sortingAlgor;
        std::string fileFeatVect;
    public:
        Property(char* configs);
        // std::string getRoot() { return (this->root); }
        // void getProperties() { std::cout << (this->properties) << std::endl; }
        // void getStrategies() { std::cout << (this->strategies) << std::endl; }
};
