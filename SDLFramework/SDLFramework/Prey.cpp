#include "Prey.h"
#include <cstdlib>

Prey::Prey()
{
	mId = ObjectId::PREY;
	mSteering = new PreySteeringBehaviors(this);

	m_Position = Vector(rand() % 1920+ 1, rand() % 1080 + 1);
	m_Heading = Vector((float)(rand() % 20 + 1) / 10 -1, (float)(rand() % 20 + 1) / 10 - 1);

	m_Velocity = Vector(rand() % 200 + 1, rand() % 200 + 1);

	mWidth = 32;
	mHeight = 32;
	mTexture = mApplication->LoadTexture("prey.png");
}

Prey::~Prey()
{
}

void Prey::Update(float deltatime) {
	TorroidBehaviour();

	Vector stForce = mSteering->Calculate();
	if ((stForce.x == 0 && stForce.y == 0) == false) {
		m_Heading = Approach(stForce, m_Heading, deltatime);
	}
	m_Heading.Normalize();

	m_Position.y += (m_Heading.y * m_Velocity.y) * deltatime;
	m_Position.x += (m_Heading.x * m_Velocity.x) * deltatime;
}

void Prey::Draw() {
	mApplication->DrawTextureRotate(mTexture, (int)m_Position.x, (int)m_Position.y, mWidth, mHeight, m_Heading.Angle());
}
