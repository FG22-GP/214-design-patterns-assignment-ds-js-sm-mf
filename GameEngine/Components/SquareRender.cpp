#include "SquareRender.h"

void SquareRender::Tick()
{
    Graphics::RenderSquare(gameObject->transform.position.x, gameObject->transform.position.y, 20 * gameObject->transform.scale.x, 100 * gameObject->transform.scale.y, 255,255,255,1);
}
