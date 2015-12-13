#include "Vector.h"

#include <cmath>

Vector::Vector()
	: z(0), y(0), x(0)
{
}

Vector::Vector(float x, float y)
	: z(0), y(y), x(x)
{
}

Vector::Vector(float x, float y, float z)
	: z(z), y(y), x(x)
{
}

Vector Vector::operator+(const Vector& v)
{
	Vector v2;

	v2.x = x + v.x;
	v2.y = y + v.y;
	v2.z = z + v.z;

	return v2;
}

Vector Vector::operator-(const Vector& v)
{
	Vector v2;

	v2.x = x - v.x;
	v2.y = y - v.y;
	v2.z = z - v.z;

	return v2;
}

float Vector::Length() const {
	float length;

	length = sqrt(x*x + y*y);

	return length;
}

void Vector::Normalize() {
	float length = Length();
	x = x / length;
	y = y / length;
	z = z / length;
}
