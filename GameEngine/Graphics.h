#pragma once

#include <vector>
#include <set>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Transform.h"

class RenderObject;

class Graphics
{
public:
	static bool Initialize(const char* windowTitle, int Width = 640, int Height = 480);
	static void Exit();
	static void PresentFrame(void);
	static void ClearFrame(void);
	static void RenderCircle(int x, int y, int radius, unsigned char r = 255, unsigned char g = 255, unsigned char b = 255, unsigned char a = 0);
	static void RenderSquare(int x, int y, int width, int height, unsigned char r = 255, unsigned char g = 255, unsigned char b = 255, unsigned char a = 0);
	static SDL_Window* GetWindow();
};

class RenderObject
{
public:

	virtual void Render(Transform* t) = 0;

	void SetPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

	bool Hide;
	int xpos = 0;
	int ypos = 0;
};

class Sprite : public RenderObject
{
public:
	void Render(Transform* t);

	void Set(int x, int y, double angle = 0.0, int textureIndex = -1, SDL_Point center = { 32, 32 }, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void Set(int textureIndex);

	int textureIdx;

private:
	SDL_Texture* texture;
	SDL_Rect renderQuad;
	SDL_Rect clip;
	double angle;
	SDL_Point center;
	SDL_RendererFlip flip;

};

class Rectangle : public RenderObject
{
public:
	void Render(Transform* t);

	void SetSize(int Width, int Height);
	void SetColor(unsigned char r, unsigned char g, unsigned char b);

private:
	SDL_Rect renderQuad;
	SDL_Color renderColor;

};

class Circle : public RenderObject
{
public:
	void Render(Transform* t);

	void SetSize(int Width, int Height);
	void SetColor(unsigned char r, unsigned char g, unsigned char b);

private:
	SDL_Rect renderQuad;
	SDL_Color renderColor;

};

class Text : public RenderObject
{
public:

	void Render(Transform* t);

	void SetText(std::string text, unsigned char r = 255, unsigned char g = 255, unsigned char b = 255, unsigned char a = 0);

private:
	SDL_Texture* fontTexture = NULL;
	int width;
	int height;
};