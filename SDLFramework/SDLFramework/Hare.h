#pragma once
#include "Animal.h"


class Hare : public Animal
{
public:
	Hare(Node * cNode);
	void Hare::Draw()override;
	~Hare();
	void Hare::MoveHare(Node* node);
};

