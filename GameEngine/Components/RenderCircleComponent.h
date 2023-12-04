#pragma once
#include "../Component.h"
#include <SDL.h>

class RenderCircleComponent : public Component
{
	public:
		SDL_Renderer* renderer;
		int r, g, b;
		int radius;


		RenderCircleComponent(SDL_Renderer* render, int red, int green, int blue, int rad)
		{
			r = red;
			g = green;
			b = blue;
			radius = rad;
			renderer = render;
		}

		void Tick();
};
