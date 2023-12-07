#pragma once
#include "../Component.h"
#include <SDL.h>
#include "../Global.h" 

class RenderCircleComponent : public Component
{
	public:
		int r, g, b;
		int radius;


		RenderCircleComponent(int red, int green, int blue, int rad)
		{
			r = red;
			g = green;
			b = blue;
			radius = rad;
		}

		void Tick();
};
