#pragma once
#include <string>
#include <vector>

#include "Global.h"
#include "Transform.h"
#include "Vector2.h"

class Component; // forward declaration

class GameObject
{
	public:
		std::string name;
		Transform transform;
		std::vector<Component*> components;
		bool active = true;
		bool visible = true;

		GameObject(std::string inName = "GameObject", Transform inTransform = Transform(Vector2(0,0))){
			name = inName;
			transform = inTransform;
			GAMEOBJECTS.push_back(this);
		}
	
		virtual void Start();
		virtual void Tick();
};
