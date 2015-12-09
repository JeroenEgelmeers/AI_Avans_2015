#pragma once
#include "Item.h"

class Gun : public Item
{
public:
	Gun(Node* cNode);
	~Gun();

	void Draw()override;
	void ChangeState(Animal animal)override;
};