#pragma once
#include "Node.h"
#include "IGameObject.h"

class Animal : public IGameObject
{
protected:
	Node* currentNode;
private:
	// every entity has a unique identifying number
	int m_ID;

	// this is the next valid ID. Each time a BaseGameEntity is instantiated
	// this value is updated
	static int m_iNextValidId;

	//this is called within the constructor to make sure the ID is set
	//correctly. It verifies that the value passe to the method is greater
	//or equal to the next valid ID, before setting the ID and incrementing
	//the next valid ID
	void SetID(int val);
public:
	Animal(int id);
	virtual ~Animal();

	Node* getCurrentNode() { return currentNode; }
	void setCurrentNode(Node* cNode);

	virtual void Draw()override;
	virtual void Update(float deltaTime) = 0;
	int ID()const { return m_ID; }
};

