#pragma once
#include <vector>
#include <string>
using namespace std;
// State Effectivity
class StateEffect
{
private:
	int Effectivity;
	int Avg;
	std::string StateName;
public:
	StateEffect(string _StateName);
	~StateEffect();

	string GetStateName() { return StateName; }
	int GetEffectivity() { return Effectivity; }

	std::vector<StateEffect> ParentStates;

	void changeAvg(int _steps);
	void AddToEffectivity();
	bool DelFromEffectivity();
};

