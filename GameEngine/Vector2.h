#pragma once
#include <cmath>
#include "MathHelpers.h"


class Vector2
{
public:
    float x, y;

    Vector2() : x(0), y(0){}
    Vector2(float x, float y) : x(x), y(y){}

    Vector2 operator+(const Vector2& other);
    Vector2 operator+=(const Vector2& other);
    Vector2 operator*(float factor);
    Vector2 operator*=(float factor);
    Vector2 operator-(const Vector2& other);
    Vector2 operator-=(const Vector2& other);

    float Length() const
    {
        return std::sqrt(x * x + y * y);
    }

    Vector2 Normalize() const
    {
        if (Length() != 0.0f)
        {
            return Vector2(x / Length(), y / Length());
        }
        return Vector2();
    }


    static Vector2 FromAngle(float angleDegrees)
    {
        double angleRadians = MathHelpers::AngleToRadians(angleDegrees);

        float vx = std::cos(angleRadians);
        float vy = std::sin(angleRadians);

        return Vector2(vx, vy).Normalize();
    }
};
