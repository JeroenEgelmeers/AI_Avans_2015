#include "Node.h"
#include "Cow.h"
#include "Hare.h"

using std::vector;

Node::Node()
	: Point()
{}

Node::Node(float x, float y, int _id)
	: Point(x, y),
	id(_id)
{}

Node::Node(float x, float y, float z, int _id)
	: Point(x, y, z),
	id(_id)
{}

vector<int> Node::GetEdges()
{
	return edges;
}

void Node::AddEdge(int i)
{
	edges.push_back(i);
}

Node::~Node()
{}
