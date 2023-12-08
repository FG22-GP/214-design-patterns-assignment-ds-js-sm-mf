#include "Paddle.h"

#include "../Components/SquareRender.h"

void Paddle::Start()
{
    GameObject::Start();

    SquareRender* sr = new SquareRender(0,255);
    AddComponent(sr);
    
}

void Paddle::Tick()
{
    GameObject::Tick();

}
