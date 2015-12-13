#pragma once

#include "IGameObject.h"
#include "Vector.h"

class MovingEntity : public IGameObject
{
private:
	Vector m_Velocity;
	Vector m_Heading;
	Vector m_Side;

	float f_Mass;
	float m_MaxSpeed;
	float m_MaxForce;
	float m_MaxTurnRate;
public:
	MovingEntity();
	~MovingEntity();

	virtual void Update(float deltatime) =0;
	virtual void Draw() =0;
};

