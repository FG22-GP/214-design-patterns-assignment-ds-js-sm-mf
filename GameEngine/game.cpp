#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <math.h>
#include <sstream>
#include <vector>
#include <ctime>
#include <iostream>

#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include "Vector3.h"
#include "Components/RenderCircleComponent.h"
#include "Components/TestComponent.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// GLOBALS
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
bool gQuit = false;
std::vector<GameObject*> GameObjects;

bool init()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not init. SDL Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		gWindow = SDL_CreateWindow("SDL gigachad", 
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(gWindow == NULL)
		{
			printf("failed to create window. SDL Error: %s\n", SDL_GetError());
			return false;
		}
		else
		{

			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if(!gRenderer)
			{
				printf("Failed to create renderer. %s", SDL_GetError());
				return false;
			}

		}
	}
	return true;

}

void close()
{
	// closes the sdl program
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL; // TODO test if these NULL's are necessary
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}


void InputCheck()
{
	SDL_Event event;
	while(SDL_PollEvent(&event) != 0){
		if(event.type == SDL_QUIT) // this seems to trigger when you hit the X in windows etc.
		{
			gQuit = true;
		}
		else if (event.type ==  SDL_MOUSEBUTTONDOWN)
		{
			switch(event.button.button)
			{
				case SDL_BUTTON_LEFT:
					SDL_Log("left click");
					break;
				case SDL_BUTTON_RIGHT:
					SDL_Log("Right click");
					break;
				case SDL_BUTTON_MIDDLE:
					SDL_Log("Middle click");
					break;
			}
		}
		else if (event.type == SDL_KEYDOWN)
		{
			//SDL_Log("%s pressed", SDL_GetKeyName(event.key.keysym.sym));
			switch(event.key.keysym.sym){
				case SDLK_ESCAPE:
					gQuit=true;
					break;
				case SDLK_f:
					SDL_Log("F pressed");
					break;

			}
		}
	}
}


int rng(int lower, int upper)
{
	int range = upper - lower + 1;
	int num = std::rand() % range + lower;
	return num;
}


int main(int argc, char* args[]) {
	if(init() == false)
	{
		// something failed to initialize, we die
		return 1;
	}


	// create a bunch of game objects
	for(int i = 0; i < 100; i++)
	{
		GameObject* go = new GameObject("random object");
		int r = rng(0,500);
		int r2 = rng(0,500);
		int rcolor = rng(0,255);
		int rsize = rng(5,20);
		go->transform.position = Vector3(r,r2,0);

		RenderCircleComponent* rcc = new RenderCircleComponent(gRenderer, rcolor, 128,128, rsize);
		rcc->gameObject = go;
		go->components.push_back(rcc);
		
		GameObjects.push_back(go);
	}

	// create a GameObject
	GameObject* A = new GameObject("GameObject A");
	A->transform.position = Vector3(100,100,0);

	// add some components to it
	RenderCircleComponent* rcc = new RenderCircleComponent(gRenderer, 0,255,0,10);
	rcc->gameObject = A;
	A->components.push_back(rcc);

	TestComponent* tc = new TestComponent(); // TODO should try to push our gameobject in the constructor
	tc->gameObject = A; // so we dont need to do this everytime
	A->components.push_back(tc);

	GameObjects.push_back(A); // add it to the global GameObjects array (vector actually)

	// another GameObject...
	GameObject* B = new GameObject("B");
	B->transform.position = Vector3(0,0,0);
	RenderCircleComponent* rcc2 = new RenderCircleComponent(gRenderer, 255,0,0, 15);
	rcc2->gameObject = B;
	B->components.push_back(rcc2);

	TestComponent* tc2 = new TestComponent();
	tc2->gameObject = B;
	B->components.push_back(tc2);

	GameObjects.push_back(B);

	while(!gQuit)
	{
		SDL_RenderClear(gRenderer);

		// main loop
		
		for(auto & go : GameObjects) // Iterate over all GameObjects
		{
			// Iterate over all components on the GameObject and run their Tick()
			for(auto & component : go->components)
			{
				component->Tick();
			}

			go->transform.position += Vector3(2,1,0);
			go->transform.position *= 1.01;

			// clamp to screen
			if(go->transform.position.x > SCREEN_WIDTH){
				go->transform.position.x = 0;
			}
			if(go->transform.position.y > SCREEN_HEIGHT)
			{
				go->transform.position.y = 0;
			}
		}

		// restore draw color to black so the background remains black
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

		// and finally present the frame
		SDL_RenderPresent(gRenderer);

		InputCheck();

	}

	close();
	return 0;
}
