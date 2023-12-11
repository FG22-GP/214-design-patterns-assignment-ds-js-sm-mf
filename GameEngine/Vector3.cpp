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

float Vector3::Distance(const Vector3 v1, const Vector3 v2)
{
    float dx = v2.x - v1.x;
    float dy = v2.y - v1.y;
    float dz = v2.z - v1.z;

    return std::sqrt(dx * dx + dy * dy + dz * dz);
}
