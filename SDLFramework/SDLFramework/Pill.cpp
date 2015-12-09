#include "Pill.h"

Pill::Pill(Node* cNode)
{
	mTexture = mApplication->LoadTexture("pill.png");
	mApplication->AddRenderable(this);
	setCurrentNode(cNode);
}

Pill::~Pill()
{
}

void Pill::Draw()
{
	mApplication->DrawTexture(mTexture, currentNode->x, currentNode->y, 75, 75);
}

void Pill::ChangeState(Animal animal)
{
	if (typeid(animal).name() == "Cow") {
		animal.ChangeState(StateEnum::eCowChaseHare);
	}
}
