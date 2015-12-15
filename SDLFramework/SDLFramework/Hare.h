#pragma once
#include "Animal.h"

class Item;

class Hare : public Animal
{
public:
	Hare(Node * cNode);
	void Hare::Update(float deltaTime) override;
	void Hare::Draw()override;
	void Hare::SetGraph(Graph* g);
	void Hare::ChangeState(StateEnum state) override;
	void Hare::SearchItem(Item* _item) override;

	~Hare();

	StateEnum Hare::GetBestStateByRandom() override;
};
