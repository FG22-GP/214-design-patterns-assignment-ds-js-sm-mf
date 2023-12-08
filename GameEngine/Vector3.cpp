#include "Vector3.h"


Vector3 Vector3::operator+(const Vector3& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3 Vector3::operator+=(const Vector3& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3 Vector3::operator*(float factor)
{
    x *= factor;
    y *= factor;
    z *= factor;
    return *this;
}

Vector3 Vector3::operator*=(float factor)
{
    x *= factor;
    y *= factor;
    z *= factor;
    return *this;
}

Vector3 Vector3::operator-(const Vector3& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector3 Vector3::operator-=(const Vector3& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector3 Vector3::operator=(const Vector2& other)
{
    x = other.x;
    y = other.y;
    // z = z;
    return *this;
}

Vector3 Vector3::operator+=(const Vector2& other)
{
    x += other.x;
    y += other.y;
    // z = z;
    return *this;
}
