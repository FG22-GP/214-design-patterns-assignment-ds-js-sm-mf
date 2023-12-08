#pragma once
#include <vector>
#include <ctime>
#include <iostream>
#include "GameObject.h"
#include "Transform.h"
#include "Graphics.h"
#include "Global.h"
#include "Input.h"
#include "GameObjects/Paddle.h"

int main(int argc, char* args[])
{
    if (Graphics::Initialize("Pong") == false)
    {
        // something failed to initialize, we die
        return 1;
    }
    srand(time(nullptr)); // initialize random seed
    Input::Initialize();

    // initialize DeltaTime calculation https://gamedev.stackexchange.com/a/110831
    std::string WindowTitle = "Pong - FPS: xxx";
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;

    // add a bunch of balls
    /*
    for (int i = 0; i < 100; i++)
    {
        int r1 = Random::RandomIntInRange(0, 255);
        int r2 = Random::RandomIntInRange(0, 255);
        int r3 = Random::RandomIntInRange(0, 255);
        int rsize = Random::RandomIntInRange(5, 20);
        int rx = Random::RandomIntInRange(0, SCREEN_WIDTH);
        int ry = Random::RandomIntInRange(0, SCREEN_HEIGHT);

        Ball* b = new Ball(Transform(Vector2(rx, ry)), r1, r2, r3, rsize);
    }*/

    Paddle* p1 = new Paddle(1);
    p1->transform.position = Vector2(100, 250);

    Paddle* p2 = new Paddle(2);
    p2->transform.position = Vector2(500,250);

    /*
     * at this point the "scene" should have all the gameobjects in it,
     * as we're about to run Start() and then proceed to the main loop
     */

    // run Start() on all game objects
    for (auto& go : GAMEOBJECTS)
    {
        go->Start();
    }

    while (!QUIT_REQUESTED) // main loop
    {
        Graphics::ClearFrame();
        Input::CheckForInput();

        // calculate DT
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        DELTATIME = ((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

        // put fps/dt in window title 
        WindowTitle = "Pong - FPS: " + std::to_string(1 / DELTATIME) + " (deltatime: " + std::to_string(DELTATIME) + ")";
        SDL_SetWindowTitle(Graphics::GetWindow(), WindowTitle.c_str()); // put fps in window title

        for (auto& go : GAMEOBJECTS) // Iterate over all GameObjects
        {
            if (go->active == false)
            {
                continue; // this gameobject is inactive, dont do anything
            }

            go->Tick(); // tick the game object (and its components) 
        }

        Graphics::PresentFrame();
        if(Input::IsButtonDown(START))
        {
            QUIT_REQUESTED=true;
        }
    }

    Graphics::Exit();
    return 0;
}
