#ifndef __point__
#define __point__

class Vector;

class Point
{
protected:
public:
	float x;
	float y;
	float z;

	Point();
	Point(float x, float y);
	Point(float x, float y, float z);
	
	Point operator+(const Vector& v);
	Vector operator-(const Point& p);
};

#endif

