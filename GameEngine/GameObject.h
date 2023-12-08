#pragma once
#include <string>
#include <vector>
#include "Global.h"
#include "Transform.h"

class Component; // forward declaration

class GameObject
{
public:
    virtual ~GameObject() = default;
    std::string name;
    Transform transform;
    std::vector<Component*> components;
    bool active = true;
    bool visible = true;


    GameObject(std::string inName = "GameObject", Transform inTransform = Transform())
    {
        name = inName;
        transform = inTransform;
        GAMEOBJECTS.push_back(this);
    }

    virtual void Start();
    virtual void Tick();
    void AddComponent(Component* NewComponent);
    void Destroy();

private:
    int id;
};
