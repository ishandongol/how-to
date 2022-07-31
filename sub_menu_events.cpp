#include "game.h"


void subMENU1::events(buttons tea, buttons crimp, buttons comp, buttons stretcher, int *p){
	while (sub_event){

		while (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				sub_event = false;
				*p = 5;

			}
			else if (event.type == SDL_KEYDOWN){
				switch (event.key.keysym.sym){
				case SDLK_ESCAPE:
					sub_event = false;
					main_event = true;
					*p = 0;

					break;
				}
			}
			else if (event.type == SDL_MOUSEBUTTONUP){
				if (event.button.x > tea.destination.x && event.button.x<tea.destination.x + tea.destination.w &&
					event.button.y>tea.destination.y && event.button.y < tea.destination.y + tea.destination.h){
					// cout<<"make tea"<<endl;
					*p = 6;
					sub_event = false;

				}
				else if (event.button.x > crimp.destination.x && event.button.x<crimp.destination.x + tea.destination.w &&
					event.button.y>crimp.destination.y && event.button.y < crimp.destination.y + crimp.destination.h){
					// cout<<"crimp"<<endl;
					*p = 7;
					sub_event = false;

				}
				else if (event.button.x > comp.destination.x && event.button.x<comp.destination.x + comp.destination.w &&
					event.button.y>comp.destination.y && event.button.y < comp.destination.y + comp.destination.h){
					//cout<<"computer"<<endl;
					*p = 8;
					sub_event = false;

				}
				else if (event.button.x > stretcher.destination.x && event.button.x<stretcher.destination.x + stretcher.destination.w &&
					event.button.y>stretcher.destination.y && event.button.y < stretcher.destination.y + stretcher.destination.h){
					//cout<<"stretcher"<<endl;
					*p = 9;
					sub_event = false;

				}

			}
		}
		SDL_Delay(50);
	}

}

void subMENU2::events(int *p){
	while (sub_event){
		//cout<<"help event running"<<endl;
		while (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				sub_event = false;
				*p = 5;

			}
			else if (event.type == SDL_KEYDOWN){
				switch (event.key.keysym.sym){
				case SDLK_ESCAPE:
					sub_event = false;
					main_event = true;
					*p = 0;

					break;
				}
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN){

			}
		}
		SDL_Delay(50);
	}

}


void subMENU3::events(int *p, buttons options1, buttons options2){
	//cout<<"options event running"<<endl;
	while (sub_event){
		while (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				sub_event = false;
				*p = 5;

			}
			else if (event.type == SDL_KEYDOWN){
				switch (event.key.keysym.sym){
				case SDLK_ESCAPE:
					sub_event = false;
					main_event = true;
					*p = 0;

					break;
				}
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN){
				if (event.button.x > options1.destination.x && event.button.x<options1.destination.x + options1.destination.w
					&& event.button.y>options1.destination.y && event.button.y < options1.destination.y + options1.destination.h){
					//cout<<"SOUNDS"<<endl;
					temp_x = options1.destination.x;
					temp_y = options1.destination.y;
					sub_event = false;
					sub_drag = true;
					opt = 1;

				}
				else if (event.button.x > options2.destination.x && event.button.x<options2.destination.x + options2.destination.w
					&& event.button.y>options2.destination.y && event.button.y < options2.destination.y + options2.destination.h){
					// cout<<"music"<<endl;
					temp_x = options2.destination.x;
					temp_y = options2.destination.y;
					sub_event = false;
					sub_drag = true;
					opt = 2;
				}
			}
		}
		SDL_Delay(50);
	}

}

