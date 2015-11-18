#ifndef __graph__
#define __graph__

#include <vector>
#include <map>
#include <math.h>
#include <iostream>

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

	std::vector<Node> GetNodes();
	std::vector<Edge> GetEdges();
	
	Node* GetNode(int i);
	Edge* GetEdge(int i);

	std::vector<Node*> Graph::AStar(Node* start, Node* goal);
	int CalculateHeuristic(Node* start, Node* goal);

	~Graph();
};

#endif;