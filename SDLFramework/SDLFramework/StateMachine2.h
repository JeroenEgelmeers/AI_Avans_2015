#ifndef STATEMACHINE_H
#define STATEMACHINE_H

//------------------------------------------------------------------------
//
//  Name:   StateMachine.h
//
//  Desc:   State machine class. Inherit from this class and create some 
//          states to give your agents FSM functionality
//
//  Author: Mat Buckland (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include <cassert>
#include <string>
#include "IAnimalState.h"

template <class entity_type>
class StateMachine2
{
private:
	//a pointer to the agent that owns this instance
	entity_type*	m_pOwner;

	//a record of the current state the agent is in
	IAnimalState*	m_pCurrentState;

	//a record of the last state the agent was in
	IAnimalState*	m_pPreviousState;

	//this is called every time the FSM is updated
	IAnimalState*	m_pGlobalState;

public:
	StateMachine2(entity_type* owner) :m_pOwner(owner),
		m_pCurrentState(NULL),
		m_pPreviousState(NULL),
		m_pGlobalState(NULL)
	{}

	virtual ~StateMachine2()
	{
		delete m_pPreviousState;
		delete m_pGlobalState;
		delete m_pCurrentState;

		m_pPreviousState = nullptr;
		m_pGlobalState = nullptr;
		m_pCurrentState = nullptr;
	}

	//use these methods to initialize the FSM
	void SetCurrentState(IAnimalState* s)
	{
		m_pCurrentState = s;
	}

	void SetGlobalState(IAnimalState* s)
	{
		m_pGlobalState = s;
	}

	void SetPreviousState(IAnimalState* s)
	{
		m_pPreviousState = s;
	}

	//call this to update the FSM
	void  Update()const
	{
		//if a global state exists, call its execute method, else do nothing
		if (m_pGlobalState)
			m_pGlobalState->Execute(m_pOwner);

		//same for the current state
		if (m_pCurrentState)
			m_pCurrentState->Execute(m_pOwner);
	}

	//change to a new state
	void  ChangeState(IAnimalState* pNewState)
	{
		assert(pNewState && "<StateMachine::ChangeState>:trying to assign null state to current");

		//keep a record of the previous state
		if (m_pPreviousState != nullptr)
		{
			m_pPreviousState->Exit(m_pOwner);
			delete m_pPreviousState;
			m_pPreviousState = nullptr;
		}

		m_pPreviousState = m_pCurrentState;

		//call the exit method of the existing state
		m_pCurrentState->Exit(m_pOwner);

		//change state to the new state
		m_pCurrentState = pNewState;

		//call the entry method of the new state
		m_pCurrentState->Enter(m_pOwner);
	}

	//change state back to the previous state
	void  RevertToPreviousState()
	{
		ChangeState(m_pPreviousState);
	}

	//returns true if the current state's type is equal to the type of the
	//class passed as a parameter. 
	bool  isInState(const IAnimalState& st)const
	{
		if (typeid(*m_pCurrentState) == typeid(st)) return true;
		return false;
	}

	IAnimalState* CurrentState()  const
	{
		return m_pCurrentState;
	}

	IAnimalState*  GlobalState()   const
	{
		return m_pGlobalState;
	}

	IAnimalState*  PreviousState() const
	{
		return m_pPreviousState;
	}

	std::string GetNameOfCurrentState()const
	{
		std::string s(typeid(*m_pCurrentState).name());

		//remove the 'class ' part from the front of the string
		if (s.size() > 5)
			s.erase(0, 6);

		return s;
	}
};

#endif
