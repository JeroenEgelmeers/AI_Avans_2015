#ifndef __node__
#define __node__

#include <vector>
#include "Point.h"

class Node : public Point
{
private: 
	bool mSeen;
	float mPathWeight;
	int mPathFrom;

	std::vector<int> edges;
	Node();
public:
	Node(float x, float y);
	Node(float x, float y, float z);

	std::vector<int> GetEdges();
	void AddEdge(int edge);

	bool IsSeen() { return mSeen; }
	void SetSeen(bool s) { mSeen = s; };

	float GetPathWeight() { return mPathWeight; }
	void SetPathWeight(float w) { mPathWeight = w; }

	int GetPathFrom() { return mPathFrom; }
	void SetPathFrom(int f) { mPathFrom = f; }

	~Node();
};

#endif;