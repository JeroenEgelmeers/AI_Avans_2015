#include "Graph.h"
#include "Node.h"
#include "Edge.h"

#include "Vector.h"
#include "Cow.h"
#include "Hare.h"

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

	nodes[a].AddEdge(edges.size() - 1);
	nodes[b].AddEdge(edges.size() - 1);
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

void Graph::SetCow(Cow* _cow)
{
	cow = _cow;
}

Cow* Graph::GetCow()
{
	return cow;
}

void Graph::SetHare(Hare* _hare)
{
	hare = _hare;
}
Hare* Graph::GetHare()
{
	return hare;
}

std::vector<Node*> Graph::GetShortestPath()
{
	return this->AStar(cow->getCurrentNode(), hare->getCurrentNode());
}

std::vector<Node*> Graph::AStar(Node* start, Node* goal)
{
	std::map<Node*, double> openList;
	std::vector<Node*> closedList;
	openList.insert(std::pair<Node*, double>(start, 0));

	Node* current = start;
	//closedList.push_back(current);

	double weightTillNow = 0;

	while (current != goal)
	{
		for (int i : current->GetEdges())
		{
			//Edge* e = GetEdge(i);
			int x = FollowEdge(current->id, i);
			if (std::find(closedList.begin(), closedList.end(), GetNode(x)) == closedList.end())
			{
				int g = weightTillNow + GetEdge(i)->GetLength();
				int h = CalculateHeuristic(goal, GetNode(x));
				int f = g + h;

				openList.insert(std::pair<Node*, double>(GetNode(x), f));
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
		openList.clear();
	}
	std::cout << "cl length:  " << closedList.size() << std::endl;
	for each (Node* n in closedList)
	{
		std::cout << "Route: " << n->id << std::endl;
	}
	return closedList;
}

int Graph::CalculateHeuristic(Node* start, Node* goal)
{
	return sqrt(pow((start->GetX() - goal->GetX()), 2) + pow(start->GetY() - goal->GetY(), 2));
}

int Graph::FollowEdge(int node, int edge)
{
	if (this->edges[edge].GetFirst() == node)
		return edges[edge].GetSecond();
	else
		return edges[edge].GetFirst();
}

void Graph::MoveHare()
{
	if (cow->getCurrentNode() == hare->getCurrentNode())
	{
		std::vector<int> closed;
		std::vector<Node> open = GetNodes();

		for each (int i in hare->getCurrentNode()->GetEdges())
		{
			Edge* e = GetEdge(i);
			closed.push_back(e->GetSecond());
		}

		// vec.erase(std::remove(vec.begin(), vec.end(), 8), vec.end());
		for (size_t i = 0; i < closed.size(); i++)
		{
			for (size_t j = 0; j < open.size(); j++)
			{
				if (&open.at(j) == GetNode(i))
				{
					open.erase(open.begin() + j);
				}
			}

			hare->setCurrentNode(&open[rand() % open.size()]);
		}
	}
}

Graph::~Graph() {}
