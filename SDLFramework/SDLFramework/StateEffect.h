#pragma once
#include <vector>
#include "StateEnum.h"
using namespace std;
// State Effectivity
class StateEffect
{
private:
	int Effectivity;
	int Avg;
	StateEnum StateName;
public:
	StateEffect(StateEnum _StateName);
	~StateEffect();

	StateEnum GetStateName() { return StateName; }
	int GetEffectivity() { return Effectivity; }

	std::vector<StateEffect> ParentStates;

	void changeAvg(int _steps);
	void AddToEffectivity();
	bool DelFromEffectivity();
	bool HasParents();
};

