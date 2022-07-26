#include "Property.hpp"

Property::Property(vector<string> sSplit)
{
        this->root = sSplit[0];
        this->function = sSplit[1];
        this->folder2d = sSplit[2];
        this->fileDistMatr = sSplit[3];
        this->sortingAlgor = sSplit[4];
        this->fileFeatVect = sSplit[5];
};