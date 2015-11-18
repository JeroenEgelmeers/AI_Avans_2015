#include "Edge.h"

Edge::Edge()
	: length(0), second(0), first(0)
{
}

Edge::Edge(int a, int b, float l)
	: length(l), second(b), first(a)
{
}


Edge::~Edge()
{
}
