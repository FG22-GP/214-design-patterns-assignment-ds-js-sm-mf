#include "CircleCollider.h"

#include "BoxCollider.h"

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

        auto Collider = this->gameObject ->GetComponent<BoxCollider>();
        auto otherCollider = c->gameObject->GetComponent<BoxCollider>();
        //auto Distance = Vector3::Distance(circlePosition, paddlePosition);
        // printf("%s distance to %s: %f\n", gameObject->name.c_str(), c->gameObject->name.c_str(), Distance);
        printf("\n null" );
        if (!Collider)
        {
            
        }
        SDL_Rect* result = nullptr;
        if (SDL_IntersectRect(Collider->GetCollider(), otherCollider->GetCollider(), result))
        {
            if (result)
            {
                HandleCollision();
            }
        }
    }
}

void CircleCollider::HandleCollision()
{
    Collision::HandleCollision();
    NeedToHandleCollision = true;
}
