#include "Animal.h"

#pragma once
class Cow : public Animal
{
public:
	Cow(Node* cNode);
	~Cow();

	void Draw()override;
};
