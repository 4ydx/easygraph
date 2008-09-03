#include "Point.h"

Point::Point()
  :X(0), Y(0), Z(0)
{
	this->dimensions = D2;
}

Point::Point(PointType dimensions)
  :X(0), Y(0), Z(0)
{
	this->dimensions = dimensions;	
}

Point::~Point()
{
}
