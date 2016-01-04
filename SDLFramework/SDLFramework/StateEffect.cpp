#include "StateEffect.h"

StateEffect::StateEffect(StateEnum _StateName)
{
	StateName	= _StateName;
	Avg			= 0;
	Effectivity = 10;
}

StateEffect::~StateEffect()
{
}

int StateEffect::GetEffectivity()
{
	if (HasParents()) {
		int totalEffectivity = 0;
		for (int i = 0; i < ParentStates.size(); i++) {
			totalEffectivity = (totalEffectivity + ParentStates.at(i).GetEffectivity());
		}
		return totalEffectivity;
	}
	else {
		return Effectivity;
	}
}

void StateEffect::changeAvg(int _steps)
{
	// Should be better to hold a list and get the real AVG.
	// If else to make sure the first will set the AVG.
	if (Avg > 0) {
		Avg = (Avg + _steps) / 2;
	}
	else {
		Avg = _steps;
	}
}

void StateEffect::AddToEffectivity(int addPoints)
{
	if (HasParents()) {
		int seprate = (addPoints / ParentStates.size()); // Warning, could be ,-number. Should be fixed later!
		for (int i = 0; i < ParentStates.size(); i++) {
			ParentStates.at(i).AddToEffectivity(seprate);
		}
	}
	else {
		Effectivity = (Effectivity + addPoints);
	}
}

bool StateEffect::DelFromEffectivity(int delPoints)
{
	if (HasParents()) {
		int seprate = (delPoints / ParentStates.size()); // Warning, could be ,-number. Should be fixed later!
		for (int i = 0; i < ParentStates.size(); i++) {
			ParentStates.at(i).DelFromEffectivity(seprate);
		}
	}
	else {
		if (Effectivity > 2 && delPoints <= 2) {
			Effectivity - delPoints;
			return true;
		}
	}
	return false;
}

bool StateEffect::HasParents()
{
	if (ParentStates.size() > 0) {
		return true;
	}
	return false;
}
