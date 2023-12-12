#pragma once
#include "../Collision.h"

class CircleCollider : public Collision
{
public:
    void Start() override;
    void Tick() override;
    void HandleCollision() override;

    float radius = 0;

    CircleCollider(float inRadius)
    {
        radius = inRadius;
    }
    
    
};
