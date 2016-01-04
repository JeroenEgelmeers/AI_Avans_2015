#include "HareStates.h"
#include <random>
#include "Animal.h"
#include "Graph.h"

//------------------------------------------------------------------------methods for WanderAround
void HareWanderAround::Enter(Animal* hare)
{
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(1, 6);
	stateUpdates = dist1(dre);
	stateUpdatesDone = 0;
}

void HareWanderAround::Execute(Animal* hare)
{
	if (stateUpdatesDone <= stateUpdates)
	{
		++stateUpdatesDone;
		hare->setCurrentNode(hare->GetGraph()->GetNode(hare->GetGraph()->GetNewNeighborNode(hare->GetGraph()->GetNodePosition(hare->getCurrentNode()))));
	}
	else
	{
		std::random_device dev;
		std::default_random_engine dre(dev());
		std::uniform_int_distribution<int> dist1(1, 100);
		int temp = dist1(dre);
		if (temp < 51)
			hare->ChangeState(StateEnum::eHareRest);
		else
			hare->ChangeState(StateEnum::eHareSearchGun);
	}
}

void HareWanderAround::Exit(Animal* hare)
{
	stateUpdates = 0;
	stateUpdatesDone = 0;
}
//----------------------------------------------------------------------methodes
void HareRest::Enter(Animal* hare)
{
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(1, 3);
	stateUpdates = dist1(dre);
	stateUpdatesDone = 0;
}

void HareRest::Execute(Animal* hare)
{
	if (stateUpdatesDone <= stateUpdates)
		++stateUpdatesDone;
	else
		hare->ChangeState(StateEnum::eHareWanderAround);
}

void HareRest::Exit(Animal* hare)
{
	stateUpdates = 0;
	stateUpdatesDone = 0;
}

//------------------------------------------------------------------------methods for FleeFromCow
void HareFleeFromCow::Enter(Animal* hare)
{
	// int stateUpdates, stateUpdatesDone;
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(4, 6);
	stateUpdates = dist1(dre);
	stateUpdatesDone = 0;
}

void HareFleeFromCow::Execute(Animal* hare)
{
	if (stateUpdatesDone <= stateUpdates)
	{
		++stateUpdatesDone;
		int targetNode = hare->GetGraph()->GetFarthestHeuristicNode(hare->GetGraph()->GetHareTargetNode());
		int path = hare->GetGraph()->AStar(hare->GetGraph()->GetCowTargetNode(), targetNode);
		hare->setCurrentNode(hare->GetGraph()->GetNode(path));
	}
}

void HareFleeFromCow::Exit(Animal* hare)
{
	stateUpdates = 0;
	stateUpdatesDone = 0;
}


//------------------------------------------------------------------------methods for HareChaseCow
void HareChaseCow::Enter(Animal* hare) { }

void HareChaseCow::Execute(Animal* hare)
{
	int path = hare->GetGraph()->AStar(hare->GetGraph()->GetHareTargetNode(), hare->GetGraph()->GetCowTargetNode());
	hare->setCurrentNode(hare->GetGraph()->GetNode(path));
}

void HareChaseCow::Exit(Animal* hare) { }

//------------------------------------------------------------------------methods for HareChaseCow
void HareSearchGun::Enter(Animal* hare) {}

void HareSearchGun::Execute(Animal* hare)
{
	int path = hare->GetGraph()->AStar(hare->GetGraph()->GetHareTargetNode(), hare->GetGraph()->GetGunTargetNode());
	hare->setCurrentNode(hare->GetGraph()->GetNode(path));
}

void HareSearchGun::Exit(Animal* hare) {}
