#include "StateEffect.h"

StateEffect::StateEffect(string _StateName)
{
	StateName	= _StateName;
	Avg			= 10;
	Effectivity = 10;
}

StateEffect::~StateEffect()
{
}

void StateEffect::changeAvg(int _steps)
{
	Avg = (Avg + _steps) / 2;
}

void StateEffect::AddToEffectivity()
{
	++Effectivity;
}

bool StateEffect::DelFromEffectivity()
{
	if (Effectivity > 2) {
		Effectivity - 1;
		return true;
	}

	return false;
}
