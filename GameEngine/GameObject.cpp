#include "GameObject.h"

#include "Component.h"

void GameObject::Start()
{
    printf("Start from GameObject base: %s\n", name.c_str());
}

void GameObject::Tick()
{
    // Tick our components
    for(auto & component : components)
    {
        component->Tick();
    }
}
