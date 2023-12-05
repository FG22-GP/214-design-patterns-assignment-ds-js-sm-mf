#include "RenderCircleComponent.h"
#include "../Graphics.h"

void RenderCircleComponent::Tick()
{

    GraphicsLib::RenderCircle(gameObject->transform.position.x, gameObject->transform.position.y, radius, r, g, b);

}
