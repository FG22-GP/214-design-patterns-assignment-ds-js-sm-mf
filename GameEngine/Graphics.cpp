#include "Graphics.h"
#include <set>

std::set<RenderObject*> RenderObjects;
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

	/*font = TTF_OpenFont("font.ttf", 28);
	if (font == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		ok = false;
	}*/

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

RenderObject::RenderObject()
{
	RenderObjects.insert(this);
	Hide = false;
}

RenderObject::~RenderObject()
{
	RenderObjects.erase(this);
}

void Graphics::RenderSquare(int x, int y, int width, int height, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_Rect rect = SDL_Rect(x, y, width, height);
	SDL_RenderFillRect(renderer, &rect);
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
