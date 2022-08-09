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
    int min;
    int max;
    int numIterations;

public:
    Clustering(string method, string distMatrix, int min, int max, int numIter);
    string getMethod(){ return this->method; }
    string getDistMatrix(){ return this->distMatrix; }
    int getMin(){ return this->min; }
    int getMax(){ return this->max; }
    int getNumIterations(){ return this->numIterations; }
};
