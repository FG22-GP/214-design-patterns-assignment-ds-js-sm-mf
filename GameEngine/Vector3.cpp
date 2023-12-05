#include "Vector3.h"


Vector3 Vector3::operator+(Vector3& other)
{
    return Vector3(x + other.x, y + other.y, z + other.z);
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
    return Vector3(x * factor, y * factor, z * factor);
}

Vector3 Vector3::operator*=(float factor)
{
    x *= factor;
    y *= factor;
    z *= factor;
    return *this;
}

Vector3 Vector3::operator-(const Vector3& other) const
{
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator-=(const Vector3& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}
