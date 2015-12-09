#pragma once
#include "Item.h"

class Pill : public Item
{
public:
	Pill(Node* cNode);
	~Pill();

	void Draw()override;
	void ChangeState(Animal* animal)override;
};

