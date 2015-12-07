#include "HareStates.h"
#include <random>
#include "Animal.h"
#include "Graph.h"

//------------------------------------------------------------------------methods for FleeFromCow
void HareFleeFromCow::Enter(Animal* hare)
{
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(1, 6);
	fleeUpdates = dist1(dre);
	fleeUpdatesDone = 0;
}

void HareFleeFromCow::Execute(Animal* hare)
{
	
}

void HareFleeFromCow::Exit(Animal* hare)
{
	fleeUpdates = 0;
	fleeUpdatesDone = 0;
}

//------------------------------------------------------------------------methods for WanderAround
void HareWanderAround::Enter(Animal* hare)
{
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(1, 6);
	//wanderUpdates = dist1(dre);
	wanderUpdates = 3;
	wanderUpdatesDone = 0;
}

void HareWanderAround::Execute(Animal* hare)
{
	if (wanderUpdatesDone <= wanderUpdates)
	{
		++wanderUpdatesDone;
		hare->setCurrentNode(hare->GetGraph()->GetNode(hare->GetGraph()->GetNewNeighborNode(hare->GetGraph()->GetNodePosition(hare->getCurrentNode()))));
	}
	else
	{
		hare->GetFSM()->ChangeState(new HareRest);
	}
}

void HareWanderAround::Exit(Animal* hare)
{
	wanderUpdates = 0;
	wanderUpdatesDone = 0;
}
//----------------------------------------------------------------------methodes
void HareRest::Enter(Animal* hare)
{
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(1, 3);
	//restUpdates = dist1(dre);
	restUpdates = 2;
	restUpdatesDone = 0;
}

void HareRest::Execute(Animal* hare)
{
	if (restUpdatesDone <= restUpdates)
		++restUpdatesDone;
	else
		hare->GetFSM()->ChangeState(new HareWanderAround());
}

void HareRest::Exit(Animal* hare)
{
	restUpdates = 0;
	restUpdatesDone = 0;
}
