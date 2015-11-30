#pragma once
#include "Node.h"
#include "IGameObject.h"
#include "StateMachine.h"

class Animal : public IGameObject
{
protected:
	Node* currentNode;
	StateMachine<Animal>* m_pStateMachine;
public:
	Animal();	
	~Animal();

	Node* getCurrentNode() { return currentNode; }
	void setCurrentNode(Node* cNode);

	virtual void Draw()override;
	virtual void Update(float deltaTime) override;

	StateMachine<Animal>* GetFSM() const
	{
		return m_pStateMachine;
	};
};
