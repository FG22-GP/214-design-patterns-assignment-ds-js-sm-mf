#pragma once
#include "../../../../GameEngine/Component.h"

class CollisionComponent : public Component
{
public:
    
    SDL_Rect collisionBox;

    CollisionComponent(float x , float  y, float width, float height);

    virtual void HandleCollision();

    void Tick() override;
    
};
