#include "Ball.h"

#include "../Components/CircleRender.h"

void Ball::Start()
{
    GameObject::Start();

    CircleRender* rcc = new CircleRender(r, g, b, size);
    AddComponent(rcc);

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
