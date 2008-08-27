#include "Point.h"

Point::Point()
{
	X = Y = Z = 0;
}

Point::Point(PointType dimensions)
{
	X = Y = Z = 0;
	this->dimensions = dimensions;	
}

Point::~Point()
{
}
