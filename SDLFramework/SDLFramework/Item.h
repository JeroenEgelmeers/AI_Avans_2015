#pragma once
#include <typeinfo>
#include "Node.h"
#include "Animal.h"

class Graph;

class Item : public IGameObject
{
protected:
	Graph* graph;
	Node* currentNode;
public:
	Item();
	~Item();

	Graph*	GetGraph();
	void	SetGraph(Graph* g);
	bool	TakenByAnimal;

	Node* getCurrentNode() { return currentNode; }
	void setCurrentNode(Node* cNode);

	virtual void Draw()override;
	virtual void Update(float deltaTime) override;
	virtual void ChangeState(Animal* animal);
};

