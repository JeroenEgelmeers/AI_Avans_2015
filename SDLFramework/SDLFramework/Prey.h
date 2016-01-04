#pragma once
#include "MovingEntity.h"
#include "PreySteeringBehaviors.h"

class Prey : public MovingEntity
{
private:
	PreySteeringBehaviors* mSteering = nullptr;
public:
	Prey();
	~Prey();

	void Update(float deltatime);
	void Draw();
};

