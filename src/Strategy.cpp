#include "Strategy.hpp"


using std::string; using std::vector; using std::cout; using std::endl;

Strategy::Strategy(vector<string> sSplit)
{
    this->name = sSplit[0];
    this->path = sSplit[1];
};