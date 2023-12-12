#include "Paddle.h"

#include "../Components/SquareRender.h"
#include "../Components/Collision.h"
#include "../Components/Colliders/BoxCollider.h"

void Paddle::Start()
{
    GameObject::Start();

    SquareRender* sr = new SquareRender(0, 255);
    AddComponent(sr);

    transform.scale.x = 25;
    transform.scale.y = 100;

    bc = new BoxCollider(transform.position.x, transform.position.y, transform.scale.x, transform.scale.y);
    AddComponent(bc);
}

void Paddle::Tick()
{
    GameObject::Tick();

    // theres probably a prettier way to do this
    if (Player == 1)
    {
        if (Input::IsButtonDown(P1_UP))
        {
            transform.position += Vector2(0, -1) * Speed * DELTATIME;
        }

        if (Input::IsButtonDown(P1_DOWN))
        {
            transform.position += Vector2(0, 1) * Speed * DELTATIME;
        }
    }
    else if (Player == 2)
    {
        if (Input::IsButtonDown(P2_UP))
        {
            transform.position += Vector2(0, -1) * Speed * DELTATIME;
        }

        if (Input::IsButtonDown(P2_DOWN))
        {
            transform.position += Vector2(0, 1) * Speed * DELTATIME;
        }
    }

    // clamp library would be nice
    if (transform.position.y < 0)
    {
        transform.position.y = 0;
    }
    if (transform.position.y > SCREEN_HEIGHT - transform.scale.y)
    {
        transform.position.y = SCREEN_HEIGHT - transform.scale.y;
    }
}