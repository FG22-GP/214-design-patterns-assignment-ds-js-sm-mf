#pragma once
#include <vector>
#include <ctime>
#include <iostream>
#include "GameObjects/GameManager.h"
#include "GameObject.h"
#include "Graphics.h"
#include "Global.h"
#include "Input.h"

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


    // only object we need to add here (GameManager will spawn the paddles etc)
    GameManager* GM = new GameManager();
    GM->Start(); // would be nice if this would be called automatically from the constructor but cant since its virtual


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
        SDL_SetWindowTitle(Graphics::GetWindow(), WindowTitle.c_str());

        for (auto& go : GAMEOBJECTS) // Iterate over all GameObjects
        {
            if (go->active == false)
            {
                continue; // this gameobject is inactive, dont do anything
            }
            go->Tick(); // tick the game object (and its components) 
        }

        
        Graphics::PresentFrame();
    }

    Graphics::Exit();
    return 0;
}
