#include "FWApplication.h"
#include "Config.h"
#include "IGameObject.h"
#include <SDL.h>
#include <SDL_video.h>
#include <SDL_render.h>
#include <SDL_events.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <time.h>

#include "Graph.h"
#include "Cow.h"
#include "Hare.h"
#include "Gun.h"
#include "Pill.h"

FWApplication * FWApplication::mInstance;
FWApplication::FWApplication(int offsetX, int offsetY, int width, int height)
	: mTargetDelayMS(1000 / 60),
	mStartCycleTimeMS(0),
	mDeltaTimeMS(0),
	mTimeMS(0),
	mIsRunning(true),
	mFontSize(12),
	mFontName("")
	//mTextBackgroundColor(0xFF,0xFF,0xFF,0xFF)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		LOG("SDL init failed");
		return;
	}

	mWindow = SDL_CreateWindow("KMint framework", offsetX, offsetY, width, height, SDL_WINDOW_SHOWN);
	if (!mWindow)
	{
		LOG(SDL_GetError());
		return;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!mRenderer)
	{
		LOG(SDL_GetError());
		SDL_DestroyWindow(mWindow);
		return;
	}

	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
	if (!IMG_Init(imgFlags) & imgFlags)
	{
		LOG(IMG_GetError());
		SDL_DestroyWindow(mWindow);
		SDL_DestroyRenderer(mRenderer);
		return;
	}

	if (TTF_Init() < 0)
	{
		LOG(TTF_GetError());
		SDL_DestroyWindow(mWindow);
		SDL_DestroyRenderer(mRenderer);
		return;
	}

	//mFont = TTF_OpenFont(GetRelativePath("Resources/OpenSans-Regular.ttf").c_str(), mFontSize);
	SetFontSize(12);
	SetFont("OpenSans-Regular.ttf");

	/* initialize random seed: */
	srand(time(NULL));
	mInstance = this;
	mGameObjects.reserve(32);

	mGraph = new Graph();
	// TODO set current cow node
	mCow = new Cow(mGraph->GetNode((0 + (rand() % (int)(mGraph->GetNodes().size())))));
	mHare = new Hare(mGraph->GetNode(GetNewNode(mGraph->GetNodePosition(mCow->getCurrentNode()))));
	mCow->SetGraph(mGraph);
	mHare->SetGraph(mGraph);

	mPill = new Pill(mGraph->GetNode((0 + (rand() % (int)(mGraph->GetNodes().size())))));
	mGun = new Gun(mGraph->GetNode((0 + (rand() % (int)(mGraph->GetNodes().size())))));

	AddRenderable(mGraph);
	AddRenderable(mCow);
	AddRenderable(mHare);

}

FWApplication::~FWApplication()
{
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	TTF_CloseFont(mFont);
	TTF_Quit();
	SDL_Quit();
}

int FWApplication::GetNewNode(int currentNode)
{
	std::vector<int> neighborNodes = std::vector<int>();

	for (int edge : mGraph->GetNode(currentNode)->GetEdges())
	{
		neighborNodes.push_back(mGraph->FollowEdge(currentNode, edge));
		neighborNodes.push_back(currentNode);
	}

	bool correctNumber = false;
	int newNodePosition;
	while (correctNumber == false)
	{
		newNodePosition = 0 + (rand() % (int)(mGraph->GetNodes().size()));
		correctNumber = true;
		for (int node : neighborNodes)
		{
			if (node == newNodePosition)
			{
				correctNumber = false;
			}
		}
	}
	return newNodePosition;
}

SDL_Window * FWApplication::GetWindow() const
{
	return mWindow;
}

FWApplication * FWApplication::GetInstance()
{
	if (!mInstance)
	{
		new FWApplication();
	}

	return mInstance;
}

bool FWApplication::IsRunning()
{
	return mIsRunning;
}

std::string FWApplication::GetRelativePath(const std::string & path) const
{
	std::string basePath = SDL_GetBasePath();
	return basePath + ".." + PATH_SEP + path; //  + PATH_SEP
	//size_t pos = basePath.rfind("Debug");
	//return basePath.substr(0, basePath.rfind("Debug")) + path + PATH_SEP; //  + "resources" + PATH_SEP
}

