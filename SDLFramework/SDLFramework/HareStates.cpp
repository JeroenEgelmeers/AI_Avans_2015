#include "HareStates.h"
#include <random>
#include "Animal.h"

//------------------------------------------------------------------------methods for FleeFromCow
void FleeFromCow::Enter(Animal* hare)
{
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(1, 6);
	fleeUpdates = dist1(dre);
	fleeUpdatesDone = 0;
}

void FleeFromCow::Execute(Animal* hare)
{
	
}

void FleeFromCow::Exit(Animal* hare)
{
	fleeUpdates = 0;
	fleeUpdatesDone = 0;
}

//------------------------------------------------------------------------methods for WanderAround
void WanderAroundRabbit::Enter(Animal* hare)
{
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(1, 6);
	wanderUpdates = dist1(dre);
	wanderUpdatesDone = 0;
}

void WanderAroundRabbit::Execute(Animal* hare)
{
	if (wanderUpdatesDone <= wanderUpdates)
	{
		// do stuff
	}
}

void WanderAroundRabbit::Exit(Animal* hare)
{
	wanderUpdates = 0;
	wanderUpdatesDone = 0;
}
