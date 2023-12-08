#pragma once
#include "Vector2.h"
#include "Vector3.h"


class Transform
{
public:
    Vector3 position = Vector3(0,0,0);
    Vector3 rotation = Vector3(0,0,0);
    Vector3 scale = Vector3(1.0,1.0,1.0);
    

    void Move(float dX, float dY);
    void SetPosition(float X, float Y);

    Transform(Vector3 inPosition = Vector3(0,0,0), Vector3 inRotation = Vector3(0,0,0), Vector3 inScale = Vector3(1,1,1))
    {
        position = inPosition;
        rotation = inRotation;
        scale = inScale;
    }
};
