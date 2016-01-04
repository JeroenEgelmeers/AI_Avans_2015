#include "PreySteeringBehaviors.h"
#include "Prey.h"

Vector PreySteeringBehaviors::Cohesion(){
	Vector forceVector = Vector();	
	Vector centerOfMass = Vector();

	float neighbors = 0;
	
	for each (IGameObject* e in mParent->GetLevel()->GetGameObjects())
	{
		if (e != mParent && //Not checking self
			e->mId == ObjectId::PREY && // Target is a prey
			e->GetPosition().LengthTorus(mParent->GetPosition(), mScreenHeight, mScreenWidth) < cohesionDistance
			) {
			centerOfMass + e->GetPosition();
			neighbors++;
		}

		if (neighbors > 0) {
			centerOfMass.Average(neighbors);
			forceVector = centerOfMass - mParent->GetPosition();
			forceVector.Normalize();
		}
	}

	return forceVector;
}

Vector PreySteeringBehaviors::Seperation() {
	Vector forceVector = Vector();

	for each (IGameObject* e in mParent->GetLevel()->GetGameObjects())
	{
		if (e != mParent && //Not checking self
			e->mId == ObjectId::PREY && // Target is a prey
			sqrt(e->GetPosition().LengthTorus(mParent->GetPosition(), mScreenHeight, mScreenWidth)) < seperationDistance
			) {
			Vector headingVector = mParent->GetPosition() - e->GetPosition();

			float scale = headingVector.Length() / (float)sqrt(seperationDistance);
			headingVector.Normalize();
			headingVector / scale;
			forceVector += headingVector;
		}
	}
	
	return forceVector;
}


Vector PreySteeringBehaviors::Alignment() {
	Vector forceVector = Vector();
	int neighbors = 0;

	for each (IGameObject* e in mParent->GetLevel()->GetGameObjects())
	{
		if (e != mParent && //Not checking self
			e->mId == ObjectId::PREY && // Target is a prey
			e->GetPosition().LengthTorus(mParent->GetPosition(), mScreenHeight, mScreenWidth) < cohesionDistance // Target is a prey
			){
				forceVector = mParent->GetHeading();
				neighbors++;

		}
	}

	if (neighbors > 0) {
		forceVector.Average(neighbors);
		forceVector.Normalize();
	}

	return forceVector;
}

PreySteeringBehaviors::PreySteeringBehaviors(Prey* target)
{
	mParent = target;

	mScreenWidth, mScreenHeight;

	int *widthPtr = &mScreenWidth;
	int *heightPtr = &mScreenHeight;
	mParent->GetLevel()->GetWindowSize(widthPtr, heightPtr);
}

PreySteeringBehaviors::~PreySteeringBehaviors()
{
}

Vector PreySteeringBehaviors::Calculate() {
	Vector forceVector = Vector(0, 0);

	forceVector += Cohesion();
	forceVector += Seperation();
	forceVector += Alignment();
	return forceVector;
}