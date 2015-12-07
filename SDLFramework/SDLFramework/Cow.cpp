#include "Cow.h"

Cow::Cow(Node* cNode, int ID)
{
	mTexture = mApplication->LoadTexture("cow-1.png");
	mApplication->AddRenderable(this);
	setCurrentNode(cNode);
}

Cow::~Cow(){ }

void Cow::Draw() 
{
	mApplication->DrawTexture(mTexture, currentNode->x, currentNode->y, 75, 75);
}

void Cow::Update()
{
}

void Cow::ChangeState(State * pNewState)
{
	//make sure both states are valid before attempting to 
	//call their methods
	assert(m_pCurrentState && pNewState);

	// call the exit method of the excisting state
	m_pCurrentState->Exit(this);

	//change state to the new state
	m_pCurrentState = pNewState;

	//call the entry method of the new state
	m_pCurrentState->Enter(this);
}