void subMENU3::drag_event(SDL_Renderer *texture_renderer, buttons *options1, buttons *options2, bool *sound, bool *music, MAINMenu howtoMENU, buttons optionsMENU_text,
	buttons MENU_text_foot, buttons options_options3, buttons options_options4, subMENU3 bubble, subMENU3 bubble2){
	while (sub_drag){

		while (SDL_PollEvent(&event)){
			if (event.type == SDL_MOUSEMOTION){

				if (opt == 1){
					options1->update(event.button.x, event.button.y);
				}
				else if (opt == 2){
					options2->update(event.button.x, event.button.y);

				}
				// cout<<""<<endl;

			}
			else if (event.type == SDL_MOUSEBUTTONUP){
				if (event.button.x > bubble.destination.x + 20 && event.button.x<bubble.destination.x + bubble.destination.w - 20
					&& event.button.y>bubble.destination.y + 20 && event.button.y < bubble.destination.y + bubble.destination.h - 20){

					if (opt == 1){
						// cout<<"yes sounds"<<endl;
						*sound = true;
						sub_drag = false;
						sub_event = true;
						Mix_Resume(-1);


					}
					else if (opt == 2){
						//cout<<"music"<<endl;
						*music = true;
						sub_drag = false;
						sub_event = true;


					}


				}
				else if (event.button.x > bubble2.destination.x + 20 && event.button.x<bubble2.destination.x + bubble2.destination.w - 20
					&& event.button.y>bubble2.destination.y + 20 && event.button.y < bubble2.destination.y + bubble2.destination.h - 20){
					if (opt == 1){
						//cout<<"yes sounds"<<endl;
						*sound = false;
						sub_drag = false;
						sub_event = true;
						Mix_Pause(-1);

					}
					else if (opt == 2){
						//cout<<"music"<<endl;
						*music = false;
						sub_drag = false;
						sub_event = true;

					}

				}
				else{
					if (opt == 1){
						options1->destination.x = temp_x;
						options1->destination.y = temp_y;
						sub_drag = false;
						sub_event = true;

					}
					else if (opt == 2){
						options2->destination.x = temp_x;
						options2->destination.y = temp_y;
						sub_drag = false;
						sub_event = true;

					}


				}


			}

		}
		SDL_Delay(10);

		if (opt == 1 || opt == 2){
			//cout <<"running"<<endl;
			SDL_RenderClear(texture_renderer);
			howtoMENU.render(texture_renderer);
			bubble.render(texture_renderer);
			bubble2.render(texture_renderer);
			optionsMENU_text.render(texture_renderer);
			MENU_text_foot.render(texture_renderer);
			options1->render(texture_renderer);
			options2->render(texture_renderer);
			options_options3.render(texture_renderer);
			options_options4.render(texture_renderer);
			SDL_RenderPresent(texture_renderer);

		}

	}

}

void subMENU4::events(int *p){
	// cout<<"credits event running"<<endl;
	while (sub_event){
		while (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				sub_event = false;
				*p = 5;

			}
			else if (event.type == SDL_KEYDOWN){
				switch (event.key.keysym.sym){
				case SDLK_ESCAPE:
					sub_event = false;
					main_event = true;
					*p = 0;

					break;
				}
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN){

			}
		}
		SDL_Delay(50);
	}

}

void subMENU5::events(int *p, bool *game_run, buttons quitMENU_YES, buttons quitMENU_NO){
	// cout<<"quit event running"<<endl;
	while (sub_event){
		while (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				sub_event = false;
				*p = 5;

			}
			else if (event.type == SDL_KEYDOWN){

				switch (event.key.keysym.sym){
				case SDLK_ESCAPE:
					sub_event = false;
					main_event = true;
					*p = 0;

					break;
				case SDLK_RETURN:
					sub_event = false;
					main_event = false;
					*game_run = false;

					break;
				}
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN){
				if (event.button.button == SDL_BUTTON_LEFT){
					if (event.button.x > quitMENU_YES.destination.x && event.button.x<quitMENU_YES.destination.x + quitMENU_YES.destination.w &&
						event.button.y>quitMENU_YES.destination.y && event.button.y < quitMENU_YES.destination.y + quitMENU_YES.destination.h){
						sub_event = false;
						main_event = false;
						*game_run = false;


					}
					else if (event.button.x > quitMENU_NO.destination.x && event.button.x<quitMENU_NO.destination.x + quitMENU_NO.destination.w &&
						event.button.y>quitMENU_NO.destination.y && event.button.y < quitMENU_NO.destination.y + quitMENU_NO.destination.h){

						sub_event = false;
						main_event = true;
						*p = 0;

					}
				}
			}
		}
		SDL_Delay(50);
	}

}
void subMENU5::events2(int *p, bool *game_run, buttons quitMENU_YES, buttons quitMENU_NO, int *temp){
	// cout<<"quit event running"<<endl;
	while (sub_event){
		while (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				sub_event = false;
				*p = 10;

			}
			else if (event.type == SDL_KEYDOWN){

				switch (event.key.keysym.sym){
				case SDLK_ESCAPE:
					sub_event = false;
					main_event = true;
					*p = 1;

					break;
				case SDLK_RETURN:
					sub_event = false;
					main_event = false;
					*game_run = false;

					break;
				}
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN){
				if (event.button.button == SDL_BUTTON_LEFT){
					if (event.button.x > quitMENU_YES.destination.x && event.button.x<quitMENU_YES.destination.x + quitMENU_YES.destination.w &&
						event.button.y>quitMENU_YES.destination.y && event.button.y < quitMENU_YES.destination.y + quitMENU_YES.destination.h){

						sub_event = false;
						main_event = true;
						*p = 1;



					}
					else if (event.button.x > quitMENU_NO.destination.x && event.button.x<quitMENU_NO.destination.x + quitMENU_NO.destination.w &&
						event.button.y>quitMENU_NO.destination.y && event.button.y < quitMENU_NO.destination.y + quitMENU_NO.destination.h){

						sub_event = false;
						main_event = true;
						cout << "value of temp in sub menu" << *temp << endl;
						*p = *temp;


					}
				}
			}
		}
		SDL_Delay(50);
	}

}

