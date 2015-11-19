#include "Animal.h"
#include <vector>
#include "Hare.h"

#pragma once
class Cow : public Animal
{
private:
public:
	Cow(Node* cNode);
	~Cow();

	bool MoveCow(std::vector<Node*> path);

	void Draw()override;
};
