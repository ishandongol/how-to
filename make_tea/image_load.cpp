#include "make_tea.h"


void level1 :: load_image(SDL_Renderer *texture_renderer, const char* url, int x, int y){
        surface=IMG_Load(url);
        texture=SDL_CreateTextureFromSurface(texture_renderer,surface);
        SDL_FreeSurface(surface);
        SDL_QueryTexture(texture,NULL,NULL ,&source.w,&source.h);
        destination.x=x;
        destination.y=y;
        destination.w=source.w;
        destination.h=source.h;




 }
