#include "Ball.h"

#include "../Components/RenderCircleComponent.h"

void Ball::Start()
{
    GameObject::Start();

    RenderCircleComponent* rcc = new RenderCircleComponent(r, g, b, size);
    AddComponent(rcc);

    printf("Hello from ball\n");
}

void Ball::Tick()
{
    GameObject::Tick();

    transform.position += Vector2(50, 50) * DELTATIME;

    if (transform.position.x > SCREEN_WIDTH)
    {
        transform.position.x = 0;
    }
    if (transform.position.y > SCREEN_HEIGHT)
    {
        transform.position.y = 0;
    }
}
