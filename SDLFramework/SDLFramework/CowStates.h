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

	ChaseRabbit()
	{}

	//copy ctor and assignment should be private
	ChaseRabbit(const ChaseRabbit&);
	ChaseRabbit& operator=(const ChaseRabbit&);

public:

	//this is a singleton
	static ChaseRabbit* Instance();

	virtual void Enter(Cow* Cow);

	virtual void Execute(Cow* Cow);

	virtual void Exit(Cow* Cow);
};

//------------------------------------------------------------------------
//
//  De koe zal doelloos rondlopen
//  
//------------------------------------------------------------------------
class WanderAroundCow : public State<Animal>
{
private:

	WanderAroundCow()
	{}

	//copy ctor and assignment should be private
	WanderAroundCow(const WanderAroundCow&);
	WanderAroundCow& operator=(const WanderAroundCow&);
	int wanderUpdatesRequired;

public:

	//this is a singleton
	static WanderAroundCow* Instance();

	virtual void Enter(Cow* Cow);

	virtual void Execute(Cow* Cow);

	virtual void Exit(Cow* Cow);
};
