#include "Ball.h"

#include "../../ext/SDL2-2.26.4/lib/x64/CollisionComponent.h"
#include "../Components/CircleRender.h"

void Ball::Start()
{
    GameObject::Start();

    CircleRender* rcc = new CircleRender(r, g, b, size);
    AddComponent(rcc);
    collision = new CollisionComponent(this->transform.position.x , this->transform.position.y, transform.scale.x, transform.scale.y);
    AddComponent(collision);

    printf("Hello from ball\n");
}

void Ball::Tick()
{
    GameObject::Tick();
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