SDL_Texture * FWApplication::LoadTexture(const std::string & fileName)
{
	const std::string path = GetRelativePath("Resources" PATH_SEP + fileName);
	SDL_Surface * surface = IMG_Load(path.c_str());
	if (surface)
	{
		SDL_Texture * texture = SDL_CreateTextureFromSurface(mRenderer, surface);
		SDL_FreeSurface(surface);

		if (!texture)
		{
			LOG("Couldn't load texture: " + path);
		}
		return texture;
	}

	LOG("SDL Error, couldn't load BMP: " + path);
	return nullptr;
}

void FWApplication::DrawTexture(SDL_Texture * texture, int xOffset, int yOffset)
{
	SDL_Rect rect = { xOffset, yOffset };

	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	SDL_RenderCopy(mRenderer, texture, &rect, &rect);
}
void FWApplication::DrawTexture(SDL_Texture * texture, int xOffset, int yOffset, int width, int height)
{
	SDL_Rect rect = { xOffset - (width / 2), yOffset - (height / 2), width, height };

	//SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	SDL_RenderCopy(mRenderer, texture, NULL, &rect);
}

void FWApplication::StartTick()
{
	SDL_RenderClear(mRenderer);
	mStartCycleTimeMS = SDL_GetTicks();

	//SDL_Event ev;
	//while (SDL_PollEvent(&ev) != 0)
	//{
	//	if (ev.type == SDL_QUIT)
	//	{
	//		mIsRunning = false;
	//	}
	//}
}

void FWApplication::EndTick()
{
	SDL_RenderPresent(mRenderer);
	//SDL_UpdateWindowSurface(mWindow);

	mTimeMS = SDL_GetTicks();
	mDeltaTimeMS = mTimeMS - mStartCycleTimeMS;
	if (((int32_t)mTargetDelayMS - (int32_t)mDeltaTimeMS) > 0)
	{
		SDL_Delay(mTargetDelayMS - mDeltaTimeMS);
	}
}

void FWApplication::UpdateGameObjects()
{
	if (moveCow)
	{
		mCow->Update(0);
		moveCow = false;
		if (mCow->getCurrentNode() == mPill->getCurrentNode())
		{
			mPill->ChangeState(mCow);
		}
	}
	else
	{
		mHare->Update(0);
		moveCow = true;
		if (mHare->getCurrentNode() == mGun->getCurrentNode())
		{
			mGun->ChangeState(mHare);
		}
	}

	if (mHare->getCurrentNode() == mCow->getCurrentNode())
	{
		// TODO Check if cow is in chase state & hare is in chase state
		if (mCow->GetFSM()->GetNameOfCurrentState().find("Chase") != std::string::npos || 
			mHare->GetFSM()->GetNameOfCurrentState().find("Chase") != std::string::npos )
		{
			if (!moveCow)
			{
				std::cout << "cow killed hare, respawn hare \n";
				mHare->setCurrentNode(mGraph->GetNode(GetNewNode(mGraph->GetNodePosition(mHare->getCurrentNode()))));
			}
			else
			{
				std::cout << "Hare killed cow, respawn cow \n";
				mCow->setCurrentNode(mGraph->GetNode(GetNewNode(mGraph->GetNodePosition(mHare->getCurrentNode()))));
			}

			mHare->ChangeState(StateEnum::eHareWanderAround);
			mCow->ChangeState(StateEnum::eCowWanderAround);
		}

		// Respawn Pill and Gun
		if (mPill->TakenByAnimal)
		{
			mPill->setCurrentNode(mGraph->GetNode((0 + (rand() % (int)(mGraph->GetNodes().size())))));
			mPill->TakenByAnimal = false;
		}
		if (mGun->TakenByAnimal)
		{
			mGun->setCurrentNode(mGraph->GetNode((0 + (rand() % (int)(mGraph->GetNodes().size())))));
			mGun->TakenByAnimal = false;
		}
	}
}

void FWApplication::RenderGameObjects()
{
	for (IGameObject * obj : mGameObjects)
	{
		obj->Draw();
	}
}

void FWApplication::SetTargetFPS(unsigned short target)
{
	mTargetDelayMS = 1000 / target;
}

void FWApplication::RemoveTexture(SDL_Texture * texture)
{
	SDL_DestroyTexture(texture);
}

void FWApplication::DrawLine(int startPosX, int startPosY, int endPosX, int endPosY)
{
	SDL_RenderDrawLine(mRenderer, startPosX, startPosY, endPosX, endPosY);
}

void FWApplication::SetColor(const Color & color)
{
	mColor = color;
	SDL_SetRenderDrawColor(mRenderer, mColor.r, mColor.g, mColor.b, mColor.a);
}

