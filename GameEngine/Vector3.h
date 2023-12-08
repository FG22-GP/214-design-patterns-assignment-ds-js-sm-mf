#pragma once
#include "Vector2.h"

class Vector3
{
public:
    float x,y,z;

    Vector3() : x(0), y(0), z(0) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    Vector3 operator+(const Vector3& other);
    Vector3 operator+=(const Vector3& other);
    Vector3 operator*(float factor);
    Vector3 operator*=(float factor);
    Vector3 operator-(const Vector3& other);
    Vector3 operator-=(const Vector3& other);

    Vector3 operator=(const Vector2& other);
    Vector3 operator+=(const Vector2& other);
};
