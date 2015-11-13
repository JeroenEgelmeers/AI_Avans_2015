#include "Edge.h"



Edge::Edge()
	: second(0), first(0)
{
}

Edge::Edge(int a, int b)
	: second(b), first(a)
{
}


Edge::~Edge()
{
}
