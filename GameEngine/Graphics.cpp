#include "Graphics.h"

SDL_Renderer* renderer = NULL;
TTF_Font* font = NULL;
SDL_Window* window = NULL;

int screen_width;
int screen_height;

bool initDone = false;

void Graphics::ClearFrame()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
}

void Graphics::PresentFrame()
{
	SDL_RenderPresent(renderer);
}

bool Graphics::Initialize(const char* windowTitle, int Width, int Height)
{
	if (initDone) return false;

	screen_width = Width;
	screen_height = Height;

	bool ok = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		ok = false;
	}

	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		ok = false;
	}

	font = TTF_OpenFont("font/lazy.ttf", 28);
	if (font == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		ok = false;
	}

	if (ok)
	{
		window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WindowFlags::SDL_WINDOW_ALLOW_HIGHDPI);

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		ok = renderer;
	}

	if (ok)
	{
		initDone = true;
		printf("graphics lib init ok\n");
	}

	return ok;
}

void Graphics::Exit()
{
	if (initDone)
	{
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
		SDL_DestroyWindow(window);
		window = NULL;
		SDL_Quit();
		initDone = false;
	}
}

void Graphics::RenderSquare(int x, int y, int width, int height, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_Rect rect = SDL_Rect(x, y, width, height);
	SDL_RenderFillRect(renderer, &rect);
}

SDL_Window* Graphics::GetWindow()
{
	return window;
}

void Graphics::RenderCircle(int x, int y, int radius, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);


	//https://gist.github.com/Gumichan01/332c26f6197a432db91cc4327fcabb1c

	int offsetx, offsety, d;
	int status;

	offsetx = 0;
	offsety = radius;
	d = radius - 1;
	status = 0;

	while (offsety >= offsetx) {

		status += SDL_RenderDrawLine(renderer, x - offsety, y + offsetx,
			x + offsety, y + offsetx);
		status += SDL_RenderDrawLine(renderer, x - offsetx, y + offsety,
			x + offsetx, y + offsety);
		status += SDL_RenderDrawLine(renderer, x - offsetx, y - offsety,
			x + offsetx, y - offsety);
		status += SDL_RenderDrawLine(renderer, x - offsety, y - offsetx,
			x + offsety, y - offsetx);

		if (status < 0) {
			status = -1;
			break;
		}

		if (d >= 2 * offsetx) {
			d -= 2 * offsetx + 1;
			offsetx += 1;
		}
		else if (d < 2 * (radius - offsety)) {
			d += 2 * offsety - 1;
			offsety -= 1;
		}
		else {
			d += 2 * (offsety - offsetx - 1);
			offsety -= 1;
			offsetx += 1;
		}
	}

}

void Text::SetText(std::string text, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	if (fontTexture != NULL)
	{
		SDL_DestroyTexture(fontTexture);
		fontTexture = NULL;
		width = 0;
		height = 0;
	}

	SDL_Color col = { r, g, b, a };

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), col);
	if (textSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		fontTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (fontTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			width = textSurface->w;
			height = textSurface->h;
		}
		SDL_FreeSurface(textSurface);
	}

}

void Text::Render(Transform* t)
{
	if (renderer == NULL || fontTexture == NULL) return;
	SDL_Rect rq = { xpos + t->position.x, ypos + t->position.y, width * t->scale.x, height * t->scale.y };
	SDL_RenderCopy(renderer, fontTexture, NULL, &rq);
}
