#include "Cow.h"
#include <SDL.h>

Cow::Cow(Node* cNode)
{
	mTexture = mApplication->LoadTexture("cow-1.png");
	mApplication->AddRenderable(this);
	setCurrentNode(cNode);

	waiting = 1;
}

Cow::~Cow() { }

void Cow::Draw() 
{
	mApplication->DrawTexture(mTexture, mX, mY, 100, 100);
}

void Cow::MoveCow(std::vector<Node*> path)
{
	for each (Node* n in path)
	{
		setCurrentNode(n);
	}
}
