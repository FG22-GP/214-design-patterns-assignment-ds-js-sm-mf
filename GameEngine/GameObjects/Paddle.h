#pragma once
#include "../GameObject.h"
#include "../Graphics.h"
#include "../Input.h"

class Paddle : public GameObject
{
public:
    void Start() override;
    void Tick() override;

    int Speed = 300;
    int Player = 1;

    Paddle(int inPlayer = 1)
    {
        Player = inPlayer;
    }
    
};
