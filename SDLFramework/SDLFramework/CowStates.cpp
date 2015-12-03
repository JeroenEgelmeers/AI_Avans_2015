#include "CowStates.h"
#include "Animal.h"
#include <random>
#include <iostream>
#include "StateFactory.h"

//------------------------------------------------------------------------methods for ChaseRabbit
void ChaseRabbit::Enter(Animal* cow)
{
	this->fectory = new StateFactory();
	//cow->chase();
}

void ChaseRabbit::Execute(Animal* cow)
{
	//if (cow->getCurrentNode() == hare.CugetCurrentNode())
	//{
		cow->GetFSM()->ChangeState(new ChaseRabbit());
	//	return;
	//}
}

void ChaseRabbit::Exit(Animal* cow)
{
	delete this->fectory;
}

//------------------------------------------------------------------------methods for WanderAround
void WanderAroundCow::Enter(Animal* cow)
{
	this->fectory = new StateFactory();
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(1, 6);
	wanderUpdates = dist1(dre);
	wanderUpdatesDone = 0;
}

void WanderAroundCow::Execute(Animal* cow)
{
	if (wanderUpdatesDone >= wanderUpdates)
	{
		cow->GetFSM()->ChangeState();
		return;
	}

	//cow->wander();
}

void WanderAroundCow::Exit(Animal* cow)
{
	delete this->fectory;
	wanderUpdates = 0;
	wanderUpdatesDone = 0;
}
