#pragma once
#include "../GameObject.h"
#include "../../ext/SDL2-2.26.4/lib/x64/CollisionComponent.h"

class Ball : public GameObject
{
public:
    void Start() override;
    void Tick() override;
    const float Speed = 100;
    Vector2 Direction = Vector2(1, 1);

    CollisionComponent* collision;
    
    int r, g, b, size;

    Ball(Transform inTransform = Vector3(0,0,0), int red = 255, int green = 0, int blue = 0, int inSize = 10)
    {
        r = red;
        g = green;
        b = blue;
        size = inSize;
        transform = inTransform;
    }

private:
    void Move();
};
