#pragma once
//#include "Animal.h"
class Animal;

class IAnimalState
{
public:
	virtual void Enter(Animal* animal) = 0;
	virtual void Execute(Animal* animal) = 0;
	virtual void Exit(Animal* animal) = 0;
};
