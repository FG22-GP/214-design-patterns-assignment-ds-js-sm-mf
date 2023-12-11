#include "CircleCollider.h"

void CircleCollider::Start()
{
    Collision::Start();
}

void CircleCollider::Tick()
{
    Collision::Tick();

    // find nearest collider thats not ourselves
    for (auto& c : COLLIDERS)
    {
        if (c == this)
        {
            continue;
        }

        auto ourPosition = this->gameObject->transform.position;
        auto theirPoisition = c->gameObject->transform.position;
        auto Distance = Vector3::Distance(ourPosition, theirPoisition);
        // printf("%s distance to %s: %f\n", gameObject->name.c_str(), c->gameObject->name.c_str(), Distance);

        if (Distance < radius)
        {
            HandleCollision();
        }
    }
}

void CircleCollider::HandleCollision()
{
    Collision::HandleCollision();
    NeedToHandleCollision = true;
}
