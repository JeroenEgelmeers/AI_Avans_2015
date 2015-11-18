#include "Hare.h"



Hare::Hare(Node * cNode)
{
	mTexture = mApplication->LoadTexture("rabbit-3.png");
	mApplication->AddRenderable(this);
	setCurrentNode(cNode);
	mX = currentNode->x;
	mY = currentNode->y;
}

Hare::~Hare()
{
}

void Hare::Draw()
{
	mApplication->DrawTexture(mTexture, mX, mY, 100, 100);
}