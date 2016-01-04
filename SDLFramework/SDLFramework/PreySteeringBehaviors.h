#pragma once

#include "Vector.h"

class Prey;
 
class PreySteeringBehaviors
{
private:
	Prey* mParent;
	int cohesionDistance = 550;
	int seperationDistance = 500;

	Vector Cohesion();
	Vector Seperation();
	Vector Alignment();
public:
	PreySteeringBehaviors(Prey* target);
	~PreySteeringBehaviors();

	Vector Calculate();

};