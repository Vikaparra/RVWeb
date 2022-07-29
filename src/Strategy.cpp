#include "Strategy.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

Strategy::Strategy(vector<string> sSplit)
{
    this->name = sSplit[0];
    this->path = sSplit[1];
};