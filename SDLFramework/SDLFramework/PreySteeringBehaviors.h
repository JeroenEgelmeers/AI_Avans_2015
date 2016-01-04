#pragma once

#include "Vector.h"

class Prey;
 
class PreySteeringBehaviors
{
private:
	Prey* mParent;
	int cohesionDistance = 150;
	int seperationDistance = 50;

	int mScreenWidth;
	int mScreenHeight;

	Vector Cohesion();
	Vector Seperation();
	Vector Alignment();
public:
	PreySteeringBehaviors(Prey* target);
	~PreySteeringBehaviors();

	Vector Calculate();

};