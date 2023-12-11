#include "SquareRender.h"

void SquareRender::Tick()
{
    Graphics::RenderSquare(gameObject->transform.position.x, gameObject->transform.position.y, 1 * gameObject->transform.scale.x, 1 * gameObject->transform.scale.y, r,g,b,1);
}

void SquareRender::SetColor(int inRed, int inGreen, int inBlue)
{
    r = inRed;
    g = inGreen;
    b = inBlue;
}
