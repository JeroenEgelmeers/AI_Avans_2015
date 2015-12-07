#include "Animal.h"

#pragma once
class Cow : public Animal
{
public:
	Cow(Node* cNode);
	~Cow();

	void Update(float deltaTime) override;
	void Draw()override;

	void Cow::SetGraph(Graph* g);
};
