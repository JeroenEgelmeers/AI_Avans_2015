#include "HareStates.h"


//------------------------------------------------------------------------methods for FleeFromCow
FleeFromCow* FleeFromCow::Instance()
{
	static FleeFromCow instance;
	return &instance;
}


void FleeFromCow::Enter(Hare* hare)
{
	
}


void FleeFromCow::Execute(Hare* hare)
{
	
}


void FleeFromCow::Exit(Hare* hare)
{}

//------------------------------------------------------------------------methods for WanderAround
WanderAroundRabbit* WanderAroundRabbit::Instance()
{
	static WanderAroundRabbit instance;
	return &instance;
}


void WanderAroundRabbit::Enter(Hare* rabbit)
{
	
}


void WanderAroundRabbit::Execute(Hare* rabbit)
{
	
}


void WanderAroundRabbit::Exit(Hare* rabbit)
{}
