#ifndef __graph__
#define __graph__

#include <vector>

class Node;
class Edge;

class Graph
{
protected: 
	std::vector<Node> nodes;
	std::vector<Edge> edges;
public:
	Graph();

	void AddNode(Node n);
	void AddEdge(int a, int b);
	
	Node* GetNode(int i);
	Edge* GetEdge(int i);

	~Graph();
};

#endif;