#include "GameObject.h"

#include "Component.h"

void GameObject::Start()
{
}

void GameObject::Tick()
{
    // Tick our components
    for (auto& component : components)
    {
        component->Tick();
    }
}

void GameObject::AddComponent(Component* NewComponent)
{
    NewComponent->gameObject = this;
    components.push_back(NewComponent);
}

void GameObject::Destroy()
{
    // find ourselves in the GAMEOBJECTS array and remove us from there
    for(int i = 0; i < GAMEOBJECTS.size(); i++)
    {
        if(GAMEOBJECTS[i] == this)
        {
            GAMEOBJECTS.erase(GAMEOBJECTS.begin() + i);
            return;
        }
    }
    // probably some more cleanup to do...
}

