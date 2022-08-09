#include "Well.hpp"

Well::Well(string name, string type)
{
	this->name = name;
	this->type = type;
};

void Well::addCoordinates(IJKKey coordinates)
{
	this->coordinates.push_back(coordinates);
}

void Well::updateBorders()
{
	for (const auto &c : this->coordinates)
	{
		if (c.i < this->iMin)
		{
			this->iMin = c.i;
		}
		if (c.j < this->jMin)
		{
			this->jMin = c.j;
		}
		if (c.i > this->iMax)
		{
			this->iMax = c.i;
		}
		if (c.j > this->jMax)
		{
			this->jMax = c.j;
		}
	}
}