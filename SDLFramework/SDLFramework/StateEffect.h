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
	int GetEffectivity();
	int GetAvg() { return Avg; }

	std::vector<StateEffect> ParentStates;

	void changeAvg(int _steps);
	void AddToEffectivity(int addPoints);
	bool DelFromEffectivity(int delPoints);
	bool HasParents();
};

