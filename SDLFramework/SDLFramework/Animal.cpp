#include "Animal.h"

Animal::Animal()
{
}


Animal::~Animal()
{
}

void Animal::setCurrentNode(Node * cNode)
{
	currentNode = cNode;
	mX = currentNode->x;
	mY = currentNode->y;
}

void Animal::Draw()
{
}

void Animal::Update(float deltaTime)
{
}
