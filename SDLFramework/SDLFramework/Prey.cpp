#include "Prey.h"

Prey::Prey()
{
	mX = 50;
	mY = 50;
	mWidth = 32;
	mHeight = 32;
	mTexture = mApplication->LoadTexture("prey.png");
}

Prey::~Prey()
{
}

void Prey::Update(float deltatime) {
	int screenWidth, screenHeight;

	int *widthPtr = &screenWidth;
	int *heightPtr = &screenHeight;

	mApplication->GetWindowSize(widthPtr, heightPtr);

	if (mY > screenHeight + 16) {
		mY = 0;
	}
	else if (-16 < mY) {
		mY = screenHeight;
	}

	if (mX > screenWidth + 16) {
		mX = 0;
	}
	else if (-16 < mX) {
		mX = screenWidth;
	}

	mY++;
	mX++;
}

void Prey::Draw() {
	mApplication->DrawTextureRotate(mTexture, mX, mY, mWidth, mHeight, 135);
}
