#include "Header.h"

void obj::rendering(SDL_Renderer* texture_renderer)
{
	SDL_RenderCopy(texture_renderer, texture1, &source, &dest);
}
