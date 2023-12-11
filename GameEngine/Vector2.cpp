#include "Vector2.h"



Vector2 Vector2::operator+(const Vector2& other)
{
    x += other.x;
    y += other.y;
    return *this;
}

Vector2 Vector2::operator+=(const Vector2& other)
{
    
    x += other.x;
    y += other.y;
    return *this;
}

Vector2 Vector2::operator*(const float factor)
{
    return Vector2(x * factor, y * factor);
}

Vector2 Vector2::operator*=(const float factor)
{
    x *= factor;
    y *= factor;
    return *this;
}

Vector2 Vector2::operator-(const Vector2& other) 
{
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2 Vector2::operator-=(const Vector2& other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}
