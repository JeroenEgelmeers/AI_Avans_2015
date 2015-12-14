#pragma once
#include "Animal.h"
#include "IAnimalState.h"

class HareWanderAround : public IAnimalState
{
private:
	//copy ctor and assignment should be private
	HareWanderAround(const HareWanderAround&);
	HareWanderAround& operator=(const HareWanderAround&);

	int stateUpdates, stateUpdatesDone;

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

	int stateUpdates, stateUpdatesDone;

public:
	HareRest() {}
	~HareRest() {}

	void HareRest::Enter(Animal* hare) override;
	void HareRest::Execute(Animal* hare) override;
	void HareRest::Exit(Animal* hare) override;
};

class HareFleeFromCow : public IAnimalState
{
private:
	//copy ctor and assignment should be private
	HareFleeFromCow(const HareFleeFromCow&);
	HareFleeFromCow& operator=(const HareFleeFromCow&);

	int stateUpdates, stateUpdatesDone;

public:
	HareFleeFromCow() {}
	~HareFleeFromCow() {}

	void HareFleeFromCow::Enter(Animal* hare) override;
	void HareFleeFromCow::Execute(Animal* hare) override;
	void HareFleeFromCow::Exit(Animal* hare) override;
};

class HareChaseCow : public IAnimalState
{
private:
	//copy ctor and assignment should be private
	HareChaseCow(const HareChaseCow&);
	HareChaseCow& operator=(const HareChaseCow&);

	int stateUpdates, stateUpdatesDone;

public:
	HareChaseCow() { }
	~HareChaseCow() { }

	void HareChaseCow::Enter(Animal* hare) override;
	void HareChaseCow::Execute(Animal* hare) override;
	void HareChaseCow::Exit(Animal* hare) override;
};


class HareSearchItem : public IAnimalState
{
private:
	//copy ctor and assignment should be private
	HareSearchItem(const HareSearchItem&);
	HareSearchItem& operator=(const HareSearchItem&);

	int stateUpdates, stateUpdatesDone;

public:
	HareSearchItem() { }
	~HareSearchItem() { }

	void HareSearchItem::Enter(Animal* hare) override;
	void HareSearchItem::Execute(Animal* hare) override;
	void HareSearchItem::Exit(Animal* hare) override;
};
