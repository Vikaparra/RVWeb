#include "Property.hpp"

Property::Property(vector<string> sSplit)
{
	this->root = sSplit[0];
	this->function = sSplit[1];
	this->folder2d = sSplit[2];
	this->fileDistMatr = sSplit[3];
	this->sortingAlgor = sSplit[4];
	this->fileFeatVect = sSplit[5];
};

int Property::convertMeanType()
{
	switch (this->function[0])
	{
		case 'M':
			if(this->function == "MIN"){
				return 3;
			}else if(this->function == "MAX"){
				return 4;
			}else if(this->function == "MODE"){
				return 10;
			}
			break;

		case 'S':
			if(this->function == "SUM"){
				return 5;
			}else if(this->function == "STDEV"){
				return 6;
			}	
			break;

		case 'A':
			return 7;
			break;

		case 'G':
			return 8;
			break;

		case 'H':
			return 9;
			break;

		default:
			//CRIAR EXCESSÃO
			break;
	}
}