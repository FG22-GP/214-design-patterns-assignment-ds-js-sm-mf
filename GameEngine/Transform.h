#pragma once
#include "Vector2.h"


class Transform
{
public:
    Vector2 position;

    void Move(float dX, float dY);
    void SetPosition(float X, float Y);

    Transform(Vector2 inPosition = Vector2(0,0))
    {
        position = inPosition;
    }
};
