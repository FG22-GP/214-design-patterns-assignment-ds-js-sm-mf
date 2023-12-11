#include "Ball.h"

#include "../Components/CircleRender.h"
#include "../Components/Collision.h"
#include "../Components/Colliders/CircleCollider.h"

void Ball::Start()
{
    GameObject::Start();

    CircleRender* rcc = new CircleRender(r, g, b, size);
    AddComponent(rcc);

    cc = new CircleCollider(size/2);
    AddComponent(cc);

    name = "Ball";

    printf("Hello from ball\n");
}

void Ball::Tick()
{
    GameObject::Tick();

    if(cc->NeedToHandleCollision)
    {
        cc->NeedToHandleCollision = false;
        Direction = Direction * -1;
    }

    Move();
}

void Ball::Move()
{
    transform.position += Direction * Speed * DELTATIME;
    
    if (transform.position.x - size < 0 || transform.position.x + size > SCREEN_WIDTH)
    {
        Direction.x = -Direction.x;
    }
    if (transform.position.y - size < 0 || transform.position.y + size > SCREEN_HEIGHT)
    {
        Direction.y = -Direction.y;
    }
}
