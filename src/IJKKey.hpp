#include <iostream>
#include <string>
#include <vector>
#include <boost/regex.hpp>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stoi;

// LEMBRAR DE MUDAR O NOME

class IJKKey
{
    public:
        string property;
        int i;
        int j;
        int model;
        IJKKey(string property, int i, int j, int model);
};