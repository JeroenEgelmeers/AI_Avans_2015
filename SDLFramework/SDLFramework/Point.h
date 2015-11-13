#ifndef __point__
#define __point__

class Vector;

class Point
{
protected:
	Point();
public:
	float x;
	float y;
	float z;

	Point(float x, float y);
	Point(float x, float y, float z);
	
	Point operator+(const Vector& v);
};

#endif

