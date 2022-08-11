#include <boost/regex.hpp>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Strategy {
private:
  string name;
  string path;

public:
  Strategy(vector<string> sSplit);
  string getName() { return (this->name); }
  string getPath() { return (this->path); }
};
