#include "Cow.h"

Cow::Cow(Node* cNode)
{
	mTexture = mApplication->LoadTexture("cow-1.png");
	mApplication->AddRenderable(this);
	setCurrentNode(cNode);
}

Cow::~Cow(){ }

void Cow::Draw() 
{
	mApplication->DrawTexture(mTexture, mX, mY, 100, 100);
}