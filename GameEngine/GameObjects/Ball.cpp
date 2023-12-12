#include "Ball.h"

#include <algorithm>
#include <SDL_system.h>

#include "../Components/CircleRender.h"
#include "../Components/Collision.h"

Vector2 Ball::GetRandomDirection()
{
    const float randomY = Random::RandomFloat(-0.3f, 0.3f);
    const float randomX = Random::RandomFloat(-1, 1) + 0.3f;

    return Vector2(randomX, randomY).Normalize();
}

void Ball::Start()
{
    GameObject::Start();
    CurrentSpeed = Speed;

    rcc = new CircleRender(r, g, b, size);
    AddComponent(rcc);
    bc = new BoxCollider(transform.position.x, transform.position.y, size / 2, size / 2);
    AddComponent(bc);
    Reset();

    name = "Ball";
}

// auto randomOffset = Direction.x > 0? Vector2(MathHelpers::RandomFloat( 0, 1),MathHelpers::RandomFloat( 0, 1) ):  Vector2(MathHelpers::RandomFloat( -1, 0), MathHelpers::RandomFloat(-1, 0));
void Ball::Tick()
{
    GameObject::Tick();
    if (bc->NeedToHandleCollision)
    {
        bc->NeedToHandleCollision = false;
        Direction.x = -Direction.x;
        CurrentSpeed += 20;
    }

    Move();
}

void Ball::Reset()
{
    CurrentSpeed = Speed;
    Direction = GetRandomDirection();
}

void Ball::Move()
{
    transform.position += Direction * CurrentSpeed * DELTATIME;

    if (transform.position.x - size < 0 || transform.position.x + size > SCREEN_WIDTH)
    {
        Direction.x = -Direction.x;
    }
    if (transform.position.y - size < 0 || transform.position.y + size > SCREEN_HEIGHT)
    {
        Direction.y = -Direction.y;
    }
}
