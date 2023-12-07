﻿#pragma once
#include <string>
#include <vector>

#include "Global.h"
#include "Transform.h"

class Component; // forward declaration

class GameObject
{
	public:
		std::string name;
		Transform transform;
		std::vector<Component*> components;
		bool active = true;
		bool visible = true;

		GameObject(std::string inname = "GameObject"){
			name = inname;
			GAMEOBJECTS.push_back(this);
		}

};
