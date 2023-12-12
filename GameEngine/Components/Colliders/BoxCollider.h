#pragma once
#include <set>

#include "../Collision.h"

class BoxCollider : public Collision
{
public:
    void Start() override;
    void Tick() override;
    void HandleCollision() override;

    SDL_Rect* GetCollider();

    BoxCollider(int x, int y, int width, int height)
    {
        CollisionBox.x = x;
        CollisionBox.y = y;
        CollisionBox.w = width;
        CollisionBox.h = height;
    }

private:
    SDL_Rect CollisionBox;
};

struct HitData
{
    GameObject hitObject;
};
