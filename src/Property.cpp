#include "Property.hpp"

Property::Property(char* configs)
{
        this->root = configs[1];
        this->function = configs[1];
        this->folder2d = configs[1];
        this->fileDistMatr = configs[1];
        this->sortingAlgor = configs[1];
        this->fileFeatVect = configs[1];
};