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
#include "Global.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


// GLOBALS
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
bool gQuit = false;

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

	// initialize DeltaTime calculation https://gamedev.stackexchange.com/a/110831
	std::string WindowTitle = "FPS: xxx";
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;

	// initialize randomness
	srand(time(nullptr));
	

	// create a bunch of game objects
	for(int i = 0; i < 100; i++)
	{
		int r1 = Random::RandomIntInRange(0,255);
		int r2 = Random::RandomIntInRange(0,255);
		int r3 = Random::RandomIntInRange(0,255);
		int rsize = Random::RandomIntInRange(5,20);
		int rx = Random::RandomIntInRange(0, SCREEN_WIDTH);
		int ry = Random::RandomIntInRange(0, SCREEN_HEIGHT);

		// create game object with name and position
		GameObject* go = new GameObject("Random Game Object " + std::to_string(i), Vector2(rx,ry));
		//go->transform.position = Vector2(rx,ry); // can also set position like this

		RenderCircleComponent* rcc = new RenderCircleComponent(gRenderer, r1, r2,r3, rsize);
		rcc->gameObject = go;
		go->components.push_back(rcc);

		// the test component just spams the gameobject name deltatime (useful for testing)
		/*
		TestComponent* tcc = new TestComponent();
		tcc->gameObject = go;
		go->components.push_back(tcc);
		*/

		// game object gets added to global GAMEOBJECTS array in GameObject constructor...
		// ...no need to add it here anymore :)
	}

	while(!gQuit)
	{
		SDL_RenderClear(gRenderer);

		// main loop

		// calculate DT
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		DELTATIME = ((NOW - LAST) / (double)SDL_GetPerformanceFrequency() );

		WindowTitle = "FPS: " + std::to_string(1/DELTATIME) + " (deltatime: " + std::to_string(DELTATIME) + ")";
		SDL_SetWindowTitle(gWindow, WindowTitle.c_str()); // put fps in window title
		
		for(auto & go : GAMEOBJECTS) // Iterate over all GameObjects
		{
			if(go->active == false)
			{
				continue; // this gameobject is inactive, dont do anything
			}
			
			// Iterate over all components on the GameObject and run their Tick()
			for(auto & component : go->components)
			{
				component->Tick();
			}

			// move the game object
			go->transform.position += Vector2(5,5) * DELTATIME;

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
