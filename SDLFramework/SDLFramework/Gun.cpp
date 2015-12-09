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
	if (!TakenByAnimal) {
		mApplication->DrawTexture(mTexture, currentNode->x, currentNode->y, 75, 75);
	}
}

void Gun::ChangeState(Animal* animal)
{
	// TODO check if it's a hare!
	animal->ChangeState(StateEnum::eHareChaseCow);
	TakenByAnimal = true;
}
