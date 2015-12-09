#include "Gun.h"

Gun::Gun(Node* cNode)
{
	mTexture = mApplication->LoadTexture("gun-metal.png");
	mApplication->AddRenderable(this);
	setCurrentNode(cNode);
}

Gun::~Gun()
{
}

void Gun::Draw()
{
	mApplication->DrawTexture(mTexture, currentNode->x, currentNode->y, 75, 75);
}

void Gun::ChangeState(Animal animal)
{
	if (typeid(animal).name() == "Hare") {
		animal.ChangeState(StateEnum::eHareChaseCow);
	}
}
