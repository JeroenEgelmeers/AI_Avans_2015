#include "Cow.h"
#include "CowStates.h"

Cow::Cow(Node* cNode)
{
	mTexture = mApplication->LoadTexture("cow-1.png");
	mApplication->AddRenderable(this);
	setCurrentNode(cNode);
	
	m_pStateMachine = new StateMachine<Animal>(dynamic_cast<Animal*>(this));
	m_pStateMachine->SetCurrentState(WanderAroundCow::Instance());
	m_pStateMachine->CurrentState()->Enter(this);
}

Cow::~Cow(){ }

void Cow::Draw() 
{
	mApplication->DrawTexture(mTexture, currentNode->x, currentNode->y, 75, 75);
}