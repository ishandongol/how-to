#include"game.h"

void MAINMenu::events(SDL_Renderer *texture_renderer, buttons howtoBut, buttons help, buttons options,
	buttons credits, buttons quit, buttons here, MAINMenu howto_back,
	MAINMenu howto_logo, MAINMenu hamro_logo, int*p, float frameTime, int prevTime, int currentTime, float deltaTime, float frameTime2, MAINMenu *clouds, MAINMenu *bird, bool *top, MAINMenu *point){
	while (main_event){
		prevTime = currentTime;
		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - prevTime) / 1000.0f;
		frameTime += deltaTime;
		frameTime2 += deltaTime;
		if (frameTime >= 0.02f){
			frameTime = 0;
			clouds->destination.x -= 1;




			if (clouds->destination.x == -(clouds->destination.w)){
				clouds->destination.x = 1200;



			}



		}
		else if (frameTime2 >= 0.095f){
			frameTime2 = 0;
			if (user_knows == false){
				point->source.x += 38;
				if (point->source.x == 76 + 38){
					point->source.x = 0;
				}
			}

			bird->source.x += bird->source.w;
			if (bird->destination.y == 0){
				*top = true;

			}
			else if (bird->destination.y == 675){
				*top = false;
			}
			if (*top){
				bird->destination.y += 5;
			}
			else{
				bird->destination.y -= 5;
			}


			if (bird->source.x >= 1160){
				bird->source.x = 0;


			}

		}

		SDL_RenderClear(texture_renderer);

		howto_back.render(texture_renderer);
		if (user_knows == false){
			point->render(texture_renderer);
		}

		howto_logo.render(texture_renderer);
		hamro_logo.render(texture_renderer);
		howtoBut.render(texture_renderer);
		help.render(texture_renderer);
		options.render(texture_renderer);
		credits.render(texture_renderer);
		quit.render(texture_renderer);
		clouds->render(texture_renderer);
		bird->render(texture_renderer);
		SDL_RenderPresent(texture_renderer);

		while (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				main_event = false;
				*p = 5;

			}
			else if (event.type == SDL_KEYDOWN){
				switch (event.key.keysym.sym){
				case SDLK_ESCAPE:
					main_event = false;
					*p = 5;
					break;
				case SDLK_F1:
					main_event = false;
					break;
				}
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN){


				if (howtoBut.texture == NULL){
					cout << "Null" << endl;
				}
				if (event.button.button == SDL_BUTTON_LEFT){
					SDL_RenderClear(texture_renderer);

					howto_back.render(texture_renderer);
					here.render(texture_renderer);
					howto_logo.render(texture_renderer);
					hamro_logo.render(texture_renderer);
					howtoBut.render(texture_renderer);
					help.render(texture_renderer);
					options.render(texture_renderer);
					credits.render(texture_renderer);
					quit.render(texture_renderer);
					clouds->render(texture_renderer);
					SDL_RenderPresent(texture_renderer);
					if (event.button.x > howtoBut.destination.x && event.button.x < howtoBut.destination.x + howtoBut.destination.w &&
						event.button.y > howtoBut.destination.y && event.button.y < howtoBut.destination.y + howtoBut.destination.h){
						temp_x = howtoBut.destination.x;
						temp_y = howtoBut.destination.y;
						point->destination.x = 759;
						point->destination.y = 450;
						//cout<<"pressed"<<endl;
						main_event = false;
						drag_run = true;
						howto = true;
					}
					else if (event.button.x > help.destination.x && event.button.x < help.destination.x + help.destination.w&&
						event.button.y > help.destination.y && event.button.y < help.destination.y + help.destination.h){
						temp_x = help.destination.x;
						temp_y = help.destination.y;

						main_event = false;
						drag_run = true;
						help_run = true;
					}
					else if (event.button.x > options.destination.x && event.button.x < options.destination.x + options.destination.w&&
						event.button.y > options.destination.y && event.button.y < options.destination.y + options.destination.h){

						temp_x = options.destination.x;
						temp_y = options.destination.y;
						main_event = false;
						drag_run = true;
						options_run = true;
					}
					else if (event.button.x > credits.destination.x && event.button.x < credits.destination.x + credits.destination.w&&
						event.button.y > credits.destination.y && event.button.y < credits.destination.y + credits.destination.h){

						temp_x = credits.destination.x;
						temp_y = credits.destination.y;
						main_event = false;
						drag_run = true;
						credits_run = true;
					}
					else if (event.button.x > quit.destination.x && event.button.x < quit.destination.x + quit.destination.w&&
						event.button.y > quit.destination.y && event.button.y < quit.destination.y + quit.destination.h){

						temp_x = quit.destination.x;
						temp_y = quit.destination.y;
						main_event = false;
						drag_run = true;
						quit_run = true;
					}

				}


			}

		}

		SDL_Delay(10);
	}



}
void MAINMenu::event_drag(SDL_Renderer *texture_renderer, buttons howtoBut, buttons help, buttons options, buttons credits, buttons quit, MAINMenu howto_back, MAINMenu howto_logo, MAINMenu hamro_logo, int*p
	, float frameTime, int prevTime, int currentTime, float deltaTime, float frameTime2, MAINMenu *clouds, MAINMenu *bird, bool *top, MAINMenu *point){
	while (drag_run){
		cout << *top << endl;
		prevTime = currentTime;
		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - prevTime) / 1000.0f;
		frameTime += deltaTime;
		frameTime2 += deltaTime;
		if (frameTime >= 0.02f){
			frameTime = 0;
			clouds->destination.x -= 1;
			if (clouds->destination.x == -(clouds->destination.w)){
				clouds->destination.x = 1200;
			}
			else if (frameTime2 >= 0.095f){
				frameTime2 = 0;
				if (user_knows == false){
					point->source.x += 38;
					if (point->source.x == 76 + 38){
						point->source.x = 0;
					}
				}

				bird->source.x += bird->source.w;

				if (bird->destination.y == 0){
					*top = true;


				}
				else if (bird->destination.y == 675){
					*top = false;
				}
				if (*top){
					bird->destination.y += 5;
					cout << "top" << endl;
				}
				else {
					bird->destination.y -= 5;
					cout << "down" << endl;
				}


				if (bird->source.x >= 1160){
					bird->source.x = 0;


				}

			}
			SDL_RenderClear(texture_renderer);

			howto_back.render(texture_renderer);
			if (user_knows == false){
				point->render(texture_renderer);
			}

			howto_logo.render(texture_renderer);
			hamro_logo.render(texture_renderer);
			howtoBut.render(texture_renderer);
			help.render(texture_renderer);
			options.render(texture_renderer);
			credits.render(texture_renderer);
			quit.render(texture_renderer);
			clouds->render(texture_renderer);
			bird->render(texture_renderer);
			SDL_RenderPresent(texture_renderer);
		}

		while (SDL_PollEvent(&event)){
			if (event.type == SDL_MOUSEMOTION){


				if (howto){
					howtoBut.update(event.button.x, event.button.y);
				}
				else if (help_run){
					help.update(event.button.x, event.button.y);
				}
				else if (options_run){
					options.update(event.button.x, event.button.y);
				}
				else if (credits_run){
					credits.update(event.button.x, event.button.y);
				}
				else if (quit_run){
					quit.update(event.button.x, event.button.y);
				}
				if (howto || help_run || options_run || credits_run || quit_run){
					SDL_RenderClear(texture_renderer);
					howto_back.render(texture_renderer);
					howto_logo.render(texture_renderer);
					hamro_logo.render(texture_renderer);
					howtoBut.render(texture_renderer);
					help.render(texture_renderer);
					options.render(texture_renderer);
					credits.render(texture_renderer);
					quit.render(texture_renderer);
					clouds->render(texture_renderer);
					bird->render(texture_renderer);
					SDL_RenderPresent(texture_renderer);

				}

			}
			else if (event.type == SDL_MOUSEBUTTONUP){
				point->destination.x = 954 + 70;
				point->destination.y = 400 - 30;
				if (event.button.x > 659 + 40 && event.button.x < 659 + 263 - 40 &&
					event.button.y>427 + 40 && event.button.y < 427 + 646 - 40){
					// cout<<"yes"<<endl;
					if (howto){
						user_knows = true;
						drag_run = false;
						*p = 1;
					}
					if (help_run){
						drag_run = false;
						*p = 2;
					}
					if (options_run){
						drag_run = false;
						*p = 3;
					}
					if (credits_run){
						drag_run = false;
						*p = 4;
					}
					if (quit_run){
						drag_run = false;
						*p = 5;
					}


				}
				if (howto)
                    {
					//howtoBut.update(2,event.button.x,event.button.y,temp_x,temp_y);


					drag_run = false;
					main_event = true;
					howto = false;


				}
				else if (help_run)
                    {
					// help.update(2,event.button.x,event.button.y,temp_x,temp_y);


					drag_run = false;
					main_event = true;
					help_run = false;


				}
				else if (options_run)
                    {
					//options.update(2,event.button.x,event.button.y,temp_x,temp_y);


					drag_run = false;
					main_event = true;
					options_run = false;

				}
				else if (credits_run){
					//credits.update(2,event.button.x,event.button.y,temp_x,temp_y);


					drag_run = false;
					main_event = true;
					credits_run = false;

				}
				else if (quit_run){
					// quit.update(2,event.button.x,event.button.y,temp_x,temp_y);


					drag_run = false;
					main_event = true;
					quit_run = false;

				}


			}

		}
		SDL_Delay(10);
	}

}
