// Your First C++ Program a
#include "RVConfig.hpp"
#include <iostream>
#include <boost/serialization/vector.hpp>

int main(int argc, char** argv) {
    Configuration configuration(argv);
    // configuration.getProperties();
    // configuration.getStrategies();    
    std::cout << "Hello World";
    return 0;
}