#include"game.h"

void MAINMenu::load(SDL_Renderer *texture_renderer, const char* url, int x, int y){

	int flags = IMG_INIT_JPG | IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	if ((initted&flags) != flags) {
		//prints error in command if failed to initialize
		cout << "IMG_Init: Failed to init required jpg and png support!" << IMG_GetError() << endl;
	}

	//just to check if the code runs... before writing this there was error
	// cout<<"chalyo"<<endl;
	//this loads the image and stores to surface

	surface = IMG_Load(url);
	//this creates a texture from the loaded image see above... the "surface"
	texture = SDL_CreateTextureFromSurface(texture_renderer, surface);
	if (texture == NULL){
		cout << "Cannot load :: " << url << endl;

	}
	//this frees up the surface... because it is not necessary now
	SDL_FreeSurface(surface);
	//this is used to know the height and width of the loaded texture
	SDL_QueryTexture(texture, NULL, NULL, &source.w, &source.h);
	//this is written to to give the x and y coordinate of the source and destination rectangle and also the destination width and height
	//ps we render everything in the rectangle like we did in drawing class the printing .. we used view port ... imagine the rectangles as viewport

	destination.x = x;
	source.x = 0;
	destination.y = y;
	source.y = 0;
	destination.w = source.w;
	destination.h = source.h;




}

void buttons::load(SDL_Renderer *texture_renderer, const char*text, int x, int y, TTF_Font *font, TTF_Font *outline, SDL_Color color, SDL_Color color2){
	surface = TTF_RenderText_Blended(font, text, color);
	texture = SDL_CreateTextureFromSurface(texture_renderer, surface);
	SDL_FreeSurface(surface);
	SDL_QueryTexture(texture, NULL, NULL, &source.w, &source.h);
	destination.x = x;
	destination.y = y;
	destination.w = source.w;
	destination.h = source.h;

	//outline

	surface = TTF_RenderText_Blended(outline, text, color2);
	outline_texture = SDL_CreateTextureFromSurface(texture_renderer, surface);
	SDL_FreeSurface(surface);
	SDL_QueryTexture(outline_texture, NULL, NULL, &outline_source.w, &outline_source.h);
	outline_destination.x = x - 2;
	outline_destination.y = y - 2;
	outline_destination.w = outline_source.w;
	outline_destination.h = outline_source.h;

}
void buttons::load_no_outline(SDL_Renderer *texture_renderer, const char* text, int x, int y, TTF_Font* font, SDL_Color color){
	surface = TTF_RenderText_Blended(font, text, color);
	texture = SDL_CreateTextureFromSurface(texture_renderer, surface);
	SDL_FreeSurface(surface);
	SDL_QueryTexture(texture, NULL, NULL, &source.w, &source.h);
	destination.x = x;
	destination.y = y;
	destination.w = source.w;
	destination.h = source.h;

}



