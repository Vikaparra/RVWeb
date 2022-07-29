#include <iostream>
#include <string>
#include <vector>
#include <boost/regex.hpp>

using std::string;
using std::vector;

class Strategy
{
private:
    string name;
    string path;

public:
    Strategy(vector<string> sSplit);
    string getName() { return (this->name); }
    string getPath() { return (this->path); }
};
