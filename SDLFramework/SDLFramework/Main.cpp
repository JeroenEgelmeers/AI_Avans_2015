#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include "Cow.h"
#include "Hare.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int main(int args[])
{
	srand(time(NULL));

	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}

	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));

	auto graph = new Graph();

	// Nodes
	graph->AddNode(Node(200, 100, 0)); // id = 0
	graph->AddNode(Node(400, 120, 1)); // id = 1
	graph->AddNode(Node(600, 180, 2)); // id = 2
	graph->AddNode(Node(580, 400, 3)); // id = 3
	graph->AddNode(Node(480, 480, 4)); // id = 4
	graph->AddNode(Node(380, 280, 5)); // id = 5
	graph->AddNode(Node(280, 400, 6)); // id = 6
	graph->AddNode(Node(200, 500, 7)); // id = 7
	graph->AddNode(Node(160, 400, 8)); // id = 8
	graph->AddNode(Node(130, 200, 9)); // id = 9

	// Edges
	graph->AddEdge(0, 1);
	graph->AddEdge(0, 5);
	graph->AddEdge(1, 2);
	graph->AddEdge(2, 3);
	graph->AddEdge(2, 5);
	graph->AddEdge(3, 5);
	graph->AddEdge(4, 5);
	graph->AddEdge(5, 6);
	graph->AddEdge(6, 8);
	graph->AddEdge(7, 8);
	graph->AddEdge(8, 9);
	graph->AddEdge(9, 0);
	//graph->AddEdge(7, 4);

	// TODO set current cow node
	Cow* cow = new Cow(graph->GetNode(rand() % graph->GetNodes().size()));
	Hare* hare = new Hare(graph->GetNode(rand() % graph->GetNodes().size()));
	//Hare* hare = new Hare(graph->GetNode(3));

	graph->SetCow(cow);
	graph->SetHare(hare);

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
				case SDLK_SPACE:
					cow->setCurrentNode(graph->GetNode(rand() % graph->GetNodes().size()));
					hare->setCurrentNode(graph->GetNode(rand() % graph->GetNodes().size()));
					break;
				case SDLK_RETURN:
				case SDLK_KP_ENTER:
					if (!cow->MoveCow(graph->GetShortestPath())) {
						Node* hareNode = hare->getCurrentNode();
						vector<int> blockedNodes;
						blockedNodes.clear();
						blockedNodes = hareNode->GetEdges();

						Node* newNode = graph->GetNode(rand() % graph->GetNodes().size());
						while (find(blockedNodes.begin(), blockedNodes.end(), newNode->id) != blockedNodes.end()) {
							newNode = graph->GetNode(rand() % graph->GetNodes().size());
							cout << newNode->id;
						}
						hare->setCurrentNode(newNode);
					}
				default:
					break;
				}
			}
		}

		application->SetColor(Color(0, 0, 0, 255));
		application->DrawText("KMINT opdracht 1", 800 / 2, 10);
		application->DrawText("Hit the SPACE bar to move the cow.", 800 / 2, 25);

		// Draw Nodes
		for (auto &n : graph->GetNodes())
		{
			application->DrawRect(n.x - 5, n.y - 5, 10, 10, true);
			application->DrawText(std::to_string(n.id), n.GetX(), n.GetY() + 50);
		}

		// Draw Edges
		for (auto &e : graph->GetEdges())
		{
			Node* a = graph->GetNode(e.GetFirst());
			Node* b = graph->GetNode(e.GetSecond());

			application->DrawLine(a->x, a->y, b->x, b->y);
		}

		cow->Draw();
		hare->Draw();

		// For the background
		application->SetColor(Color(255, 255, 255, 255));

		/*application->UpdateGameObjects();
		application->RenderGameObjects();*/
		application->EndTick();
	}

	return EXIT_SUCCESS;
}