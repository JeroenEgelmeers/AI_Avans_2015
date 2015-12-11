#pragma once
#include "Node.h"
#include "IGameObject.h"
#include "StateMachine2.h"
#include "StateFactory.h"
#include "StateEnum.h"

class Graph;

class Animal : public IGameObject
{
protected:
	Graph* graph;
	Node* currentNode;
	StateMachine2<Animal>* m_pStateMachine;
	StateFactory* factory;

public:
	Animal();	
	~Animal();


	Graph* GetGraph();
	void SetGraph(Graph* g);

	Node* getCurrentNode() { return currentNode; }
	void setCurrentNode(Node* cNode);

	virtual void Draw()override;
	virtual void Update(float deltaTime) override;

	StateMachine2<Animal>* GetFSM() const { return m_pStateMachine; }
	virtual void ChangeState(StateEnum state);
};
