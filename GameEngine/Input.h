#pragma once
#include <SDL_keycode.h>
#include <SDL_events.h>
#include <vector>
#include <tuple>

enum Button { UNKNOWN, P1_UP, P1_DOWN, P2_UP, P2_DOWN, START };

class Input
{
public:
    static void Initialize();
    static void CheckForInput();
    static bool IsKeyDown(SDL_Keycode key);
    static bool IsButtonDown(Button b);
    static std::vector<SDL_Keycode> GetKeysDown();

private:
    inline static std::vector<SDL_Keycode> keys_down;
    inline static std::vector<std::tuple<Button, SDL_Keycode>> mappings;
    inline static std::vector<SDL_Keycode> tracked_keys;
    inline static std::vector<Button> buttons_down;

    static void KeyDown(SDL_Keycode key);
    static void KeyUp(SDL_Keycode key);

    static Button MapKeyToButton(SDL_Keycode key);
};
