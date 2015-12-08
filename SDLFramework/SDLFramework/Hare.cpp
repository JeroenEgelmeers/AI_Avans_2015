#include "Hare.h"
#include "HareStates.h"
#include "Graph.h"

Hare::Hare(Node * cNode)
{
	mTexture = mApplication->LoadTexture("rabbit-3.png");
	mApplication->AddRenderable(this);
	setCurrentNode(cNode);

	m_pStateMachine = new StateMachine2<Animal>(dynamic_cast<Animal*>(this));
	m_pStateMachine->SetCurrentState(new HareWanderAround());
	m_pStateMachine->CurrentState()->Enter(dynamic_cast<Animal*>(this));
}

Hare::~Hare()
{
}

void Hare::Update(float dt)
{
	this->GetFSM()->CurrentState()->Execute(dynamic_cast<Animal*>(this));
}

void Hare::Draw()
{
	mApplication->DrawTexture(mTexture, currentNode->x, currentNode->y, 75, 75);
	mApplication->DrawText(GetFSM()->GetNameOfCurrentState(), currentNode->x + 50, currentNode->y - 50);
}

void Hare::SetGraph(Graph* g)
{
	this->graph = g;
	g->SetHareTarget(dynamic_cast<Hare*>(this));
}

void Hare::ChangeState(StateEnum state)
{
	if (state > StateEnum::eEndCowStates)
	{
		this->GetFSM()->ChangeState(this->factory->CreateNewSate(state));
	}
}
