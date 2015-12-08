#include "Animal.h"
#include "Graph.h"

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

void Animal::Draw() { }

void Animal::Update(float deltaTime)
{
	this->GetFSM()->CurrentState()->Execute(dynamic_cast<Animal*>(this));
}

void Animal::ChangeState(StateEnum state)
{

}
