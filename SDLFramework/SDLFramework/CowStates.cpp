#include "CowStates.h"
#include "Animal.h"
#include <random>
#include <iostream>
#include "StateFactory.h"
#include "Graph.h"

// ------------------------------------------------------------------------methods for CowChaseHare
void CowChaseHare::Enter(Animal* cow) { }

void CowChaseHare::Execute(Animal* cow)
{
	int path = cow->GetGraph()->AStar(cow->GetGraph()->GetCowTargetNode(), cow->GetGraph()->GetHareTargetNode());
	cow->setCurrentNode(cow->GetGraph()->GetNode(path));
}

void CowChaseHare::Exit(Animal* cow) { }

// ------------------------------------------------------------------------ methods for CowWanderAround
void CowWanderAround::Enter(Animal* cow)
{
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(1, 6);
	stateUpdates = dist1(dre);
	stateUpdatesDone = 0;
}

void CowWanderAround::Execute(Animal* cow)
{
	cow->setCurrentNode(cow->GetGraph()->GetNode(cow->GetGraph()->GetNewNeighborNode(cow->GetGraph()->GetNodePosition(cow->getCurrentNode()))));
}

void CowWanderAround::Exit(Animal* cow)
{
	stateUpdates = 0;
	stateUpdatesDone = 0;
}

// ---------------------------------------------------------------------- methodes for CowRest
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

// ---------------------------------------------------------------------- methodes for CowFleeFromHare
void CowFleeFromHare::Enter(Animal* cow)
{
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(4, 6);
	stateUpdates = dist1(dre);
	stateUpdatesDone = 0;
}

void CowFleeFromHare::Execute(Animal* cow)
{
	if (stateUpdatesDone <= stateUpdates)
	{
		++stateUpdatesDone;
		int targetNode = cow->GetGraph()->GetFarthestHeuristicNode(cow->GetGraph()->GetCowTargetNode());
		int path = cow->GetGraph()->AStar(cow->GetGraph()->GetCowTargetNode(), targetNode);
		cow->setCurrentNode(cow->GetGraph()->GetNode(path));

	}
	//else if (false) // hare has pill
	//{
	//	cow->ChangeState(StateEnum::eHareWanderAround);
	//}
	//else if (false) // hare has gun
	//{
	//	cow->ChangeState(StateEnum::eHareChaseCow);
	//}
	//else if (stateUpdatesDone > stateUpdates) // fleeing done
	//{
	//	cow->ChangeState(StateEnum::eHareRest);
	//}
}

void CowFleeFromHare::Exit(Animal* hare)
{
	stateUpdates = 0;
	stateUpdatesDone = 0;
}
