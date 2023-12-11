#include "Collision.h"

void Collision::Start()
{
    Component::Start();
}

void Collision::Tick()
{
    Component::Tick();
    // printf("Colliders active: %i\n", COLLIDERS.size());
}

void Collision::HandleCollision()
{
}

