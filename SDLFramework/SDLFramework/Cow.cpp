#include "Cow.h"
#include <SDL.h>
#include "Hare.h"

Cow::Cow(Node* cNode)
{
	mTexture = mApplication->LoadTexture("cow-1.png");
	mApplication->AddRenderable(this);
	setCurrentNode(cNode);
}

Cow::~Cow() { }

void Cow::Draw()
{
	mApplication->DrawTexture(mTexture, mX, mY, 100, 100);
}

bool Cow::MoveCow(std::vector<Node*> path)
{
	if (path.size() > 0)
	{
		setCurrentNode(path.at(1));
		return true;
	}
	else
	{
		return false;
	}

	//for each (Node* n in path)
	//{
	//	setCurrentNode(n);
	//}
	//return true;
}
