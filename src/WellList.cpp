#include "WellList.hpp"

WellList::WellList(string strategy, vector<Well> wellList, string path)
{
    this->strategyName = strategy;
    this->wellList = wellList;


};

void WellList::loadFile(string path){
    
};