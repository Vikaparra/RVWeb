#include <iostream>

class IJKKey
{
private:
    int i;
    int j;
    int k;

public:
    IJKKey(int i, int j, int k);
    int getI() { return this->i; }
    int getJ() { return this->j; }
    int getK() { return this->k; }
    int createHash();
};