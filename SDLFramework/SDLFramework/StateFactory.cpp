#include "StateFactory.h"
#include "CowStates.h"
#include "HareStates.h"



StateFactory::StateFactory() {}

StateFactory::~StateFactory() {}

IAnimalState* StateFactory::CreateNewSate(StateEnum number)
{
	switch (number)
	{
	case eCowWanderAround:
		return new CowWanderAround();
		break;
	case eCowChaseHare:
		return new CowChaseHare();
		break;
	case eHareWanderAround:
		return new HareWanderAround();
		break;
	case eHareFleeFromCow:
		return new HareFleeFromCow();
		break;
	default:
		break;
	}
}
