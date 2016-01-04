#ifndef __vector__
#define __vector__

#define PI 3.14159265

class Vector{
private:
public:
	float	x;
	float	y;
	float	z;

	Vector();
	Vector(float x, float y);
	Vector(float x, float y, float z);

	// Math with vectors
	Vector	operator+(const Vector& v);
	Vector	operator-(const Vector& v);
	void    operator+=(const Vector& v);

	Vector operator*(float s);
	Vector operator/(float s);

	void	Average(float count);
	float	Length() const;
	float	LengthTorus(const Vector& v, int w, int h) const;
	void	Normalize();
	float	Angle();
};
#endif
