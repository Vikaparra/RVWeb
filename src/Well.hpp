#include <iostream>
#include <string>
#include <vector>
#include "IJKKey.hpp"

using std::string;
using std::vector;

class Well
{
private:
    string type;
    string name;
    vector<IJKKey> coordinates;
    int iMin; // o que isso significa???
    int iMax;
    int jMin;
    int jMax;

public:
    Well(string name, string type);
    Well();
    void addCoordinates(IJKKey coordinates);
    void getName() { std::cout << "NOME: " << this->name; }
    void updateBorders();
};
