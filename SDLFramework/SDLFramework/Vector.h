#ifndef __vector__
#define __vector__
class Vector{
private:
	Vector();
public:
	float x;
	float y;
	float z;

	Vector(float x, float y);
	Vector(float x, float y, float z);

	Vector operator+(const Vector& v);
	Vector operator-(const Vector& v);
};
#endif
