#include "BoxCollider.h"

void BoxCollider::Start()
{
    Collision::Start();
}

void BoxCollider::Tick()
{
    Collision::Tick();
}

void BoxCollider::HandleCollision()
{
    Collision::HandleCollision();

    printf("Hello from BoxCollider for %s\n", gameObject->name.c_str());
}
