#ifndef __edge__
#define __edge__

class Edge
{
private: 
	int first;
	int second;

	float length;

	Edge();
public:
	Edge(int a, int b, float length);
	~Edge();

	int GetFirst() { return first; }
	int GetSecond() { return second; }

	float GetLength() { return length; }
};

#endif;

