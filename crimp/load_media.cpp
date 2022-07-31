#include"crimp.h"

void crimp :: load_media(SDL_Renderer *texture_renderer, const char* url, int x, int y)
{

    surface = IMG_Load(url);
if(surface==NULL){
        cout<<url<<endl;

}
    texture = SDL_CreateTextureFromSurface(texture_renderer, surface);

    SDL_FreeSurface(surface);

    SDL_QueryTexture(texture, NULL, NULL, &source.w, &source.h);

    destination.x = x;
    source.x = 0;
    destination.y = y;
    source.y = 0;
    destination.w = source.w;
    destination.h = source.h;

    if(texture == NULL)
    {
        cout<<"Cannot Load"<<url<<endl;
    }

}

