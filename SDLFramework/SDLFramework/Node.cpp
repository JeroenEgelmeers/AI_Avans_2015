#include "Node.h"

using std::vector;

Node::Node()
	: Point(), mPathFrom(-1), mSeen(false), mPathWeight(999999)
{
}


Node::Node(float x, float y)
	: Point(x, y), mPathFrom(-1), mSeen(false), mPathWeight(999999)
{
}

Node::Node(float x, float y, float z)
	: Point(x, y, z), mPathFrom(-1), mSeen(false), mPathWeight(999999)
{
}

vector<int> Node::GetEdges()
{
	return edges;
}

void Node::AddEdge(int edge) {
	edges.push_back(edge);
}

Node::~Node()
{}
