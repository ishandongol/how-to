#include"game.h"


void MAINMenu::free_resources(){
	SDL_DestroyTexture(texture);
}

void buttons::free_resources(){
	SDL_DestroyTexture(texture);

}
