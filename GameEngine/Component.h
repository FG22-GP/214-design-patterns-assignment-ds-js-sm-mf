#pragma once
#include "GameObject.h"

class Component
{
	public:
	virtual ~Component() = default;
	GameObject *gameObject;
		virtual void Tick(double DeltaTime) = 0;
};
