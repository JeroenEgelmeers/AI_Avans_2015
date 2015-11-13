#include "Graph.h"
#include "Node.h"
#include "Edge.h"

Graph::Graph()
{
}

void Graph::AddNode(Node n) 
{
	nodes.push_back(n);
}

void Graph::AddEdge(int a, int b)
{	
	edges.push_back(Edge(a , b));

	nodes[a].GetEdges().push_back(edges.size() - 1);
	nodes[b].GetEdges().push_back(edges.size() - 1);
}

Node* Graph::GetNode(int i) {
	return &nodes[i];
}

Edge* Graph::GetEdge(int i) {
	return &edges[i];
}

Graph::~Graph()
{
}
