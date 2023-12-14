#include "Transform.h"


void Transform::Move(float dX, float dY)
{
	position.x += dX;
	position.y += dY;
}

void Transform::SetPosition(float X, float Y)
{
	position.x = X;
	position.y = Y;
}

