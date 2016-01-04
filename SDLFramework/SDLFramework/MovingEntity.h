#pragma once

#include "IGameObject.h"
#include "Vector.h"


class MovingEntity : public IGameObject
{
protected:
	Vector m_Velocity;
	Vector m_Heading;
	Vector m_Side;

	float f_Mass;
	float m_MaxSpeed;
	float m_MaxForce;
	float m_MaxTurnRate;

	void TorroidBehaviour();

	Vector Approach(Vector vGoal, Vector vCurrent, float dt);
public:
	MovingEntity();
	~MovingEntity();

	virtual void Update(float deltatime) =0;
	virtual void Draw() =0;

	FWApplication* GetLevel() {
		return mApplication;
	}

	Vector GetHeading() const {
		return m_Heading;
	}

	Vector GetVelocity() const {
		return m_Velocity;
	}
};

