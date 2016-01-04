#include "Vector.h"
#include "Point.h"

#include <cmath>
#include <ctgmath>
#include <algorithm>

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

void Vector::operator+=(const Vector& v)
{
    x += v.x;
	y += v.y;
	z += v.z;
}

Vector Vector::operator*(float s) {
	Vector v2;

	v2.x = x * s;
	v2.y = y * s;
	v2.z = z * s;

	return v2;
}

Vector Vector::operator/(float s) {
	Vector v2;

	v2.x = x / s;
	v2.y = y / s;
	v2.z = z / s;

	return v2;
}

void Vector::Average(float count) {
	x /= count;
	y /= count;
	z /= count;
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

float Vector::Angle() {
	return atan2(y, x) * 180 / PI;
}

void Vector::Normalize() {
	float length = Length();
	x = x / length;
	y = y / length;
	z = z / length;
}
