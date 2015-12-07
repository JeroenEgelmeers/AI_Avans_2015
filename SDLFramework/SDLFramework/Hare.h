#pragma once
#include "Animal.h"


class Hare : public Animal
{
public:
	Hare(Node * cNode);
	void Hare::Update(float deltaTime) override;
	void Hare::Draw()override;
	void Hare::SetGraph(Graph* g);
	~Hare();
};
