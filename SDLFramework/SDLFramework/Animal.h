#pragma once
#include "Node.h"
#include "IGameObject.h"
#include "StateMachine2.h"
#include "StateFactory.h"
#include "StateEnum.h"

class Graph;
class Item;

class Animal : public IGameObject
{
private: 
	// stuff

protected:
	Graph* graph;
	Node* currentNode;
	StateMachine2<Animal>* m_pStateMachine;
	StateFactory* factory;
	std::vector<Item*> items;

	int targetNode;

public:
	Animal();	
	~Animal();

	Graph* GetGraph();
	void SetGraph(Graph* g);

	Node* getCurrentNode() { return currentNode; }
	void setCurrentNode(Node* cNode);
	void GetNewRandomNode();

	virtual void Draw()override;
	virtual void Update(float deltaTime) override;

	StateMachine2<Animal>* GetFSM() const { return m_pStateMachine; }
	virtual void ChangeState(StateEnum state) = 0;

	virtual void AddItem(Item* _item);
	virtual void RemoveItem(Item* _item);
	virtual std::vector<Item*> GetItems();

	virtual void SearchItem(Item* _item) = 0;
	virtual int GetItemTargetNode();
	virtual void SetItemTargetNode(int _target);
};
