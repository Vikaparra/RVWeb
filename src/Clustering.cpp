#include "Clustering.hpp"

Clustering::Clustering(string method, string distMatrix, int min, int max, int numIter){
    this->method = method;
    this->distMatrix = distMatrix;
    this->min = min;
    this->max = max;
    this->numIterations = numIter;
}