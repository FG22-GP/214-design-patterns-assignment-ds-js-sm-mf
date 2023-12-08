#pragma once

#include <vector>
#include <set>
#include <SDL.h>
#include <SDL_ttf.h>

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
	RenderObject();
	~RenderObject();

	virtual void Render() = 0;

	bool Hide;
};

class Sprite : public RenderObject
{
public:
	void Render();

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
	void Render();

	void SetPos(int x, int y, int width, int height);
	void SetSize(int Width, int Height);
	void SetColor(unsigned char r, unsigned char g, unsigned char b);

private:
	SDL_Rect renderQuad;
	SDL_Color renderColor;

};

class Circle : public RenderObject
{
public:
	void Render();

	void SetPos(int x, int y, int width, int height);
	void SetSize(int Width, int Height);
	void SetColor(unsigned char r, unsigned char g, unsigned char b);

private:
	SDL_Rect renderQuad;
	SDL_Color renderColor;

};

class Text : public RenderObject
{
public:
	Text();
	~Text();

	void Render();

	void Set(int x, int y);
	void Set(const char* text);

private:
	SDL_Texture* fontTexture;
	SDL_Rect renderQuad;
	int width;
	int height;
};