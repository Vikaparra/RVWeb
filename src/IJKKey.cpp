#include "IJKKey.hpp"
#include <string>
#include <iostream>

IJKKey::IJKKey(int i, int j, int k)
{
    this->i = i;
    this->j = j;
    this->k = k;
}

int IJKKey::createHash()
{
    std::hash<int> toHash;
    return toHash(getI()) + toHash(getJ()) + toHash(getK());
}