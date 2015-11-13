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
	Node(float x, float y);
	Node(float x, float y, float z);

	std::vector<int> GetEdges();

	~Node();
};

#endif;