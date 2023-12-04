#pragma once
#include "Vector3.h"

// TODO add rotation and scale


class Transform
{
public:
    Vector3 position;

    void Move(float dX, float dY, float dZ);
    void SetPosition(float X, float Y, float Z);
};
