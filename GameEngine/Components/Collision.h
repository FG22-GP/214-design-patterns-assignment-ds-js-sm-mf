#pragma once
#include "../Component.h"
#include "../Global.h"

class Collision : public Component
{
public:
    void Start() override;
    void Tick() override;
    virtual void HandleCollision();

    Collision()
    {
        COLLIDERS.push_back(this);
    }
};
