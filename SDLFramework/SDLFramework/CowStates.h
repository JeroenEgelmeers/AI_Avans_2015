#pragma once
#include "State.h"
#include "StateFactory.h"
#include "IAnimalState.h"
class Animal;

//------------------------------------------------------------------------
//
//  Koe zal achter de haas aan gaan om deze proberen te vangen
//  
//------------------------------------------------------------------------
class CowChaseHare : public IAnimalState
{
private:
	//copy ctor and assignment should be private
	CowChaseHare(const CowChaseHare&);
	CowChaseHare& operator=(const CowChaseHare&);

public:
	CowChaseHare() {}

	virtual void CowChaseHare::Enter(Animal* Cow) override;
	virtual void CowChaseHare::Execute(Animal* Cow) override;
	virtual void CowChaseHare::Exit(Animal* Cow) override;
};

//------------------------------------------------------------------------
//
//  De koe zal doelloos rondlopen
//  
//------------------------------------------------------------------------
class CowWanderAround : public IAnimalState
{
private:
	//copy ctor and assignment should be private
	CowWanderAround(const CowWanderAround&);
	CowWanderAround& operator=(const CowWanderAround&);
	int stateUpdates, stateUpdatesDone;

public:
	CowWanderAround() { }
	~CowWanderAround() { }

	virtual void CowWanderAround::Enter(Animal* Cow) override;
	virtual void CowWanderAround::Execute(Animal* Cow) override;
	virtual void CowWanderAround::Exit(Animal* Cow) override;
};

class CowRest : public IAnimalState
{
	private:
		//copy ctor and assignment should be private
		CowRest(const CowRest&);
		CowRest& operator=(const CowRest&);
		int stateUpdates, stateUpdatesDone;

	public:
		CowRest() { }
		~CowRest() { }

		virtual void CowRest::Enter(Animal* Cow) override;
		virtual void CowRest::Execute(Animal* Cow) override;
		virtual void CowRest::Exit(Animal* Cow) override;
};
