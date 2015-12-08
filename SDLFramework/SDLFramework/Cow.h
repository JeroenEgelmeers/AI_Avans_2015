#pragma once
#include "Animal.h"

class Cow : public Animal
{
public:
	Cow(Node* cNode);
	~Cow();

	void Update(float deltaTime) override;
	void Draw()override;

	void Cow::SetGraph(Graph* g);
	void Cow::ChangeState(StateEnum state) override;
};
