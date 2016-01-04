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

	if (m_Position.y >= screenHeight + 16) {
		m_Position.y = 0;
	}
	else if (m_Position.y < - 16) {
		m_Position.y = screenHeight;
	}

	if (m_Position.x > screenWidth + 16) {
		m_Position.x = 0;
	}
	else if (m_Position.x < - 16) {
		m_Position.x = screenWidth;
	}
}

Vector MovingEntity::Approach(Vector vGoal, Vector vCurrent, float dt) {
	return vGoal*dt + vCurrent*(1.f - dt);
}