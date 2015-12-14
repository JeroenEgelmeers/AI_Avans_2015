#pragma once
#include "Animal.h"
class Item;

class Cow : public Animal
{
public:
	Cow(Node* cNode);
	~Cow();

	void Update(float deltaTime) override;
	void Draw()override;

	void Cow::SetGraph(Graph* g);
	void Cow::ChangeState(StateEnum state) override;
	void Cow::SearchItem(Item* _item) override;
};
