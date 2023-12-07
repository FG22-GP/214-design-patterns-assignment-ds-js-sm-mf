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
#include "Graphics.h"
#include "Global.h"
#include "GameObjects/Ball.h"
#include "GameObjects/TestGameObject.h"


// GLOBALS
bool gQuit = false;

bool init()
{
	return Graphics::Initialize("test");
}

void close()
{
	Graphics::Exit();
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

	// add stuff to the "scene"
	
	// add a bunch of balls 
	for(int i = 0; i < 100; i++)
	{
		int r1 = Random::RandomIntInRange(0,255);
		int r2 = Random::RandomIntInRange(0,255);
		int r3 = Random::RandomIntInRange(0,255);
		int rsize = Random::RandomIntInRange(5,20);
		int rx = Random::RandomIntInRange(0, SCREEN_WIDTH);
		int ry = Random::RandomIntInRange(0, SCREEN_HEIGHT);

		Ball* b = new Ball(Transform(Vector2(rx,ry)), r1, r2, r3, rsize);
	}

	// add TestGameObject 
	//TestGameObject* testGO = new TestGameObject();

	/*
	 * at this point the "scene" should have all the gameobjects in it,
	 * as we're about to run Start() and then proceed to the main loop
	 */
	
	// run Start() on all game objects
	for(auto & go : GAMEOBJECTS)
	{
		go->Start();
	}

	while(!gQuit) // main loop
	{
		Graphics::ClearFrame();

		// calculate DT
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		DELTATIME = ((NOW - LAST) / (double)SDL_GetPerformanceFrequency() );

		// put fps/dt in window title //sorry i broke it / max
		//WindowTitle = "FPS: " + std::to_string(1/DELTATIME) + " (deltatime: " + std::to_string(DELTATIME) + ")";
		//SDL_SetWindowTitle(gWindow, WindowTitle.c_str()); // put fps in window title
		
		for(auto & go : GAMEOBJECTS) // Iterate over all GameObjects
		{
			if(go->active == false)
			{
				continue; // this gameobject is inactive, dont do anything
			}

			go->Tick(); // tick the game object (and its components) 
		}


		Graphics::PresentFrame();

		InputCheck();

	}

	close();
	return 0;
}
