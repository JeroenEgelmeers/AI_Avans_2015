#include "Animal.h"
#include "State.h"
#include "StateMachine.h"

#pragma once
class Cow : public Animal
{
private:
	//an instance of the state machine class
	StateMachine<Cow>* m_pStateMachine;

public:
	Cow(int id) :m_Location(shack),
		m_iThirst(0),
		m_iFatigue(0),
		Animal(id) {
		m_pStateMachine = new StateMachine<Cow>(this);

		m_pStateMachine->CurrentState(); // TODO
		m_pStateMachine->GlobalState(); // TODO
	}
	Cow(Node* cNode, int ID);
	~Cow();

	void Draw()override;
	
	// Must be implemented
	void Update();

	// this method changes the current state to the new state
	StateMachine<Cow>* GetFSM() const { return m_pStateMachine; }

};

