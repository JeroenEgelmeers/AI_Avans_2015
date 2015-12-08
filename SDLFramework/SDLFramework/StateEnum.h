#pragma once
enum StateEnum
{
	/// Keep all cow states below this point
	eCowWanderAround = 0,
	eCowChaseHare,
	eCowRest,
	// Add cow state here

	//Do not remove this item
	eEndCowStates,

	/// Keep all hare states below this point
	eHareWanderAround,
	eHareFleeFromCow,
	eHareRest,
	// Add hare state here
};
