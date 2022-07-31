#include"crimp.h"

void crimp :: render_media(SDL_Renderer * texture_renderer)
{

    SDL_RenderCopy( texture_renderer, texture, &source, &destination );
}

