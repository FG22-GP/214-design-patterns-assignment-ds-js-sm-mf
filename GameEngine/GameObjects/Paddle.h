#pragma once
#include "../GameObject.h"
#include "../Input.h"
#include "../Components/Colliders/BoxCollider.h"

class Paddle : public GameObject
{
public:
    void Start() override;
    void Tick() override;

    BoxCollider* bc;

    int Speed = 300;
    int Player = 1;

    Paddle(int inPlayer = 1)
    {
        Player = inPlayer;
    }
    
};
