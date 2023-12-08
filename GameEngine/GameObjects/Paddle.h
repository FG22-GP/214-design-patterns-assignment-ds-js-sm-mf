#pragma once
#include "../GameObject.h"
#include "../Graphics.h"

class Paddle : public GameObject
{
public:
    void Start() override;
    void Tick() override;


    Paddle()
    {
    }
    
};
