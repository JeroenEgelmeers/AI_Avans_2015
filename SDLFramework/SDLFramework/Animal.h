#pragma once
#include "Node.h"
#include "IGameObject.h"

class Animal : public IGameObject
{
public:
	Animal();	
	~Animal();

	Node* currentNode;
	Node* getCurrentNode() { return currentNode; }
	void setCurrentNode(Node* cNode);

	virtual void Draw()override;
	virtual void Update(float deltaTime) override;
};

