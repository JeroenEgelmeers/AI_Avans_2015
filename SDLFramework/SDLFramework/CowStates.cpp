#include "CowStates.h"
#include "Animal.h"
#include <random>
#include <iostream>

//------------------------------------------------------------------------methods for ChaseRabbit
void ChaseRabbit::Enter(Animal* cow)
{
	//cow->chase();
}


void ChaseRabbit::Execute(Animal* cow)
{
	//if (cow->getCurrentNode() == hare.CugetCurrentNode())
	//{
	//	cow->GetFSM()->ChangeState(WanderAroundCow::Instance());
	//	return;
	//}

}


void ChaseRabbit::Exit(Animal* cow)
{ }

//------------------------------------------------------------------------methods for WanderAround
void WanderAroundCow::Enter(Animal* cow)
{
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(1, 6);
	wanderUpdates = dist1(dre);
}


void WanderAroundCow::Execute(Animal* cow)
{
	if (wanderUpdatesDone >= wanderUpdates)
	{
		//cow->GetFSM()->ChangeState(ChaseRabbit::Instance());
		wanderUpdates = 0;
		return;
	}

	//cow->wander();
}


void WanderAroundCow::Exit(Animal* cow)
{ }
