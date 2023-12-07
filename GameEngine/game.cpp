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
#include "Components/RenderCircleComponent.h"
#include "Components/TestComponent.h"
#include "Random.h"

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
		int r = Random::RandomIntInRange(0,500);
		int r2 = Random::RandomIntInRange(0,500);
		int rcolor = Random::RandomIntInRange(0,255);
		int rsize = Random::RandomIntInRange(5,20);
		go->transform.position = Vector2(r,r2);

		RenderCircleComponent* rcc = new RenderCircleComponent(gRenderer, rcolor, 128,128, rsize);
		rcc->gameObject = go;
		go->components.push_back(rcc);
		
		GameObjects.push_back(go);
	}

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

			go->transform.position += Vector2(2,1);
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
