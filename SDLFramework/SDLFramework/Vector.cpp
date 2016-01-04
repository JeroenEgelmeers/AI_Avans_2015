#include "Vector.h"
#include "Point.h"

#include <cmath>
#include <ctgmath>
#include <algorithm>

Vector::Vector()
	: y(0), x(0)
{
}

Vector::Vector(float x, float y)
	: y(y), x(x)
{
}

Vector Vector::operator+(const Vector& v) const
{
	Vector v2;
	v2.x = x + v.x;
	v2.y = y + v.y;

	return v2;
}

Vector Vector::operator-(const Vector& v) const
{	
	Vector v2;
	v2.x = x - v.x;
	v2.y = y - v.y;

	return v2;
}

void Vector::operator+=(const Vector& v)
{
    x += v.x;
	y += v.y;
}

void Vector::operator-=(const Vector& v)
{
	x -= v.x;
	y -= v.y;
}

void Vector::operator*(float s) {
	x *= s;
	y *= s;
}

void Vector::operator/(float s) {
	x /= s;
	y /= s;
}

void Vector::Average(float count) {
	x /= count;
	y /= count;
}

float Vector::Length() const {
	float length;

	length = sqrt(x*x + y*y);

	return length;
}

float Vector::LengthTorus(const Vector& v, int w, int h) const {
	float minX = std::min(x - v.x, w - x - v.x);
	float minY = std::min(y - v.y, h - y - v.y);
	return sqrt(minX * minX + minY * minY);
}

float Vector::Heading() {
	return (float)(atan2(y, x) * 180 / PI);
}

void Vector::Normalize() {
	float length = Length();
	x /= length;
	 y /= length;
}

void Vector::Truncate(float v){
	if (Length() > v)
	{
		Normalize();

		x *= v;
		y *= v;
	}
}

void Vector::Limit(float max) {
	if (x > max) {
		x = max;
	}
	if (y > max) {
		y = max;
	}
}
