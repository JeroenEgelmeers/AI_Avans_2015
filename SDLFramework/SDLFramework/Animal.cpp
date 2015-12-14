#include "Animal.h"
#include "Graph.h"
#include "Item.h"
#include <algorithm>

Animal::Animal() 
{
	this->factory = new StateFactory();
}

Animal::~Animal()
{
	delete this->factory;
}

Graph* Animal::GetGraph()
{
	return graph;
}

void Animal::SetGraph(Graph* g)
{
	graph = g;
}

void Animal::setCurrentNode(Node* cNode)
{
	currentNode = cNode;
}

void Animal::GetNewRandomNode()
{
	this->setCurrentNode( this->graph->GetNode(this->graph->GetNewNode(this->graph->GetNodePosition(this->getCurrentNode()) )) );
}

void Animal::Draw() { }

void Animal::Update(float deltaTime)
{
	this->GetFSM()->CurrentState()->Execute(dynamic_cast<Animal*>(this));
}

void Animal::ChangeState(StateEnum state)
{

}

void Animal::AddItem(Item* _item)
{
	this->items.push_back(_item);
}

void Animal::RemoveItem(Item* _item)
{
	items.erase(std::remove(items.begin(), items.end(), _item), items.end());
}

std::vector<Item*> Animal::GetItems()
{
	return this->items;
}

void Animal::SearchItem(Item* _item)
{

}

int Animal::GetItemTargetNode()
{
	return targetNode;
}

void Animal::SetItemTargetNode(int _target)
{
	this->targetNode = _target;
}
