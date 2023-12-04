#include "Transform.h"


void Transform::Move(float dX, float dY, float dZ)
{
	position.x += dX;
	position.y += dY;
	position.z += dZ;
}

void Transform::SetPosition(float X, float Y, float Z)
{
	position.x = X;
	position.y = Y;
	position.z = Z;
}

