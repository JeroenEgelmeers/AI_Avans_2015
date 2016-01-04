#include "MovingEntity.h"

MovingEntity::MovingEntity()
{
}

MovingEntity::~MovingEntity()
{
}

void MovingEntity::TorroidBehaviour(){
	int screenWidth, screenHeight;

	int *widthPtr = &screenWidth;
	int *heightPtr = &screenHeight;

	mApplication->GetWindowSize(widthPtr, heightPtr);

	if (m_Position.y >= screenHeight + 32) {
		m_Position.y = 0;
	}
	else if (m_Position.y < - 32) {
		m_Position.y = (float)screenHeight;
	}

	if (m_Position.x > screenWidth + 32) {
		m_Position.x = 0;
	}
	else if (m_Position.x < - 32) {
		m_Position.x = (float)screenWidth;
	}
}

Vector MovingEntity::Approach(Vector vGoal, Vector vCurrent, float dt) {
	vGoal*dt;
	vCurrent*(1.f - dt);
	return vGoal + vCurrent;
}

void MovingEntity::ApplyForce(Vector force) {
	force / f_Mass;
	m_Acceleration += force;
}