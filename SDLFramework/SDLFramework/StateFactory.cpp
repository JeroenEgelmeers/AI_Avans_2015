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
	case eCowRest:
		return new CowRest();
		break;
	case eCowFleeFromHare:
		return new CowFleeFromHare();
		break;
	case eEndCowStates:
		return new CowRest();
		break;
	case eHareWanderAround:
		return new HareWanderAround();
		break;
	case eHareFleeFromCow:
		return new HareFleeFromCow();
		break;
	case eHareRest:
		return new HareRest();
		break;
	case eHareChaseCow:
		return new HareChaseCow();
		break;
	case eEndHareStates:
		return new HareRest();
		break;
	default:
		break;
	}
}
