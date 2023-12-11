#include "Paddle.h"

#include "../Components/SquareRender.h"

void Paddle::Start()
{
    GameObject::Start();

    SquareRender* sr = new SquareRender(0, 255);
    AddComponent(sr);
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
}
