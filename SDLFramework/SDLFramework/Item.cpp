#include "Item.h"
#include "Graph.h"

Item::Item()
{
	TakenByAnimal = false;
}

Graph * Item::GetGraph()
{
	return graph;
}

void Item::SetGraph(Graph * g)
{
	graph = g;
}

void Item::setCurrentNode(Node * cNode)
{
	currentNode = cNode;
}

// Virtual => defined in other classes
void Item::Draw(){ }
void Item::Update(float deltaTime)
{
}
void Item::ChangeState(Animal* animal){}

Item::~Item()
{
}
