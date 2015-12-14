#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Node.h"
#include "Edge.h"

using namespace std;

int main(int args[])
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}

	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));
	

	// lazy modes
	bool lazyOn = false;
	Uint32 lastLoopTime = 0;
	Uint32 lastFpsTime = 0;

	//while (true){}
	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					application->Quit();
					break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym)
					{
					case SDLK_RETURN:
						if (lazyOn == true)
							lazyOn = false;
						else
						{
							lazyOn = true;

						}
						break;
						case SDLK_SPACE:
							lazyOn = false;
							application->UpdateGameObjects();
							break;
						default:
							break;
					}
			}

		}

		// lazy modes
		if (lazyOn)
		{
			Uint32 now = SDL_GetTicks();
			Uint32 updateLength = now - lastLoopTime;
			lastLoopTime = now;
			lastFpsTime += updateLength;

			if (lastFpsTime > 1000)
			{
				lastFpsTime = 0;
				application->UpdateGameObjects();
			}
		}

		application->SetColor(Color(0, 0, 0, 255));
		application->DrawText("KMINT opdracht 2", 800 / 2, 10);
		application->DrawText("Hit the SPACE bar to move the cow.", 800 / 2, 25);

		// For the background
		application->SetColor(Color(255, 255, 255, 255));

		application->RenderGameObjects();
		application->EndTick();
	}

	return EXIT_SUCCESS;
}