#include "Header.h"
void obj::load_texture(SDL_Renderer *renderTarget, const char* path, int x, int y)
{
	surface = IMG_Load(path);

	texture1=SDL_CreateTextureFromSurface(renderTarget,surface);
	if(texture1==NULL){
        cout<<"nullllllllllllllll"<<path<<SDL_GetError()<<endl;
	}
	SDL_FreeSurface(surface);
	SDL_QueryTexture(texture1, NULL, NULL, &source.w, &source.h);
	dest.x = x;
	source.x=0;
	dest.y = y;
	source.y=0;
	dest.h = source.h;
	dest.w = source.w;

}
