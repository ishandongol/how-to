#include "Header.h"

void obj::click_check(bool* main_game,obj text, obj last, obj mou, obj mon, obj pwr, obj key, obj lan, obj backs, obj background,obj sprt, SDL_Renderer* texture_renderer,int*p, int *temp_p)
{
    *temp_p=*p;
	while (click)
	{
		if (sprite)
		{

            SDL_RenderClear(texture_renderer);
            last.rendering(texture_renderer);
            text.rendering(texture_renderer);
            SDL_RenderPresent(texture_renderer);

		}
		while (SDL_PollEvent(&ev) != 0)
		{
			if (ev.type == SDL_QUIT)
			{
				click=false;
                *main_game=false;
                *p=10;
			}
			else if (ev.type == SDL_KEYDOWN)

			{
			    switch (ev.key.keysym.sym)
                                {
                                case SDLK_ESCAPE:
                                    click=false;
                *main_game=false;
                *p=10;
                                    break;
                                }
				if (ev.key.keysym.sym == SDLK_SPACE)
				{
					SDL_RenderClear(texture_renderer);
					background.rendering(texture_renderer);
					mou.rendering(texture_renderer);
					mon.rendering(texture_renderer);
					pwr.rendering(texture_renderer);
					key.rendering(texture_renderer);
					lan.rendering(texture_renderer);
					SDL_RenderPresent(texture_renderer);
				}
			}
			else if (ev.type == SDL_MOUSEBUTTONDOWN)
			{
				if (ev.button.button == SDL_BUTTON_LEFT)
				{
					if (ev.button.x > mou.dest.x && ev.button.x < mou.dest.x + mou.dest.w && ev.button.y > mou.dest.y && ev.button.y < mou.dest.y + mou.dest.h)
					{
						cout << "Running" << endl;
						drag_drop = true;
						click = false;
						*main_game = true;
						temp = 1;
					}
					else if (ev.button.x > mon.dest.x && ev.button.x < mon.dest.x + mon.dest.w && ev.button.y > mon.dest.y && ev.button.y < mon.dest.y + mon.dest.h)
					{
						drag_drop = true;
						click = false;
						*main_game = true;
						temp = 2;
					}
					else if (ev.button.x > pwr.dest.x && ev.button.x < pwr.dest.x + pwr.dest.w && ev.button.y > pwr.dest.y && ev.button.y < pwr.dest.y + pwr.dest.h)
					{
						cout << "Running" << endl;
						drag_drop = true;
						click = false;
						*main_game = true;
						temp = 3;
					}
					else if (ev.button.x > key.dest.x && ev.button.x < key.dest.x + key.dest.w && ev.button.y > key.dest.y && ev.button.y < key.dest.y + key.dest.h)
					{
						drag_drop = true;
						click = false;
						*main_game = true;
						temp = 4;
					}
					else if (ev.button.x > lan.dest.x && ev.button.x < lan.dest.x + lan.dest.w && ev.button.y > lan.dest.y && ev.button.y < lan.dest.y + lan.dest.h)
					{
						drag_drop = true;
						click = false;
						*main_game = true;
						temp = 5;
					}
				}
			}
		}
	}
}
void obj::drag_event(bool* main_game, obj* mou, obj* mon, obj* pwr, obj* key, obj* lan, obj* background, obj* usb_m, obj* vga, obj* power, obj* usb_k, obj* lanu, SDL_Renderer* texture_renderer)
{
	while (drag_drop)
	{
		while (SDL_PollEvent(&ev) != 0)
		{
			cout << ev.button.x << "," << ev.button.y << endl;
			background->rendering(texture_renderer);
			if (ev.type == SDL_MOUSEMOTION)
			{
				if (temp == 1)
				{
					if (chk[1] != 1)
					{
						mou->update(ev.button.x, ev.button.y);
						SDL_RenderClear(texture_renderer);
						background->rendering(texture_renderer);
						if (chk[1] == 1)
							usb_m->rendering(texture_renderer);
						if (chk[1] != 1)
							mou->rendering(texture_renderer);
						if (chk[2] == 2)
							vga->rendering(texture_renderer);
						if (chk[2] != 2)
							mon->rendering(texture_renderer);
						if (chk[3] == 3)
							power->rendering(texture_renderer);
						if (chk[3] != 3)
							pwr->rendering(texture_renderer);
						if (chk[4] == 4)
							usb_k->rendering(texture_renderer);
						if (chk[4] != 4)
							key->rendering(texture_renderer);
						if (chk[5] == 5)
							lanu->rendering(texture_renderer);
						if (chk[5] != 5)
							lan->rendering(texture_renderer);
						SDL_RenderPresent(texture_renderer);
					}
				}
				else if (temp == 2)
				{

					if (chk[2] != 2)
					{
						mon->update(ev.button.x, ev.button.y);
						SDL_RenderClear(texture_renderer);
						background->rendering(texture_renderer);
						if (chk[1] == 1)
							usb_m->rendering(texture_renderer);
						if (chk[1] != 1)
							mou->rendering(texture_renderer);
						if (chk[2] == 2)
							vga->rendering(texture_renderer);
						if (chk[2] != 2)
							mon->rendering(texture_renderer);
						if (chk[3] == 3)
							power->rendering(texture_renderer);
						if (chk[3] != 3)
							pwr->rendering(texture_renderer);
						if (chk[4] == 4)
							usb_k->rendering(texture_renderer);
						if (chk[4] != 4)
							key->rendering(texture_renderer);
						if (chk[5] == 5)
							lanu->rendering(texture_renderer);
						if (chk[5] != 5)
							lan->rendering(texture_renderer);
						SDL_RenderPresent(texture_renderer);
					}
				}
				else if (temp == 3)
				{

					if (chk[3] != 3)
					{
						pwr->update(ev.button.x, ev.button.y);
						SDL_RenderClear(texture_renderer);
						background->rendering(texture_renderer);
						if (chk[1] == 1)
							usb_m->rendering(texture_renderer);
						if (chk[1] != 1)
							mou->rendering(texture_renderer);
						if (chk[2] == 2)
							vga->rendering(texture_renderer);
						if (chk[2] != 2)
							mon->rendering(texture_renderer);
						if (chk[3] == 3)
							power->rendering(texture_renderer);
						if (chk[3] != 3)
							pwr->rendering(texture_renderer);
						if (chk[4] == 4)
							usb_k->rendering(texture_renderer);
						if (chk[4] != 4)
							key->rendering(texture_renderer);
						if (chk[5] == 5)
							lanu->rendering(texture_renderer);
						if (chk[5] != 5)
							lan->rendering(texture_renderer);
						SDL_RenderPresent(texture_renderer);
					}
				}
				else if (temp == 4)
				{

					if (chk[4] != 4)
					{
						key->update(ev.button.x, ev.button.y);
						SDL_RenderClear(texture_renderer);
						background->rendering(texture_renderer);
						if (chk[1] == 1)
							usb_m->rendering(texture_renderer);
						if (chk[1] != 1)
							mou->rendering(texture_renderer);
						if (chk[2] == 2)
							vga->rendering(texture_renderer);
						if (chk[2] != 2)
							mon->rendering(texture_renderer);
						if (chk[3] == 3)
							power->rendering(texture_renderer);
						if (chk[3] != 3)
							pwr->rendering(texture_renderer);
						if (chk[4] == 4)
							usb_k->rendering(texture_renderer);
						if (chk[4] != 4)
							key->rendering(texture_renderer);
						if (chk[5] == 5)
							lanu->rendering(texture_renderer);
						if (chk[5] != 5)
							lan->rendering(texture_renderer);
						SDL_RenderPresent(texture_renderer);
					}
				}
				else if (temp == 5)
				{

					if (chk[5] != 5)
					{
						lan->update(ev.button.x, ev.button.y);
						SDL_RenderClear(texture_renderer);
						background->rendering(texture_renderer);
						if (chk[1] == 1)
							usb_m->rendering(texture_renderer);
						if (chk[1] != 1)
							mou->rendering(texture_renderer);
						if (chk[2] == 2)
							vga->rendering(texture_renderer);
						if (chk[2] != 2)
							mon->rendering(texture_renderer);
						if (chk[3] == 3)
							power->rendering(texture_renderer);
						if (chk[3] != 3)
							pwr->rendering(texture_renderer);
						if (chk[4] == 4)
							usb_k->rendering(texture_renderer);
						if (chk[4] != 4)
							key->rendering(texture_renderer);
						if (chk[5] == 5)
							lanu->rendering(texture_renderer);
						if (chk[5] != 5)
							lan->rendering(texture_renderer);
						SDL_RenderPresent(texture_renderer);
					}
				}
			}
			else if (ev.type == SDL_MOUSEBUTTONUP)
			{
				drag_drop = false;
				click = true;

				if (ev.button.x > 116 && ev.button.x < 116 + 50 && ev.button.y > 329 && ev.button.y < 329 + 60 && temp == 1)
				{
					chk[1] = 1;
					mou->update(122, 342);
					SDL_RenderClear(texture_renderer);
					background->rendering(texture_renderer);
					if (chk[1] == 1)
					usb_m->rendering(texture_renderer);
					if (chk[1] != 1)
					mou->rendering(texture_renderer);
					if (chk[2] == 2)
					vga->rendering(texture_renderer);
					if (chk[2] != 2)
					mon->rendering(texture_renderer);
					if (chk[3] == 3)
					power->rendering(texture_renderer);
					if (chk[3] != 3)
					pwr->rendering(texture_renderer);
					if (chk[4] == 4)
					usb_k->rendering(texture_renderer);
					if (chk[4] != 4)
					key->rendering(texture_renderer);
					if (chk[5] == 5)
					lanu->rendering(texture_renderer);
					if (chk[5] != 5)
					lan->rendering(texture_renderer);
					SDL_RenderPresent(texture_renderer);
				}
				else if (ev.button.x > 118 && ev.button.x < 118 + 19 && ev.button.y > 267 && ev.button.y < 267 + 54 && temp == 2)
				{
					chk[2] = 2;
					mon->update(132, 291);
					SDL_RenderClear(texture_renderer);
					background->rendering(texture_renderer);
					if (chk[1] == 1)
					usb_m->rendering(texture_renderer);
					if (chk[1] != 1)
					mou->rendering(texture_renderer);
					if (chk[2] == 2)
					vga->rendering(texture_renderer);
					if (chk[2] != 2)
					mon->rendering(texture_renderer);
					if (chk[3] == 3)
					power->rendering(texture_renderer);
					if (chk[3] != 3)
					pwr->rendering(texture_renderer);
					if (chk[4] == 4)
					usb_k->rendering(texture_renderer);
					if (chk[4] != 4)
					key->rendering(texture_renderer);
					if (chk[5] == 5)
					lanu->rendering(texture_renderer);
					if (chk[5] != 5)
					lan->rendering(texture_renderer);
					SDL_RenderPresent(texture_renderer);
				}

			else if (ev.button.x > 125 && ev.button.x < 125 + 65 && ev.button.y > 156 && ev.button.y < 156 + 44 && temp == 3)
				{
					chk[3] = 3;
					pwr->update(156, 176);
					SDL_RenderClear(texture_renderer);
					background->rendering(texture_renderer);
					if (chk[1] == 1)
					usb_m->rendering(texture_renderer);
					if (chk[1] != 1)
					mou->rendering(texture_renderer);
					if (chk[2] == 2)
					vga->rendering(texture_renderer);
					if (chk[2] != 2)
					mon->rendering(texture_renderer);
					if (chk[3] == 3)
					power->rendering(texture_renderer);
					if (chk[3] != 3)
					pwr->rendering(texture_renderer);
					if (chk[4] == 4)
					usb_k->rendering(texture_renderer);
					if (chk[4] != 4)
					key->rendering(texture_renderer);
					if (chk[5] == 5)
					lanu->rendering(texture_renderer);
					if (chk[5] != 5)
					lan->rendering(texture_renderer);
					SDL_RenderPresent(texture_renderer);
				}

				else if (ev.button.x > 116 && ev.button.x < 116 + 45 && ev.button.y > 359 && ev.button.y < 359 + 60 && temp == 4)
				{
					chk[4] = 4;
					key->update(123, 379);
					SDL_RenderClear(texture_renderer);
					background->rendering(texture_renderer);
					if (chk[1] == 1)
					usb_m->rendering(texture_renderer);
					if (chk[1] != 1)
					mou->rendering(texture_renderer);
					if (chk[2] == 2)
					vga->rendering(texture_renderer);
					if (chk[2] != 2)
					mon->rendering(texture_renderer);
					if (chk[3] == 3)
					power->rendering(texture_renderer);
					if (chk[3] != 3)
					pwr->rendering(texture_renderer);
					if (chk[4] == 4)
					usb_k->rendering(texture_renderer);
					if (chk[4] != 4)
					key->rendering(texture_renderer);
					if (chk[5] == 5)
					lanu->rendering(texture_renderer);
					if (chk[5] != 5)
					lan->rendering(texture_renderer);
					SDL_RenderPresent(texture_renderer);
				}

				else if (ev.button.x > 155 && ev.button.x < 155 + 21 && ev.button.y > 268 && ev.button.y < 268 + 21 && temp == 5)
				{
					chk[5] = 5;
					lan->update(165, 278);
					SDL_RenderClear(texture_renderer);
					background->rendering(texture_renderer);
					if (chk[1] == 1)
						usb_m->rendering(texture_renderer);
					if (chk[1] != 1)
						mou->rendering(texture_renderer);
					if (chk[2] == 2)
						vga->rendering(texture_renderer);
					if (chk[2] != 2)
						mon->rendering(texture_renderer);
					if (chk[3] == 3)
						power->rendering(texture_renderer);
					if (chk[3] != 3)
						pwr->rendering(texture_renderer);
					if (chk[4] == 4)
						usb_k->rendering(texture_renderer);
					if (chk[4] != 4)
						key->rendering(texture_renderer);
					if (chk[5] == 5)
						lanu->rendering(texture_renderer);
					if (chk[5] != 5)
						lan->rendering(texture_renderer);
					SDL_RenderPresent(texture_renderer);
					sprite = true;
					SDL_Delay(1500);
				}
				else
				{
					SDL_RenderClear(texture_renderer);
					background->rendering(texture_renderer);
					mou->update(880, 247);
					mou->rendering(texture_renderer);
					mon->update(923, 496);
					mon->rendering(texture_renderer);
					pwr->update(980, 122);
					pwr->rendering(texture_renderer);
					key->update(880, 337);
					key->rendering(texture_renderer);
					lan->update(864, 620);
					lan->rendering(texture_renderer);
					SDL_RenderPresent(texture_renderer);
				}
			}
		}
	}
}

