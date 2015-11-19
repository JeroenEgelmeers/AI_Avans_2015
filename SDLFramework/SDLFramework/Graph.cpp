#include "Graph.h"
#include "Node.h"
#include "Edge.h"

#include "Vector.h"
#include <algorithm>

using namespace std;

Graph::Graph()
{

}

void Graph::AddNode(Node n)
{
	nodes.push_back(n);
}

void Graph::AddEdge(int a, int b)
{
	edges.push_back(Edge(a, b, 1000 + (nodes[a] + nodes[b]).Length()));

	nodes[a].GetEdges().push_back(edges.size() - 1);
	nodes[b].GetEdges().push_back(edges.size() - 1);
}

Node* Graph::GetNode(int i)
{
	return &nodes[i];
}

vector<Node> Graph::GetNodes()
{
	return nodes;
}

vector<Edge> Graph::GetEdges()
{
	return edges;
}

Edge* Graph::GetEdge(int i)
{
	return &edges[i];
}

int Graph::FollowEdge(int node, int edge)
{
	if (edges[edge].GetFirst() == node)
		return edges[edge].GetSecond();
	else
		return edges[edge].GetSecond();
}

int Graph::GetNumNodes() {
	return nodes.size();
}

bool Graph::sortSmallerWeight(const int& l, const int& r)
{
	if (GetNode(l)->GetPathWeight > GetNode(r)->GetPathWeight()) return true;
}

void Graph::AStarReset() {
	mAStarStep = ASTEP_BEGIN;
	mTargetNode = nullptr;
	mOpenList.clear();
	mClosedList.clear();
}

std::vector<Node*> Graph::AStar(int current, int goal)
{
	AStarReset();
	mTargetNode = GetNode(goal);

	int current_node_index = 0;
	GetNode(current_node_index)->SetSeen(true);
	GetNode(current_node_index)->SetPathWeight(0);

	for (int i = 1; i < GetNumNodes(); i++)
		mOpenList.push_back(i);

	while (mOpenList.size())
	{
		Node* current_node = GetNode(current_node_index);

		size_t i;
		for (i = 0; i < current_node->GetEdges().size(); i++)
		{
			int edge = current_node->GetEdges()[i];

			int test_node = FollowEdge(current_node_index, edge);

			if (GetNode(test_node)->IsSeen())
				continue;
			
			float g_weight = GetEdge(edge)->GetLength() + current_node->GetPathWeight();
			float h_weight = (*mTargetNode + *GetNode(test_node)).Length();

			float f_weight = g_weight + h_weight;

			if (f_weight < GetNode(test_node)->GetPathWeight())
			{
				GetNode(test_node)->SetPathWeight(f_weight);
				GetNode(test_node)->SetPathFrom(current_node_index);
			}
		}

		// We made changes to our node weights. Make sure it's still a heap by remaking the heap.
		std::make_heap(mOpenList.begin(), mOpenList.end(), sortSmallerWeight);

		// Pop the smallest item off the heap.
		std::pop_heap(mOpenList.begin(), mOpenList.end(), sortSmallerWeight);

		int lowest_path_node = mOpenList.back();
		float lowest_path_weight = GetNode(lowest_path_node)->GetPathWeight();

		mOpenList.pop_back();

		if (lowest_path_node < 0)
			return [];

		current_node_index = lowest_path_node;
		GetNode(current_node_index)->SetSeen(true);

		if (GetNode(lowest_path_node) == mTargetNode)
		{
			mClosedList.push_back(current_node_index);

			while (GetNode(current_node_index)->GetPathFrom() != ~0)
			{
				current_node_index = GetNode(current_node_index)->GetPathFrom();
				mClosedList.push_back(current_node_index);
			}

			return;
		}
	}
}

Graph::~Graph()
{}
