#include "Input.h"

#include <string>

#include "Global.h"


void Input::Initialize()
{
    tracked_keys.clear();
    mappings.clear();

    // add keys we care about
    tracked_keys.push_back(SDLK_w);
    tracked_keys.push_back(SDLK_s);
    tracked_keys.push_back(SDLK_UP);
    tracked_keys.push_back(SDLK_DOWN);
    tracked_keys.push_back(SDLK_ESCAPE);
    tracked_keys.push_back(SDLK_r);

    // map sdl keys to buttons
    // ideally this should read mappings from a file (like json) or something
    mappings.push_back(std::make_tuple(START, SDLK_ESCAPE));
    mappings.push_back(std::make_tuple(RESTART, SDLK_r));
    mappings.push_back(std::make_tuple(P1_UP, SDLK_w));
    mappings.push_back(std::make_tuple(P1_DOWN, SDLK_s));
    mappings.push_back(std::make_tuple(P2_UP, SDLK_UP));
    mappings.push_back(std::make_tuple(P2_DOWN, SDLK_DOWN));
    // could probably iterate over the mappings to automatically populate tracked_keys


}

void Input::CheckForInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_KEYDOWN)
        {
            KeyDown(event.key.keysym.sym);
        }
        else if (event.type == SDL_KEYUP)
        {
            KeyUp(event.key.keysym.sym);
        }
        else if (event.type == SDL_QUIT) // this should probably not be in here but oh well
        {
           QUIT_REQUESTED = true; 
        }
    }
}

bool Input::IsKeyDown(SDL_Keycode key)
{
    if (std::find(keys_down.begin(), keys_down.end(), key) != keys_down.end())
    {
        return true;
    }
    return false;
}

bool Input::IsButtonDown(Button b)
{
    if (std::find(buttons_down.begin(), buttons_down.end(), b) != buttons_down.end())
    {
        return true;
    }
    return false;
}

std::vector<SDL_Keycode> Input::GetKeysDown()
{
    return keys_down;
}

void Input::KeyDown(SDL_Keycode key)
{
    // first check if we care about this key
    if (std::find(tracked_keys.begin(), tracked_keys.end(), key) != tracked_keys.end())
    {
        if (!IsKeyDown(key))
        {
            keys_down.push_back(key);
            buttons_down.push_back(MapKeyToButton(key));
        }
    }
}

void Input::KeyUp(SDL_Keycode key)
{
    if (IsKeyDown(key))
    {
        for (int i = 0; i < keys_down.size(); i++)
        {
            if (keys_down[i] == key)
            {
                keys_down.erase(keys_down.begin() + i);
                buttons_down.erase(buttons_down.begin() + i); // should work since we add them at the same time in KeyDown
            }
        }
    }
}

Button Input::MapKeyToButton(SDL_Keycode key)
{
    for(auto & mapping : mappings)
    {
        SDL_Keycode k = get<1>(mapping);
        if (k == key)
        {
            return get<0>(mapping);
        }
    }
    return UNKNOWN;
}
