#ifndef __graph__
#define __graph__

#include <vector>
#include <map>
#include <math.h>
#include <iostream>

#include "IGameObject.h"

class Node;
class Edge;
class Cow;
class Hare;
class Pill;
class Gun;

class Graph : public IGameObject
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

	Cow* cow;
	Hare* hare;
	
	void AStarReset();
protected: 
	std::vector<Node> nodes;
	std::vector<Edge> edges;
public:
	Graph();

	void Update(float deltatime) {};
	void Draw();

	void AddNode(Node n);
	void AddEdge(int a, int b);

	void SetCowTarget(Cow* c);
	void SetHareTarget(Hare* h);
	int GetCowTargetNode();
	int GetHareTargetNode();
	//Pill* GetPillTarget();
	//Gun* GetGunTarget();

	std::vector<Node> GetNodes();
	std::vector<Edge> GetEdges();
	
	int GetNumNodes();
	Node* GetNode(int i);
	int GetNodeIndex(Node* _node);
	Edge* GetEdge(int i);

	int GetNewNode(int node);
	int GetNewNeighborNode(int currentNode);
	int GetFarthestHeuristicNode(int currentNode);
	int GetNodePosition(const Node* node);

	int Graph::FollowEdge(int node, int edge);
	int AStar(int current, int goal);

	~Graph();
};

#endif;