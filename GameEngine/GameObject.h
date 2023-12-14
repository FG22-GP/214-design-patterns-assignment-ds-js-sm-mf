#pragma once
#include <string>
#include <vector>
#include "Global.h"
#include "Transform.h"

// GameObject is basically our MonoBehaviour

class Component; // forward declaration

class GameObject
{
public:
    virtual ~GameObject() = default;
    std::string name;
    Transform transform;
    bool active = true;
    bool visible = true;
    std::vector<Component*> components;

    virtual void Start();
    virtual void Tick();
    void AddComponent(Component* NewComponent);
    void Destroy();

    template <class T> T* GetComponent();
    
    GameObject(std::string inName = "GameObject", Transform inTransform = Transform())
    {
        name = inName;
        transform = inTransform;
        GAMEOBJECTS.push_back(this);
    }
    
};

template <class T> // this only works if its here, get unresolved externals if we move it to the .cpp file
T* GameObject::GetComponent()
{
    for(Component* co : components)
    {
        if ( T* castedComponent = dynamic_cast<T*>(co))
        {
            return castedComponent;
        }
    }
    return nullptr;
}
