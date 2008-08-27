#ifndef POINT_H_
#define POINT_H_

enum PointType
{
	D2,
	D3	
};

//TODO: Perhaps someday in the distant future when I'm really ambitious make these points
//		dimensionless using a list or something :D
class Point
{
 public:
  Point();
  Point(PointType dimensions);
  virtual ~Point();
	
  double X;
  double Y;
  double Z;
	
  PointType dimensions;
};

#endif /*POINT_H_*/
