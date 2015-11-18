#include "Node.h"

using std::vector;

Node::Node()
	: Point()
{}


Node::Node(float x, float y)
	: Point(x, y)
{}

Node::Node(float x, float y, float z)
	: Point(x, y, z)
{}

vector<int> Node::GetEdges()
{
	return edges;
}

Node::~Node()
{}
