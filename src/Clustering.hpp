#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Clustering
{
private:
    string method;
    string distMatrix;
    string min;
    string max;
    string numIterations;

public:
    Clustering(string method, string distMatrix, int min, int max, int numIter);
};
