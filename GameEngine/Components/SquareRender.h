#pragma once
#include "../Component.h"
#include "../Graphics.h"

class SquareRender : public Component
{
public:
    void Tick() override;


    int r, g, b;
    int w, h;


    SquareRender(int red = 255, int green = 255, int blue = 255, int width = 10, int height = 100)
    {
        r = red;
        g = green;
        b = blue;
        w = width;
        h = height;
        
    }
};
