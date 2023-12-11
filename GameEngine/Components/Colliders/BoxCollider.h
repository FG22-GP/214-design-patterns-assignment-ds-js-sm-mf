#pragma once
#include "../Collision.h"

class BoxCollider : public Collision
{
public:
    void Start() override;
    void Tick() override;
    void HandleCollision() override;
    
};
