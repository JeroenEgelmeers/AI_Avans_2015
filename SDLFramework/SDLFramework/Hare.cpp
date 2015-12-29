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
	for (size_t i = 0; i < effectivity.size(); i++) { randomMax += effectivity.at(1).GetEffectivity(); }
	int randomNmb = rand() % randomMax;

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
				}
			}
			return effectivity.at(i).GetStateName();
		}
	}
}

void Hare::UpdateStateEffectivity()
{
	// Get current Effectivity
	// Update current AVG of Effectivity
	// // Just get the current effectivity from list by using a switch. 
	// // // When current = Gun, update 1 and parent 0,
	// // // When current = Pill, update 1 and parent 1,


	//switch (StateEnum) {
	//case StateEnum::eHareChaseCow:
	//	break;
	//case StateEnum::eHareFleeFromCow:
	//	break;
	//case StateEnum::eHareRest:
	//	break;
	//case StateEnum::eHareSearchItem:
	//	break;
	//default:
	//	break;
	//}

}

void Hare::Update(float dt)
{
	this->GetFSM()->CurrentState()->Execute(dynamic_cast<Animal*>(this));
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