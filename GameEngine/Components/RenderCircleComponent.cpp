#include "RenderCircleComponent.h"
#include "../Graphics.h"

void RenderCircleComponent::Tick()
{

    Graphics::RenderCircle(gameObject->transform.position.x, gameObject->transform.position.y, radius, r, g, b);

}
