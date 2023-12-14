#pragma once
#include "../GameObject.h"

class TestGameObject : public GameObject
{
public:
    void Start() override;
    void Tick() override;
};
