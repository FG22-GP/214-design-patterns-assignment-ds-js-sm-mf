#pragma once
#include "../GameObject.h"
#include "../Components/Colliders/BoxCollider.h"

class CircleRender;

class Ball : public GameObject
{
public:
    void Start() override;
    void Tick() override;
    void Reset();
    float Speed = 150;
    Vector2 Direction;
    CircleRender* rcc;

    int r, g, b, size;

    BoxCollider* bc;

    Ball(Transform inTransform = Vector3(0, 0, 0), int red = 255, int green = 255, int blue = 255, int inSize = 10)
    {
        r = red;
        g = green;
        b = blue;
        size = inSize;
        transform = inTransform;
    }

private:
    void Move();
    float CurrentSpeed;
    Vector2 GetRandomDirection();
};
