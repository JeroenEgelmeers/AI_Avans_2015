#include "Pill.h"
#include <iostream>
using namespace std;

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
	if (!TakenByAnimal) {
		mApplication->DrawTexture(mTexture, currentNode->x, currentNode->y, 75, 75);
	}
}

void Pill::ChangeState(Animal* animal)
{
		// TODO check if it's a cow!
		animal->ChangeState(StateEnum::eHareWanderAround);
		TakenByAnimal = true;
}
