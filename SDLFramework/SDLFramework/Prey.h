#pragma once
#include "MovingEntity.h"
class Prey : public MovingEntity
{
public:
	Prey();
	~Prey();

	void Update(float deltatime);
	void Draw();
};

