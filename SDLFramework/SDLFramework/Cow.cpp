#include "Cow.h"
#include "CowStates.h"
#include "Graph.h"
#include "Item.h"

Cow::Cow(Node* cNode)
{
	mTexture = mApplication->LoadTexture("cow-1.png");
	mApplication->AddRenderable(this);
	setCurrentNode(cNode);
	
	m_pStateMachine = new StateMachine2<Animal>(dynamic_cast<Animal*>(this));
	m_pStateMachine->SetCurrentState(new CowChaseHare());
	m_pStateMachine->CurrentState()->Enter(this);
}

Cow::~Cow(){ }

void Cow::Update(float dt)
{
	this->GetFSM()->CurrentState()->Execute(dynamic_cast<Animal*>(this));
}

void Cow::Draw() 
{
	mApplication->SetColor(Color(0, 0, 0, 255));
	mApplication->DrawTexture(mTexture, currentNode->x, currentNode->y, 75, 75);
	mApplication->DrawText(GetFSM()->GetNameOfCurrentState(), currentNode->x + 50, currentNode->y - 50);
	mApplication->SetColor(Color(255, 255, 255, 255));
}

void Cow::SetGraph(Graph* g)
{
	this->graph = g;
	g->SetCowTarget(dynamic_cast<Cow*>(this));
}

void Cow::ChangeState(StateEnum state)
{
	if (state < StateEnum::eEndCowStates)
	{
		this->GetFSM()->ChangeState(this->factory->CreateNewSate(state));
	}
}

void Cow::SearchItem(Item* _item)
{
	SetItemTargetNode(GetGraph()->GetNodeIndex(_item->getCurrentNode()));
}
