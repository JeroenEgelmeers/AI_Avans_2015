#include "CowStates.h"
#include "Animal.h"
#include <random>
#include <iostream>
#include "StateFactory.h"

//------------------------------------------------------------------------methods for ChaseRabbit
void CowChaseHare::Enter(Animal* cow)
{
	//this->fectory = new StateFactory();
}

void CowChaseHare::Execute(Animal* cow)
{

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
	if (wanderUpdatesDone >= wanderUpdates)
	{
		cow->GetFSM()->ChangeState(new CowChaseHare());
		return;
	}
}

void CowWanderAround::Exit(Animal* cow)
{
	wanderUpdates = 0;
	wanderUpdatesDone = 0;
}
