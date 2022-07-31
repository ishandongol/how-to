#include"Header.h"
using namespace std;
SDL_Window* window = NULL;
SDL_Renderer* renderTarget = NULL;
obj background, lan, mon, pwr, mou, key, power, vga, usb_m, usb_k, lanu, ab, backs, sprt;
bool main_game = true;

int win()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
	if (imgFlags != IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG))
		cout << "Error!!" << IMG_GetError() << endl;
	window = SDL_CreateWindow("Computer Setup", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 675, SDL_WINDOW_SHOWN);
	renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	return 0;
}

int main(int argc, char* argv[])
{
	win();
	background.load_texture(renderTarget, "update_cpu.jpg", 70, 35);
	mou.load_texture(renderTarget, "usb.png", 640, 210);
	mon.load_texture(renderTarget, "tat_of_vga.png", 800, 400);
	pwr.load_texture(renderTarget, "tar_of_power.png", 830, 35);
	key.load_texture(renderTarget, "usb.png", 640, 300);
	lan.load_texture(renderTarget, "lan.png", 610, 580);
	usb_m.load_texture(renderTarget, "tar_usb.png", 93, 320);
	vga.load_texture(renderTarget, "vga_ko_tar.png", 118, 265);
	power.load_texture(renderTarget, "tar-vga.png", 125, 152);
	usb_k.load_texture(renderTarget, "tar_usb.png", 93, 355);
	lanu.load_texture(renderTarget, "lan_ko_tar.png", 155, 262);
	backs.load_texture(renderTarget, "welcome.png", 0, 0);
	sprt.load_texture(renderTarget, "crimp_fix.png", 0, 0);
	sprt.dest.w = sprt.source.w / 4;
	sprt.source.w = sprt.source.w / 4;

	SDL_SetRenderDrawColor(renderTarget, 252, 231, 0, 0);
	SDL_RenderClear(renderTarget);
	backs.rendering(renderTarget);
	/*mou.rendering(renderTarget);
	mon.rendering(renderTarget);
	pwr.rendering(renderTarget);
	key.rendering(renderTarget);
	lan.rendering(renderTarget);
	*/
	SDL_RenderPresent(renderTarget);

	while (comp_game)
	{
		ab.click_check(&comp_game, mou, mon, pwr, key, lan, backs, bkgrnd,sprt, renderTarget );
		ab.drag_event(&comp_game, &mou, &mon, &pwr, &key, &lan, &bkgrnd, &usb_m, &vga, &power, &usb_k, &lanu, renderTarget);
	}
	return 0;
}
