#include "CowStates.h"
#include "Animal.h"
#include <random>
#include <iostream>
#include "StateFactory.h"
#include "Graph.h"

//------------------------------------------------------------------------methods for ChaseRabbit
void CowChaseHare::Enter(Animal* cow)
{ }

void CowChaseHare::Execute(Animal* cow)
{
	int path = cow->GetGraph()->AStar(cow->GetGraph()->GetCowTargetNode(), cow->GetGraph()->GetHareTargetNode());
	cow->setCurrentNode(cow->GetGraph()->GetNode(path));
}

void CowChaseHare::Exit(Animal* cow)
{
	
}

//------------------------------------------------------------------------methods for WanderAround
void CowWanderAround::Enter(Animal* cow)
{
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(1, 6);
	//int stateUpdates, stateUpdatesDone;
	stateUpdates = dist1(dre);
	stateUpdatesDone = 0;
}

void CowWanderAround::Execute(Animal* cow)
{
	if (stateUpdatesDone <= stateUpdates)
	{
		++stateUpdatesDone;
		cow->setCurrentNode(cow->GetGraph()->GetNode(cow->GetGraph()->GetNewNeighborNode(cow->GetGraph()->GetNodePosition(cow->getCurrentNode()))));
	}
	else
	{
		cow->ChangeState(StateEnum::eCowChaseHare);
	}
}

void CowWanderAround::Exit(Animal* cow)
{
	stateUpdates = 0;
	stateUpdatesDone = 0;
}

//----------------------------------------------------------------------methodes for CowRest
void CowRest::Enter(Animal* cow)
{
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(1, 3);
	stateUpdates = dist1(dre);
	stateUpdatesDone = 0;
}

void CowRest::Execute(Animal* cow)
{
	if (stateUpdatesDone <= stateUpdates)
		++stateUpdatesDone;
	else
		cow->ChangeState(StateEnum::eCowWanderAround);
}

void CowRest::Exit(Animal* hare)
{
	stateUpdates = 0;
	stateUpdatesDone = 0;
}