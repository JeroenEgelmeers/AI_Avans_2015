#ifndef __vector__
#define __vector__

#define PI 3.14159265

class Vector{
private:
public:
	float	x;
	float	y;

	Vector();
	Vector(float x, float y);

	// Math with vectors
	Vector	operator+(const Vector& v) const;
	Vector	operator-(const Vector& v) const;
	void    operator+=(const Vector& v);
	void    operator-=(const Vector& v);

	void operator*(float s);
	void operator/(float s);

	void	Average(float count);
	float	Length() const;
	float	LengthTorus(const Vector& v, int w, int h) const;
	void	Normalize();
	float	Heading();
	void	Truncate(float v);
	void    Limit(float max);
};
#endif
