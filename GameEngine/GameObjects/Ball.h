#pragma once
#include "../GameObject.h"

class Ball : public GameObject
{
public:
    void Start() override;
    void Tick() override;

    int r, g, b, size;

    Ball(Transform inTransform = Vector2(0,0), int red = 255, int green = 0, int blue = 0, int inSize = 10)
    {
        r = red;
        g = green;
        b = blue;
        size = inSize;
        transform = inTransform;
    }
};
