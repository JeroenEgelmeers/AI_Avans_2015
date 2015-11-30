#pragma once
#include "State.h"
class Animal;
class Hare;

//------------------------------------------------------------------------
//
// Haas zal van de koe wegrennen
//  
//------------------------------------------------------------------------
class FleeFromCow : public State<Animal>
{
private:

	FleeFromCow() {}

	//copy ctor and assignment should be private
	FleeFromCow(const FleeFromCow&);
	FleeFromCow& operator=(const FleeFromCow&);

	int updatesSince;
	int updateDelay;

	int fleeUpdates;
	int fleeUpdatesDone;

public:

	//this is a singleton
	static FleeFromCow* Instance();

	virtual void Enter(Hare* rabbit);

	virtual void Execute(Hare* rabbit);

	virtual void Exit(Hare* rabbit);
};

//------------------------------------------------------------------------
//
//  haas zal rond lopen
//  
//------------------------------------------------------------------------
class WanderAroundRabbit : public State<Animal>
{
private:

	WanderAroundRabbit() {}

	//copy ctor and assignment should be private
	WanderAroundRabbit(const WanderAroundRabbit&);
	WanderAroundRabbit& operator=(const WanderAroundRabbit&);

public:

	//this is a singleton
	static WanderAroundRabbit* Instance();

	virtual void Enter(Hare* rabbit);

	virtual void Execute(Hare* rabbit);

	virtual void Exit(Hare* rabbit);
};
