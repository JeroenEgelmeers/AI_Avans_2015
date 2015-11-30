#pragma once
#include "State.h"
class Animal;

//------------------------------------------------------------------------
//
// Haas zal van de koe wegrennen
//
//------------------------------------------------------------------------
class FleeFromCow : public State<Animal>
{
private:
	//copy ctor and assignment should be private
	FleeFromCow(const FleeFromCow&);
	FleeFromCow& operator=(const FleeFromCow&);

	int fleeUpdates;
	int fleeUpdatesDone;

public:
	FleeFromCow() { }

	void FleeFromCow::Enter(Animal* hare) override;
	void FleeFromCow::Execute(Animal* hare) override;
	void FleeFromCow::Exit(Animal* hare) override;
};

//------------------------------------------------------------------------
//
//  haas zal rond lopen
//  
//------------------------------------------------------------------------
class WanderAroundRabbit : public State<Animal>
{
private:
	//copy ctor and assignment should be private
	WanderAroundRabbit(const WanderAroundRabbit&);
	WanderAroundRabbit& operator=(const WanderAroundRabbit&);

	int wanderUpdates;
	int wanderUpdatesDone;

public:
	WanderAroundRabbit() { }

	void WanderAroundRabbit::Enter(Animal* hare) override;
	void WanderAroundRabbit::Execute(Animal* hare) override;
	void WanderAroundRabbit::Exit(Animal* hare) override;
};