void FWApplication::DrawRect(int startPosX, int startPosY, int width, int height, bool fill)
{
	SDL_Rect rect = { startPosX, startPosY, width, height };

	if (fill)
	{
		SDL_RenderFillRect(mRenderer, &rect);
	}
	else
	{
		SDL_RenderDrawRect(mRenderer, &rect);
	}
}

//void FWApplication::DrawEllipse(int offsetX, int offsetY, int width, int height, bool fill)
//{
//	////
//	//// http://sdl-draw.sourceforge.net/
//	//// 
//
//	SDL_Rect rect = { offsetX, offsetY, width, height };
//
//	Sint32 x, y;
//	Sint32 Xchange, Ychange;
//	Sint32 EllipseError;
//	Sint32 TwoASquare, TwoBSquare;
//	Sint32 StoppingX, StoppingY;
//
//	TwoASquare = 2 * width*width;
//	TwoBSquare = 2 * height*height;
//
//	/*1st set of points*/
//	x = width - 1;  /*radius zero == draw nothing*/
//	y = 0;
//
//	x += offsetX;
//	y += offsetY;
//
//	Xchange = height*height*(1 - 2 * width);
//	Ychange = width*width;
//
//	EllipseError = 0;
//
//	StoppingX = TwoBSquare*width;
//	StoppingY = 0;
//
//	SDL_Surface * super = SDL_GetWindowSurface(mWindow);
//	if (SDL_MUSTLOCK(super)) {
//		if (SDL_LockSurface(super) < 0)  { return; }
//	}
//
//	while (StoppingX > StoppingY)
//	{
//		SDL_DRAW_PUTPIXEL
//		++y;
//
//		StoppingY += TwoASquare;
//		EllipseError += Ychange;
//		Ychange += TwoASquare;
//		if ((2 * EllipseError + Xchange) > 0) {
//			--x;
//			StoppingX -= TwoBSquare;
//			EllipseError += Xchange;
//			Xchange += TwoBSquare;
//		}
//	}
//
//	/*2nd set of points*/
//	x = 0;
//	y = height - 1;
//
//	x += offsetX;
//	y += offsetY;
//
//	Xchange = height*height;
//	Ychange = width*width*(1 - 2 * height);
//	EllipseError = 0;
//	StoppingX = 0;
//	StoppingY = TwoASquare*height;
//
//	while (StoppingX < StoppingY)
//	{
//		SDL_RenderDrawPoint(mRenderer, x, y);
//		
//		++x;
//		StoppingX += TwoBSquare;
//		EllipseError += Xchange;
//		Xchange += TwoBSquare;
//		if ((2 * EllipseError + Ychange) > 0) {
//			--y;
//			StoppingY -= TwoASquare;
//			EllipseError += Ychange;
//			Ychange += TwoASquare;
//		}
//	}
//
//	if (SDL_MUSTLOCK(super))  { SDL_UnlockSurface(super); }
//}

void FWApplication::AddRenderable(IGameObject * renderable)
{
	mGameObjects.push_back(renderable);
}

uint32_t FWApplication::GetTimeSinceStartedMS() const
{
	return mTimeMS;
}

void FWApplication::DrawText(const std::string & message, uint32_t offsetX, uint32_t offsetY)
{
	//SDL_Color color = { mColor.r, mColor.g, mColor.b, mColor.a };
	SDL_Color color = { 0, 0, 0, mColor.a };
	//SDL_Color bgColor = { mTextBackgroundColor.r, mTextBackgroundColor.g, mTextBackgroundColor.b, mTextBackgroundColor.a };

	SDL_Surface * surface = TTF_RenderText_Blended(mFont, message.c_str(), color);
	if (surface)
	{
		SDL_Texture * texture = SDL_CreateTextureFromSurface(mRenderer, surface);
		if (texture)
		{
			DrawTexture(texture, offsetX, offsetY, surface->w, surface->h);
		}
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
	}
}

void FWApplication::SetFontSize(int ptSize)
{
	mFontSize = ptSize;

	if (mFontName != "")
	{
		SetFont(mFontName);
	}
}

void FWApplication::SetFont(const std::string & filename)
{
	if (mFont)
	{
		TTF_CloseFont(mFont);
	}

	mFontName = filename;
	mFont = TTF_OpenFont(GetRelativePath("Resources/" + filename).c_str(), mFontSize);
}

void FWApplication::Quit()
{
	mIsRunning = false;
}


//void FWApplication::AddOnEvent(std::function<void(SDL_Event*)> func)
//{
//	//SDL_Set
//}