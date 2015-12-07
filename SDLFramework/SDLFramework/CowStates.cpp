#include "CowStates.h"
#include "Animal.h"
#include <random>
#include <iostream>
#include "StateFactory.h"
#include "Graph.h"

//------------------------------------------------------------------------methods for ChaseRabbit
void CowChaseHare::Enter(Animal* cow)
{
	//this->fectory = new StateFactory();
}

void CowChaseHare::Execute(Animal* cow)
{
	// int path = mGraph->AStar(mGraph->GetNodePosition(mCow->getCurrentNode()), mGraph->GetNodePosition(mHare->getCurrentNode()));
	int path = cow->GetGraph()->AStar(cow->GetGraph()->GetNodePosition(cow->getCurrentNode()), 0);
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
	wanderUpdates = dist1(dre);
	wanderUpdatesDone = 0;
}

void CowWanderAround::Execute(Animal* cow)
{
	if (wanderUpdatesDone <= wanderUpdates)
	{
		++wanderUpdatesDone;
		cow->setCurrentNode(cow->GetGraph()->GetNode(cow->GetGraph()->GetNewNeighborNode(cow->GetGraph()->GetNodePosition(cow->getCurrentNode()))));
	}
	else
	{
		cow->GetFSM()->ChangeState(new CowChaseHare());
	}
}

void CowWanderAround::Exit(Animal* cow)
{
	wanderUpdates = 0;
	wanderUpdatesDone = 0;
}
