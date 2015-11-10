#include "Point.h"
#include "Vector.h"

Point::Point() 
	: z(0), y(0), x(0)
{

}

Point::Point(float x, float y)
	: z(0), y(y), x(x)
{
}

Point::Point(float x, float y, float z)
	: z(z), y(y), x(x)
{
}

Point Point::operator+(const Vector& v) {
	Point p2;

	p2.x = x + v.x;
	p2.y = y + v.y;

	return p2;
}
