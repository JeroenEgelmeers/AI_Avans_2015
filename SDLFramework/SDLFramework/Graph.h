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
private:
	typedef enum
	{
		ASTEP_BEGIN,
		ASTAR_FINDLOWEST,
		ASTAR_CALCULATENEIGHBORS,
		ASTAR_RECONSTRUCT,
	} AStarStep;

	AStarStep mAStarStep;
	Node* mTargetNode;
	std::vector<int> mOpenList;
	std::vector<int> mClosedList;

	bool sortSmallerWeight(const int& l, const int& r);
	
	void AStarReset();
protected: 
	std::vector<Node> nodes;
	std::vector<Edge> edges;
public:
	Graph();

	void AddNode(Node n);
	void AddEdge(int a, int b);

	std::vector<Node> GetNodes();
	std::vector<Edge> GetEdges();
	

	int GetNumNodes();
	Node* GetNode(int i);
	Edge* GetEdge(int i);

	int Graph::FollowEdge(int node, int edge);

	std::vector<Node*> AStar(int current, int goal);

	~Graph();
};

#endif;