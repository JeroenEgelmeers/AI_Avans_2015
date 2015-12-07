//#pragma once
//#include "State.h"
//class Animal;
//
////------------------------------------------------------------------------
////
//// Haas zal van de koe wegrennen
////
////------------------------------------------------------------------------
//class FleeFromCow : public State<Animal>
//{
//private:
//	//copy ctor and assignment should be private
//	FleeFromCow(const FleeFromCow&);
//	FleeFromCow& operator=(const FleeFromCow&);
//
//	int fleeUpdates;
//	int fleeUpdatesDone;
//
//public:
//	FleeFromCow() { }
//
//	void FleeFromCow::Enter(Animal* hare) override;
//	void FleeFromCow::Execute(Animal* hare) override;
//	void FleeFromCow::Exit(Animal* hare) override;
//};
//
////------------------------------------------------------------------------
////
////  haas zal rond lopen
////  
////------------------------------------------------------------------------
//class WanderAroundHare : public State<Animal>
//{
//private:
//	//copy ctor and assignment should be private
//	WanderAroundHare(const WanderAroundHare&);
//	WanderAroundHare& operator=(const WanderAroundHare&);
//
//	int wanderUpdates;
//	int wanderUpdatesDone;
//
//public:
//	WanderAroundHare() {}
//
//	void WanderAroundHare::Enter(Animal* hare) override;
//	void WanderAroundHare::Execute(Animal* hare) override;
//	void WanderAroundHare::Exit(Animal* hare) override;
//};
#pragma once
#include "Animal.h"
#include "IAnimalState.h"

class HareFleeFromCow : public IAnimalState
{
private:
	//copy ctor and assignment should be private
	HareFleeFromCow(const HareFleeFromCow&);
	HareFleeFromCow& operator=(const HareFleeFromCow&);

	int fleeUpdates;
	int fleeUpdatesDone;

public:
	HareFleeFromCow() {}
	~HareFleeFromCow() {}

	void HareFleeFromCow::Enter(Animal* hare) override;
	void HareFleeFromCow::Execute(Animal* hare) override;
	void HareFleeFromCow::Exit(Animal* hare) override;
};

class HareWanderAround : public IAnimalState
{
private:
	//copy ctor and assignment should be private
	HareWanderAround(const HareWanderAround&);
	HareWanderAround& operator=(const HareWanderAround&);

	int wanderUpdates;
	int wanderUpdatesDone;

public:
	HareWanderAround() {}
	~HareWanderAround() {}

	void HareWanderAround::Enter(Animal* hare) override;
	void HareWanderAround::Execute(Animal* hare) override;
	void HareWanderAround::Exit(Animal* hare) override;
};

class HareRest : public IAnimalState
{
private:
	//copy ctor and assignment should be private
	HareRest(const HareRest&);
	HareRest& operator=(const HareRest&);

	int restUpdates;
	int restUpdatesDone;

public:
	HareRest()
	{}
	~HareRest()
	{}

	void HareRest::Enter(Animal* hare) override;
	void HareRest::Execute(Animal* hare) override;
	void HareRest::Exit(Animal* hare) override;
};
