#include "Animal.h"
#include <vector>

#pragma once
class Cow : public Animal
{
private:
	Uint32 waiting;
public:
	Cow(Node* cNode);
	~Cow();

	void MoveCow(std::vector<Node*> path);

	void Draw()override;
};
