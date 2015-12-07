#pragma once
#include "State.h"

template<class T>
class StateMachine
{
private:
	T* m_pOwner;
	State<T>* m_pCurrentState;

	//a record of the last state the agent was in.
	State<T>* m_pPreviousState;

	//this state logic is called everytime the FSM is updated
	State<T>* m_pGlobalState;

public:
	StateMachine(T* owner) :m_pOwner(owner),
		m_pCurrentState(NULL),
		m_pPreviousState(NULL),
		m_pGlobalState(NULL) { }

	//use this to update the FSM
	void Update()const {
		//if a global state excists, call its execute method
		if (m_pGlobalState) m_pGlobalState->Execute(m_pOwner);

		//same for the current state
		if (m_pCurrentState) m_pCurrentState->Execute(m_pOwner);
	}

	// change to a new state
	void ChangeState(State<T>* pNewState) {
		assert(pNewState && : "<StateMachine::ChangeState>: trying to change to a null state");

		// keep a record of the previous state
		m_pPreviousState = m_pCurrentState;

		// call the exit method of the existing state
		m_pCurrentState->Exit(m_pOwner);

		//change state to the new state
		m_pCurrentState = pNewState;

		// call the entry method of the new state
		m_pCurrentState->Enter(m_pOwner);
	}

	//Change state back to the previous state
	void RevertToPreviousState() {
		ChangeState(m_pPreviousState);
	}

	//accessors
	State<T>* CurrentState() const { return m_pCurrentState; }
	State<T>* GlobalState() const { return m_pGlobalState;  }
	State<T>* PreviousState() const { return m_pPreviousState; }

	//returns true if the current state's type is equal to the type of the 
	//class passed as a paramter.
	bool isInState(const State<T>& st)const;
	~StateMachine();

};

