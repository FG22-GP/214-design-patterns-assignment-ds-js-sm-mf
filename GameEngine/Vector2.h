#pragma once


class Vector2
{
	public:
		float x,y;

		Vector2() : x(0), y(0)  {}
		Vector2(float x, float y) : x(x), y(y)  {}
	
		Vector2 operator+(const Vector2& other);
		Vector2 operator+=(const Vector2& other);
		Vector2 operator*(float factor);
		Vector2 operator*=(float factor);
		Vector2 operator-(const Vector2& other);
		Vector2 operator-=(const Vector2& other);

};
