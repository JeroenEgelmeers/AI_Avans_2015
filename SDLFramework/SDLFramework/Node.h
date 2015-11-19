#ifndef __node__
#define __node__

#include <vector>
#include "Point.h"

class Node : public Point
{
private: 
	std::vector<int> edges;
	Node();
public:
	int id;
	Node(float x, float y, int _id);
	Node(float x, float y, float z, int _id);

	std::vector<int> GetEdges();
	void AddEdge(int i);

	int GetX() { return x; }
	int GetY() { return y; }

	~Node();
};

#endif;
