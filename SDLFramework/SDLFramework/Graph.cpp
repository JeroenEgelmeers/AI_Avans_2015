#include "Graph.h"
#include "Node.h"
#include "Edge.h"

#include "Vector.h"
#include <algorithm>

using namespace std;

Graph::Graph()
{
	// Nodes
	AddNode(Node(200, 100));
	AddNode(Node(400, 120));
	AddNode(Node(600, 180));
	AddNode(Node(580, 400));
	AddNode(Node(480, 480));
	AddNode(Node(380, 280));
	AddNode(Node(250, 400));
	AddNode(Node(200, 500));
	AddNode(Node(130, 400));
	AddNode(Node(130, 200));

	// Edges
	AddEdge(0, 1);
	AddEdge(1, 2);
	AddEdge(2, 3);
	AddEdge(4, 5);
	AddEdge(5, 6);
	AddEdge(7, 8);
	AddEdge(8, 9);
	AddEdge(9, 0);
	AddEdge(0, 5);
	AddEdge(6, 8);
	AddEdge(3, 5);
	AddEdge(2, 5);
}

void Graph::Draw() {
	mApplication->SetColor(Color(0, 0, 0, 255));
	// Draw Edges
	for (auto &e : edges)
	{
		Node a = nodes[e.GetFirst()];
		Node b = nodes[e.GetSecond()];

		mApplication->DrawLine(a.x, a.y, b.x, b.y);
	}

	mApplication->SetColor(Color(255, 0, 0, 255));
	// Draw Nodes
	for (auto &n : nodes)
	{
		mApplication->DrawRect(n.x - 5, n.y - 5, 10, 10, true);
	}

	mApplication->SetColor(Color(255, 255, 255, 255));
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

bool sortSmallerWeight(const int& l, const int& r)
{
	auto application = FWApplication::GetInstance();
	return application->GetGraph()->GetNode(l)->GetPathWeight() > application->GetGraph()->GetNode(r)->GetPathWeight();
}

int Graph::GetNodePosition(const Node* node) {
	for (size_t i = 0; i < nodes.size(); i++) {
		if (GetNode(i) == node) {
			return i;
		}
	}	
	return -1;
}

void Graph::AStarReset() {
	mAStarStep = ASTEP_BEGIN;
	mTargetNode = nullptr;
	mOpenList.clear();
	mClosedList.clear();
}

int Graph::AStar(int current, int goal)
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
			return lowest_path_node;

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

			return 1;
		}
	}
	return -1;
}

Graph::~Graph()
{}
