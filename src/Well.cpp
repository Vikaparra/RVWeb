#include "Well.hpp"

Well::Well(string name, string type, vector<string> coordinates)
{
        this->name = name;
        this->type = type;
        this->coordinates.push_back(coordinates);
};