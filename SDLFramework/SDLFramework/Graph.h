#ifndef __graph__
#define __graph__

#include <vector>
#include <map>
#include <math.h>
#include <iostream>

class Node;
class Edge;
class Cow;
class Hare;

class Graph
{
protected: 
	std::vector<Node> nodes;
	std::vector<Edge> edges;

	Cow* cow;
	Hare* hare;
public:
	Graph();

	void AddNode(Node n);
	void AddEdge(int a, int b);

	void SetCow(Cow* _cow);
	Cow* GetCow();

	void SetHare(Hare* _hare);
	Hare* GetHare();

	std::vector<Node> GetNodes();
	std::vector<Edge> GetEdges();
	
	Node* GetNode(int i);
	Edge* GetEdge(int i);

	std::vector<Node*> GetShortestPath();

	std::vector<Node*> Graph::AStar(Node* start, Node* goal);
	int CalculateHeuristic(Node* start, Node* goal);
	int FollowEdge(int node, int edge);

	~Graph();
};

#endif;