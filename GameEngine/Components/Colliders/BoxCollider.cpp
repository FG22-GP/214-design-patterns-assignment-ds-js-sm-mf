#include "BoxCollider.h"

#include "../../GameObjects/Ball.h"

void BoxCollider::Start()
{
    Collision::Start();
    CollisionBox.w = gameObject->transform.scale.x;
    CollisionBox.h = gameObject->transform.scale.y;
}

void BoxCollider::Tick()
{
    Collision::Tick();

    CollisionBox.x = gameObject->transform.position.x;
    CollisionBox.y = gameObject->transform.position.y;

    for (auto& c : COLLIDERS)
    {
        if (c == this)
        {
            continue;
        }

        auto Collider = this->gameObject->GetComponent<BoxCollider>();
        auto OtherCollider = c->gameObject->GetComponent<BoxCollider>();
  
        SDL_Rect result;
        if (SDL_IntersectRect(Collider->GetCollider(), OtherCollider->GetCollider(), &result))
        {
            NeedToHandleCollision = true;
        }
    }
}

void BoxCollider::HandleCollision()
{
    Collision::HandleCollision();
    NeedToHandleCollision = true;
}

SDL_Rect* BoxCollider::GetCollider()
{
    return &CollisionBox;
}
