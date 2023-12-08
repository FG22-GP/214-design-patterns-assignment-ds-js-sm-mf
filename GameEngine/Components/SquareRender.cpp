#include "SquareRender.h"

void SquareRender::Tick()
{
    Graphics::RenderSquare(gameObject->transform.position.x, gameObject->transform.position.y, 20, 100, 255,255,255,1);
}
