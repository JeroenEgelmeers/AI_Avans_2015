#include "Prey.h"
#include <cstdlib>

Prey::Prey()
{
	mId = ObjectId::PREY;
	mSteering = new PreySteeringBehaviors(this);

	int mScreenWidth, mScreenHeight;

	int *widthPtr = &mScreenWidth;
	int *heightPtr = &mScreenHeight;
	mApplication->GetWindowSize(widthPtr, heightPtr);
	m_Position = Vector((float)(rand() % mScreenWidth + 1), (float)(rand() % mScreenHeight + 1));
	m_Heading = Vector((float)(rand() % 20 + 1) / 10 -1, (float)(rand() % 20 + 1) / 10 - 1);

	m_Velocity = Vector(0, 0);
	
	f_Mass = 10;
	mWidth = 32;
	mHeight = 32;
	m_MaxSpeed = 4;
	m_MaxForce = 0.1;
	mTexture = mApplication->LoadTexture("prey.png");
}

Prey::~Prey()
{
}

void Prey::Update(float deltatime) {
	TorroidBehaviour();

	Vector desired = mSteering->Calculate();
	desired.Normalize();
	desired * m_MaxSpeed;

	Vector steer = desired - m_Velocity;
	steer.Limit(m_MaxForce);
	ApplyForce(steer);

	m_Velocity += m_Acceleration;
	m_Position += m_Velocity;
	m_Acceleration * 0;
}

void Prey::Draw() {
	mApplication->DrawTextureRotate(mTexture, (int)m_Position.x, (int)m_Position.y, mWidth, mHeight, m_Velocity.Heading());
}
