#include "Animal.h"
int Animal::m_iNextValidId = 0;

Animal::Animal(int id)
{
	SetID(id);
}

void Animal::setCurrentNode(Node* cNode)
{
	currentNode = cNode;
}

void Animal::Draw()
{
}

void Animal::SetID(int val)
{
	if (val >= m_iNextValidId)
	{
		m_ID = val;
		m_iNextValidId++;
	}
}

Animal::~Animal()
{
}