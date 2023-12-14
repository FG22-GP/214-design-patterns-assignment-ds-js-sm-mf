#include "CircleRender.h"
#include "../Graphics.h"

void CircleRender::Tick()
{
    Graphics::RenderCircle(gameObject->transform.position.x, gameObject->transform.position.y, radius, r, g, b);
}
