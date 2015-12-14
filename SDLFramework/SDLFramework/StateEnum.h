#pragma once
enum StateEnum
{
	/// Keep all cow states below this point
	eCowWanderAround = 0,
	eCowChaseHare,
	eCowRest,
	eCowFleeFromHare,
	// Add cow state here

	//Do not remove this item
	eEndCowStates,

	/// Keep all hare states below this point
	eHareWanderAround,
	eHareRest,
	eHareFleeFromCow,
	eHareChaseCow,
	eHareSearchItem,
	// Add hare state here

	//Do not remove this item
	eEndHareStates,
};
