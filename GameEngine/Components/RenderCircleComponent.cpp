﻿#include "RenderCircleComponent.h"

void RenderCircleComponent::Tick()
{
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    for (int y = -radius; y <= radius; y++)
    {
        for (int x = -radius; x <= radius; x++)
        {
            if ((x * x) + (y * y) <= radius * radius) // if distance <= radius = we draw a pixel
            {
                SDL_RenderDrawPoint(renderer, gameObject->transform.position.x + x, gameObject->transform.position.y + y);
            }
        }
    }
}