#pragma once
enum StateEnum
{
	/// Keep all cow states below this point
	eCowWanderAround = 0,
	eCowChaseHare,
	eCowRest,
	eCowFleeFromHare,
	// Add cow state here
	eCowSearchPill,

	//Do not remove this item
	eEndCowStates,

	/// Keep all hare states below this point
	eHareWanderAround,
	eHareFleeFromCow,
	eHareRest,
	eHareChaseCow,
	// Add hare state here
	eHareSearchGun,

	//Do not remove this item
	eEndHareStates,
};
