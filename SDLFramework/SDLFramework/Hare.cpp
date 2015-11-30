#include "Hare.h"
#include "HareStates.h"


Hare::Hare(Node * cNode)
{
	mTexture = mApplication->LoadTexture("rabbit-3.png");
	mApplication->AddRenderable(this);
	setCurrentNode(cNode);

	m_pStateMachine = new StateMachine<Animal>(dynamic_cast<Animal*>(this));
	m_pStateMachine->SetCurrentState(WanderAroundCow::Instance());
	m_pStateMachine->CurrentState()->Enter(this);
}

Hare::~Hare()
{
}

void Hare::Draw()
{
	mApplication->DrawTexture(mTexture, currentNode->x, currentNode->y, 75, 75);
}