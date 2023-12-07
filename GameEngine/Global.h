#pragma once
#include <SDL_render.h>
#include <vector>
class GameObject;


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


#ifndef MY_GLOBALS_H
#define MY_GLOBALS_H


extern double DELTATIME;
extern std::vector<GameObject*> GAMEOBJECTS;
extern SDL_Renderer* G_RENDERER;


#endif