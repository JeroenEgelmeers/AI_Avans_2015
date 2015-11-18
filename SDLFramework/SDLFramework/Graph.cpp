#include "Graph.h"
#include "Node.h"
#include "Edge.h"

#include "Vector.h"

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

std::vector<Node*> Graph::AStar(Node* start, Node* goal)
{
	std::map<Node*, double> openList;
	std::vector<Node*> closedList; // = new std::vector<Node*>();

	openList[start] = 0.0;

	Node* current = start;
	closedList.push_back(current);

	float weightTillNow = 0;

	while (current != goal)
	{
		for (int i : current->GetEdges())
		{
			Edge* e = GetEdge(i);
			if (std::find(closedList.begin(), closedList.end(), GetNode(e->GetSecond())) == closedList.end())
			{
				int g = weightTillNow + e->GetLength();
				int h = CalculateHeuristic(goal, GetNode(e->GetSecond()));
				int f = g + h;

				openList[GetNode( e->GetSecond() )] = f;
			}
		}
		
		//Shortest
		Node* shortestNode = nullptr;
		for (std::pair<Node*, double> mapPair : openList)
		{
			if (shortestNode == nullptr || mapPair.second < openList[shortestNode])
				shortestNode = mapPair.first;
		}
		
		for (size_t i = 0; i < current->GetEdges().size(); i++)
		{

			if (GetNode(GetEdge(current->GetEdges().at(i))->GetSecond()) == shortestNode)
			{
				weightTillNow += GetEdge(current->GetEdges().at(i))->GetLength();
				break;
			}
		}
		current = shortestNode;

		closedList.push_back(current);

		//Clear openList
		openList = std::map<Node*, double>();
	}
	std::cout << "cl length:  " << closedList.size() << std::endl;
	return closedList;
}

int Graph::CalculateHeuristic(Node* start, Node* goal)
{
	return sqrt(pow((start->GetX() - goal->GetX()), 2) + pow(start->GetY() - goal->GetY(), 2));
}

Graph::~Graph()
{}
