#pragma once
#include "../Component.h"

class CircleRender : public Component
{
	public:
		int r, g, b;
		int radius;


		CircleRender(int red, int green, int blue, int rad)
		{
			r = red;
			g = green;
			b = blue;
			radius = rad;
		}

		void Tick();
};
