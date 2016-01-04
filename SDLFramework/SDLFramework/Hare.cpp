#include "Hare.h"
#include "HareStates.h"
#include "Graph.h"
#include "Item.h"

Hare::Hare(Node * cNode)
{
	mTexture = mApplication->LoadTexture("rabbit-3.png");
	mApplication->AddRenderable(this);
	setCurrentNode(cNode);

	m_pStateMachine = new StateMachine2<Animal>(dynamic_cast<Animal*>(this));
	m_pStateMachine->SetCurrentState(new HareWanderAround());
	m_pStateMachine->CurrentState()->Enter(dynamic_cast<Animal*>(this));

	// To check effectivity
	effectivity.push_back(StateEffect(StateEnum::eHareFleeFromCow)); // Flee from cow
	effectivity.push_back(StateEffect(StateEnum::eHareSearchItem)); // Searching an item..
	effectivity.at(1).ParentStates.push_back(StateEnum::eHareChaseCow); // using the weapon he can chase
	effectivity.at(1).ParentStates.push_back(StateEnum::eHareWanderAround); // Using the pill he can wander [ Maybe add stateEnum WanderWithPill ]
}

Hare::~Hare() {}

StateEnum Hare::GetBestStateByRandom()
{
	int randomMax = 0;
	for (size_t i = 0; i < effectivity.size(); i++) { randomMax += effectivity.at(i).GetEffectivity(); }
	int randomNmb = rand() % randomMax;
	StateEffectivityUsed = true;
	for (size_t i = 0; i < effectivity.size(); i++) {
		if (effectivity.at(i).GetEffectivity() >= randomNmb) {
			// If the random falls in the current effectivty, then take it!
			if (effectivity.at(i).HasParents()) {
				int randomMax = 0;
				for (size_t i1 = 0; i1 < effectivity.at(i).ParentStates.size(); i1++) { randomMax += effectivity.at(i).ParentStates.at(i1).GetEffectivity(); }
				int randomNmb = rand() % randomMax;
				for (size_t i1 = 0; i1 < effectivity.size(); i1++) {
					if (effectivity.at(i).ParentStates.at(i1).GetEffectivity() >= randomNmb) {
						if (effectivity.at(i).ParentStates.at(i1).GetStateName() == StateEnum::eHareChaseCow) {
							// Weapon:
							getItem = ItemEnum::eGun;
						}else if(effectivity.at(i).ParentStates.at(i1).GetStateName() == StateEnum::eHareWanderAround) {
							// Pill:
							getItem = ItemEnum::ePill;
						}
						return StateEnum::eHareSearchItem;
					}
					else {
						randomNmb = (randomNmb - effectivity.at(i).ParentStates.at(i1).GetEffectivity()); // Lower the current number to get in the right state.
					}
				}
			}
			return effectivity.at(i).GetStateName();
		}
		randomNmb = (randomNmb - effectivity.at(i).GetEffectivity());
	}
	return StateEnum::eHareWanderAround;
}

void Hare::UpdateStateEffectivity()
{
	int turns = TurnsMade(); // Give the turns the hare stayed alive.

	// Get current State
	string stateName = this->GetFSM()->GetNameOfCurrentState();
	StateEnum stateEnumCur = StateEnum::eHareRest;
	if (stateName		== "HareWanderAround")		{ stateEnumCur = StateEnum::eHareWanderAround;	}
	else if (stateName	== "HareFleeFromCow")	{ stateEnumCur = StateEnum::eHareFleeFromCow;	}
	else if (stateName	== "HareChaseCow")		{ stateEnumCur = StateEnum::eHareChaseCow;		}
	else if (stateName	== "HareSearchItem")		{ stateEnumCur = StateEnum::eHareSearchItem;	}

	// Do the action of current state for Hare; Better with LinkedList but amazing structure not needed for KMINT.
	switch (stateEnumCur) {
	case StateEnum::eHareChaseCow:
		// Update Search and (child: Weapon) Effectivity
		if (turns < (effectivity.at(1).ParentStates.at(0).GetAvg()))
		{
			effectivity.at(1).ParentStates.at(0).AddToEffectivity(2);
			effectivity.at(0).DelFromEffectivity(2);
		}
		else {
			effectivity.at(1).ParentStates.at(0).DelFromEffectivity(2);
			effectivity.at(0).AddToEffectivity(2);
		}
		effectivity.at(1).ParentStates.at(0).changeAvg((turns));
		break;
	case StateEnum::eHareFleeFromCow:
		// Flee
		if (turns < (effectivity.at(0).GetAvg()))
		{
			effectivity.at(0).AddToEffectivity(2);
			effectivity.at(1).DelFromEffectivity(2);
		}
		else {
			effectivity.at(1).AddToEffectivity(2);
			effectivity.at(2).DelFromEffectivity(2);
		}
		effectivity.at(0).changeAvg((turns));
		break;
	case StateEnum::eHareSearchItem:
		// Can only die here...
		effectivity.at(0).AddToEffectivity(2);
		effectivity.at(1).DelFromEffectivity(2);
		effectivity.at(1).changeAvg((turns));
		break;
	case StateEnum::eHareWanderAround:
		// Update Search and (child: Pill) Effectivity
		if (turns < (effectivity.at(1).ParentStates.at(1).GetAvg()))
		{
			effectivity.at(1).ParentStates.at(1).AddToEffectivity(2);
			effectivity.at(0).DelFromEffectivity(2);
		}
		else {
			effectivity.at(1).ParentStates.at(1).DelFromEffectivity(2);
			effectivity.at(0).AddToEffectivity(2);
		}
		effectivity.at(1).ParentStates.at(1).changeAvg((turns));
		break;
	default:
		// StateEnum::eHareRest: No action needed as it's not in the effectivity's
		break;
	}

	StateEffectivityUsed = false;
	ResetTurnsMade();
}

void Hare::Update(float dt)
{
	this->GetFSM()->CurrentState()->Execute(dynamic_cast<Animal*>(this));
	TurnMade();
}

void Hare::Draw()
{
	mApplication->SetColor(Color(0, 0, 0, 255));
	mApplication->DrawTexture(mTexture, currentNode->x, currentNode->y, 75, 75);
	mApplication->DrawText(GetFSM()->GetNameOfCurrentState(), currentNode->x + 50, currentNode->y - 50);
	mApplication->SetColor(Color(255, 255, 255, 255));
}

void Hare::SetGraph(Graph* g)
{
	this->graph = g;
	g->SetHareTarget(dynamic_cast<Hare*>(this));
}

void Hare::ChangeState(StateEnum state)
{
	if (state > StateEnum::eEndCowStates && state < StateEnum::eEndHareStates)
		this->GetFSM()->ChangeState(this->factory->CreateNewSate(state));
}

void Hare::SearchItem(Item* _item)
{
	SetItemTargetNode(GetGraph()->GetNodeIndex(_item->getCurrentNode()));
}