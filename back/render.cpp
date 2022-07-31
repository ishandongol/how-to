#include"game.h"

void MAINMenu :: render(SDL_Renderer *texture_renderer){
    SDL_RenderCopy(texture_renderer, texture, &source,  &destination);

}
void buttons :: render(SDL_Renderer *texture_renderer){
    SDL_RenderCopy(texture_renderer, outline_texture, NULL,  &destination);
    SDL_RenderCopy(texture_renderer, texture, NULL,  &destination);

}
void buttons :: render_no_outline(SDL_Renderer *texture_renderer){
    SDL_RenderCopy(texture_renderer, texture, NULL,  &destination);
}

