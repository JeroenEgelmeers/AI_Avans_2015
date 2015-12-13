#ifndef __vector__
#define __vector__
class Vector{
private:
public:
	float	x;
	float	y;
	float	z;

	Vector();
	Vector(float x, float y);
	Vector(float x, float y, float z);

	Vector	operator+(const Vector& v);
	Vector	operator-(const Vector& v);

	float	Length() const;
	void	Normalize();
};
#endif
