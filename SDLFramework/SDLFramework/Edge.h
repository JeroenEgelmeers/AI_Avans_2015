#ifndef __edge__
#define __edge__

class Edge
{
private: 
	int first;
	int second;

	Edge();
public:
	Edge(int a, int b);
	~Edge();

	int GetFirst() { return first; }
	int GetSecond() { return second; }
};

#endif;

