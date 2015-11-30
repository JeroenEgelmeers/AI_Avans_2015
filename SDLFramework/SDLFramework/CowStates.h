#pragma once
#include "State.h"
class Animal;

//------------------------------------------------------------------------
//
//  Koe zal achter de haas aan gaan om deze proberen te vangen
//  
//------------------------------------------------------------------------
class ChaseRabbit : public State<Animal>
{
private:
	//copy ctor and assignment should be private
	ChaseRabbit(const ChaseRabbit&);
	ChaseRabbit& operator=(const ChaseRabbit&);

public:
	ChaseRabbit() { }

	virtual void Enter(Animal* Cow);

	virtual void Execute(Animal* Cow);

	virtual void Exit(Animal* Cow);
};

//------------------------------------------------------------------------
//
//  De koe zal doelloos rondlopen
//  
//------------------------------------------------------------------------
class WanderAroundCow : public State<Animal>
{
private:
	//copy ctor and assignment should be private
	WanderAroundCow(const WanderAroundCow&);
	WanderAroundCow& operator=(const WanderAroundCow&);
	int wanderUpdates, wanderUpdatesDone;

public:
	WanderAroundCow() { }

	virtual void WanderAroundCow::Enter(Animal* Cow) override;
	virtual void WanderAroundCow::Execute(Animal* Cow) override;
	virtual void WanderAroundCow::Exit(Animal* Cow) override;
};
