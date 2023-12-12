#pragma once
#include "../Component.h"
#include "../Graphics.h"

class TextRender : public Component
{
public:
    void Tick() override;


    int r, g, b;
    int x, y;

    Text textObj;
    std::string currentText;

    void SetText(std::string text);

    TextRender(int red = 255, int green = 255, int blue = 255)
    {
        r = red;
        g = green;
        b = blue;

    }
};
