#include"game.h"
#include"crimp/crimp.h"
#include"make_tea/make_tea.h"
#include"setup_computer/Header.h"
int cou = 0;
int sub_page = 0;
int counter = 0;
int ma = 0;
int temp_p = 0;
int page = 0;

SDL_Event intros;
SDL_Window *window = NULL;
SDL_Renderer *texture_renderer = NULL;
int win_w = 1200;
int win_h = 675;
int help_x = 629;
int help_y = 257;
TTF_Font *upcli_150, *luna_29, *upcli_50, *luna_25, *nep_60, *outline_upcli_50, *outline_nep_60, *outline_luna_29;
SDL_Color cream, white, yellow, black;
MAINMenu howto_back, howto_logo, hamro_logo, introd, sub_menu, clouds, bird, sun, point;
subMENU1 howtoMENU, howtotea, howtocrimp;
subMENU2 helpMENU;
subMENU3 optionsMENU, bubble, bubble2;
subMENU4 creditsMENU;
subMENU5 quitMENU, quitMENU2;
buttons howtoBut, here, options, credits, help, quit, howtoMENU_text, MENU_text_foot, howtoMENU_option1, howtoMENU_option2, howtoMENU_option3, howtoMENU_option4;
buttons helpMENU_text, optionsMENU_text, creditsMENU_text, quitMENU_text, quitMENU_ask, quitMENU_YES, quitMENU_NO;
buttons beginning[7], options_options1, options_options2, options_options3, options_options4;
buttons RC, testbut1, testbut2;
sounds first, second;
MAINMenu event;
//computer
//obj bgrdn, lan, mon, pwr, mou, key, power, vga, usb_m, usb_k, lanu, ab, back1;

bool sounds_play = true;
bool music_play = true;
int temp_x = 0, temp_y = 0;
bool comp_game = true;
//crimper


crimp welcome, table, crimper, jack, utp, utp2, bar, bar_slider, loop, st_through, crossover, utp_big, msg, done, type1, type2, final_crimp;

bool next_table;
bool game = true;


level1 background, pot, milk, sugar, salt, water, gas, event_drag, g1,
leaves, sound1, waterdrop, milkdrop, sound2,
leavesdrop, soundleaves, image_done, help_text, help_pot, intro, fire, button1;
obj bkgrnd, lan2, mon, pwr, mou, key, power, vga, usb_m, usb_k, lanu, ab, backs, sprt,last, text;

bool main_game = true;
void init_font(){
	if (TTF_Init() == 0){
		upcli_150 = TTF_OpenFont("resources/font/upcli.ttf", 150);
		luna_29 = TTF_OpenFont("resources/font/luna.ttf", 29);
		upcli_50 = TTF_OpenFont("resources/font/upcli.ttf", 50);
		luna_25 = TTF_OpenFont("resources/font/luna.ttf", 25);
		nep_60 = TTF_OpenFont("resources/font/nep.ttf", 60);
		outline_upcli_50 = TTF_OpenFont("resources/font/upcli.ttf", 50);
		outline_nep_60 = TTF_OpenFont("resources/font/nep.ttf", 60);
		outline_luna_29 = TTF_OpenFont("resources/font/luna.ttf", 29);
		TTF_SetFontOutline(outline_upcli_50, 1);
		TTF_SetFontOutline(outline_nep_60, 1);
		TTF_SetFontOutline(outline_luna_29, 1);


	}
	else{
		cout << "cannot open font" << TTF_GetError() << endl;
	}
}

void load(){




	//mainmenu
	texture_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(texture_renderer, 6, 140, 179, 255);
	clouds.load(texture_renderer, "resources/images/test.png", 1000, 0);
	sun.load(texture_renderer, "resources/images/sun.png", 300, 300);

	bird.load(texture_renderer, "resources/images/bird.png", 400, 675);
	bird.destination.w = bird.source.w / 8;
	//bird.source.x+=160;
	//bird.destination.h=bird.source.h/3;
	bird.source.w = bird.source.w / 8;
	//bird.source.h=bird.source.h/3;
	howto_back.load(texture_renderer, "resources/images/b.jpg", 0, 0);
	introd.load(texture_renderer, "resources/images/hamro.png", 0, 0);
	introd.destination.x = win_w / 2 - introd.source.w / 2;
	introd.destination.x = -introd.destination.w;

	introd.destination.y = win_h / 2 - introd.source.h / 2;
	howto_logo.load(texture_renderer, "resources/images/log.png", 70, 70);
	hamro_logo.load(texture_renderer, "resources/images/portal.png", 985, 40);

	howtoMENU.load(texture_renderer, "resources/images/sub.jpg", 0, 0);
	howtotea.load(texture_renderer, "resources/images/tex.jpg", 0, 0);
	//gas.load(texture_renderer,"resources/images/tea/gas.png",200,500);
	howtocrimp.load(texture_renderer, "resources/images/crimp.jpg", 0, 0);
	howtoMENU_text.load(texture_renderer, "howto", 60, 60, nep_60, outline_nep_60, black, white);
	//MENU_text_foot.load(texture_renderer,"CODE-O-METRY",900, 600,upcli_50,outline_upcli_50,black, yellow);
	beginning[4].load_no_outline(texture_renderer, "CODE-O-METRY", win_w / 2, win_h / 2, upcli_150, white);
	beginning[4].destination.x = win_w / 2 - beginning[4].destination.w / 2;
	beginning[4].destination.y = win_h / 2 - beginning[4].destination.h / 2;
	//sub_menu.load(texture_renderer,"resources/images/b2.jpg",0,0);
	beginning[6].load_no_outline(texture_renderer, "JUST DRAG & DROP ON THE SUN", 60, 100, upcli_50, white);
	howtoMENU_option1.load_no_outline(texture_renderer, "1  MAKE TEA", 200, 250, luna_29, white);
	howtoMENU_option2.load_no_outline(texture_renderer, "2  CRIMP RJ45", 200, 350, luna_29, white);
	howtoMENU_option3.load_no_outline(texture_renderer, "3  SETUP COMPUTER", 600, 250, luna_29, white);
	howtoMENU_option4.load_no_outline(texture_renderer, "4  MAKE STRETCHER", 600, 350, luna_29, white);
	options_options1.load_no_outline(texture_renderer, "SOUNDS", 395, 201, luna_29, black);
	options_options3.load_no_outline(texture_renderer, "YES", 404, 51, luna_29, yellow);
	options_options4.load_no_outline(texture_renderer, "NO", 896, 85, luna_29, yellow);
	options_options2.load_no_outline(texture_renderer, "MUSIC", 395, 300, luna_29, black);
	here.load_no_outline(texture_renderer, "Drop Here!!", 700, 500, luna_25, yellow);
	helpMENU_text.load(texture_renderer, "help", 60, 60, nep_60, outline_nep_60, black, white);
	optionsMENU_text.load(texture_renderer, "options", 60, 60, nep_60, outline_nep_60, black, white);
	creditsMENU_text.load(texture_renderer, "credits", 60, 60, nep_60, outline_nep_60, black, white);
	quitMENU_text.load(texture_renderer, "quit", 60, 60, nep_60, outline_nep_60, black, white);
	quitMENU_ask.load(texture_renderer, "DO YOU REALLY WANT TO QUIT ? ? ", 60, 200, upcli_50, outline_upcli_50, yellow, black);
	quitMENU_YES.load(texture_renderer, "YES", 220, 300, upcli_50, outline_upcli_50, black, white);
	quitMENU_NO.load(texture_renderer, "NO", 60, 300, upcli_50, outline_upcli_50, black, white);
	howtoBut.load(texture_renderer, "how to", 954, 400, nep_60, outline_nep_60, black, white);

	help.load_no_outline(texture_renderer, "Help", help_x, help_y, luna_29, white);
	options.load_no_outline(texture_renderer, "Options", help_x + help.destination.w + 16, help_y + help.destination.h + 6, luna_29, white);
	credits.load_no_outline(texture_renderer, "Credits", options.destination.x + options.destination.w + 16, options.destination.y - 50, luna_29, white);
	quit.load_no_outline(texture_renderer, "Quit", credits.destination.x + credits.destination.w + 16, credits.destination.y - 50, luna_29, white);
	bubble.load(texture_renderer, "resources/images/bubble.png", 275, 117);
	bubble2.load(texture_renderer, "resources/images/bubble.png", 754, 144);
	point.load(texture_renderer, "resources/images/point.png", howtoBut.destination.x + 70, howtoBut.destination.y - 30);
	point.destination.w = 38;
	point.source.w = 38;


	//crimper

	welcome.load_media(texture_renderer, "crimp/resources/images/welcome.png", 0, 0);
	table.load_media(texture_renderer, "crimp/resources/images/table.png", 85, 95);
	crimper.load_media(texture_renderer, "crimp/resources/images/crimper-side.png", 1070, 20);
	final_crimp.load_media(texture_renderer, "crimp/resources/images/crimp_fix.png", 506, 173);

	final_crimp.destination.w = final_crimp.source.w / 4;
	final_crimp.source.w = final_crimp.source.w / 4;
	utp.load_media(texture_renderer, "crimp/resources/images/utp.png", 500, 20);
	utp2.load_media(texture_renderer, "crimp/resources/images/utp2.png", 230, 230);

	bar.load_media(texture_renderer, "crimp/resources/images/bar.png", 110, 586);
	bar_slider.load_media(texture_renderer, "crimp/resources/images/bar_slider.png", 120, 578);

	st_through.load_media(texture_renderer, "crimp/resources/images/st_through.jpg", 800, 230);

	utp_big.load_media(texture_renderer, "crimp/resources/images/utp_big.png", -60, 230);
	msg.load_media(texture_renderer, "crimp/resources/images/msg.png", 320, 220);
	done.load_media(texture_renderer, "crimp/resources/images/done.png", 510, 340);
	type1.load_media(texture_renderer, "crimp/resources/images/type1.png", 240, 230);
	type2.load_media(texture_renderer, "crimp/resources/images/type2.png", 240, 230);

	//computer
	bkgrnd.load_texture(texture_renderer, "update_cpu.jpg", 70, 35);
	mou.load_texture(texture_renderer, "usb.png", 640, 210);
	mon.load_texture(texture_renderer, "tat_of_vga.png", 800, 400);
	pwr.load_texture(texture_renderer, "tar_of_power.png", 830, 35);
	key.load_texture(texture_renderer, "usb.png", 640, 300);
	lan2.load_texture(texture_renderer, "lan.png", 610, 580);
	usb_m.load_texture(texture_renderer, "tar_usb.png", 93, 320);
	vga.load_texture(texture_renderer, "vga_ko_tar.png", 118, 265);
	power.load_texture(texture_renderer, "tar-vga.png", 125, 152);
	usb_k.load_texture(texture_renderer, "tar_usb.png", 93, 355);
	lanu.load_texture(texture_renderer, "lan_ko_tar.png", 155, 262);
	backs.load_texture(texture_renderer, "welcome.png", 0, 0);
	last.load_texture(texture_renderer,"cpu_side.png",100,00);
    text.load_texture(texture_renderer,"congo1.png", 300,250);

	//tea

	background.load_image(texture_renderer, "make_tea/resources/images/gameplay1/kitchen.jpg", 0, 0);
	gas.load_image(texture_renderer, "make_tea/resources/images/gameplay1/gas.png", 200, 500);
	pot.load_image(texture_renderer, "make_tea/resources/images/gameplay1/pot.png", 800, 500);
	milk.load_image(texture_renderer, "make_tea/resources/images/gameplay1/milk.png", 100, 90);
	salt.load_image(texture_renderer, "make_tea/resources/images/gameplay1/box_salt.png", 370, 140);
	sugar.load_image(texture_renderer, "make_tea/resources/images/gameplay1/box_sugar.png", 280, 140);
	water.load_image(texture_renderer, "make_tea/resources/images/gameplay1/water.png", 190, 90);
	leaves.load_image(texture_renderer, "make_tea/resources/images/gameplay1/tealeaves.png", 470, 120);
	waterdrop.load_image(texture_renderer, "make_tea/resources/images/gameplay1/waterdrop.png", 243, 500);
	milkdrop.load_image(texture_renderer, "make_tea/resources/images/gameplay1/milkdrop.png", 243, 500);
	leavesdrop.load_image(texture_renderer, "make_tea/resources/images/gameplay1/leavesdrop.png", 243, 500);
	image_done.load_image(texture_renderer, "make_tea/resources/images/gameplay1/ready.png", 800, 300);
	image_done.load_image(texture_renderer, "make_tea/resources/images/gameplay1/ready.png", 800, 300);
	intro.load_image(texture_renderer, "make_tea/resources/images/gameplay1/intro.png", 0, 0);
	fire.load_image(texture_renderer, "make_tea/resources/images/gameplay1/fire2.png", 230, 410);
	fire.destination.w = fire.source.w / 9;
	fire.source.w = fire.source.w / 9;

	button1.load_image(texture_renderer, "make_tea/resources/images/gameplay1/gas_button.png", 200, 610);
	int temp_p;

}
void how_to_render(){
	howtoMENU.render(texture_renderer);
	howtoMENU_text.render(texture_renderer);
	//MENU_text_foot.render(texture_renderer);
	howtoMENU_option1.render_no_outline(texture_renderer);
	howtoMENU_option2.render_no_outline(texture_renderer);
	howtoMENU_option3.render_no_outline(texture_renderer);
	howtoMENU_option4.render_no_outline(texture_renderer);
}
void help_render(){
	howtoMENU.render(texture_renderer);
	helpMENU_text.render(texture_renderer);
	//MENU_text_foot.render(texture_renderer);
}
void options_render(){
	howtoMENU.render(texture_renderer);
	bubble.render(texture_renderer);
	bubble2.render(texture_renderer);

	optionsMENU_text.render(texture_renderer);
	//MENU_text_foot.render(texture_renderer);
	//SDL_RenderDrawLine(texture_renderer,500,200,500,500);
	options_options1.render(texture_renderer);
	options_options2.render(texture_renderer);
	options_options3.render(texture_renderer);
	options_options4.render(texture_renderer);
}
void credits_render(){
	howtoMENU.render(texture_renderer);
	creditsMENU_text.render(texture_renderer);
	//MENU_text_foot.render(texture_renderer);
}
void quit_render(){
	howtoMENU.render(texture_renderer);
	quitMENU_text.render(texture_renderer);
	quitMENU_ask.render(texture_renderer);
	quitMENU_YES.render(texture_renderer);
	quitMENU_NO.render(texture_renderer);
	//MENU_text_foot.render(texture_renderer);
}
void welcomes(){
	SDL_RenderClear(texture_renderer);
	welcome.render_media(texture_renderer);
	SDL_RenderPresent(texture_renderer);
	SDL_Delay(1000);
}
void crimp_render(){
	SDL_SetRenderDrawColor(texture_renderer, 204, 204, 153, 255);

	if (cou == 1)
	{
		cout << ":D :D :D" << endl;
		jack.load_media(texture_renderer, "crimp/resources/images/jack2.png", jack.destination.x, jack.destination.y);
		SDL_RenderClear(texture_renderer);
		jack.render_media(texture_renderer);
		SDL_RenderPresent(texture_renderer);
	}
	else
	{
		jack.load_media(texture_renderer, "crimp/resources/images/jack.png", 1040, 535);
	}
	if (sub_page == 0)
	{
		SDL_RenderClear(texture_renderer);
		table.render_media(texture_renderer);

		if (counter == 1){ utp2.render_media(texture_renderer); }
		else{ utp.render_media(texture_renderer); }
		jack.render_media(texture_renderer);
		crimper.render_media(texture_renderer);
		//bar.render_media(texture_renderer);
		//bar_slider.render_media(texture_renderer);

		SDL_RenderPresent(texture_renderer);
		//loop.running_loop(texture_renderer,&game,table, crimper, jack, utp,utp2, bar, &bar_slider, &page, &counter,&cou, final_crimp);
		//loop.drag_loop(&game,&crimper,&jack,&utp, &utp2, &bar_slider,texture_renderer,table,bar, &page,&counter,&cou);
		loop.running_loop(texture_renderer, &game, table, crimper, jack, utp, utp2, bar, &bar_slider, &sub_page, &counter, &cou, final_crimp, &page, &temp_p);
		loop.drag_loop(&game, &crimper, &jack, &utp, &utp2, &bar_slider, texture_renderer, table, bar, &sub_page, &counter, &cou);
	}
}
void computer_render(){
	SDL_SetRenderDrawColor(texture_renderer, 204, 204, 153, 255);
	SDL_RenderClear(texture_renderer);
	backs.rendering(texture_renderer);
	/*mou.rendering(texture_renderer);
	mon.rendering(texture_renderer);
	pwr.rendering(texture_renderer);
	key.rendering(texture_renderer);
	lan.rendering(texture_renderer);
	*/
	SDL_RenderPresent(texture_renderer);

}
void tea_render(){
	SDL_RenderClear(texture_renderer);

	background.render_gameplay1(texture_renderer);
	gas.render_gameplay1(texture_renderer);
	pot.render_gameplay1(texture_renderer);
	milk.render_gameplay1(texture_renderer);
	salt.render_gameplay1(texture_renderer);
	sugar.render_gameplay1(texture_renderer);
	water.render_gameplay1(texture_renderer);
	leaves.render_gameplay1(texture_renderer);
	// help_text.render_gameplay1(texture_renderer);*/
	intro.render_gameplay1(texture_renderer);
	//fire.render_gameplay1(texture_renderer);
	button1.render_gameplay1(texture_renderer);


	SDL_RenderPresent(texture_renderer);
}
//bool game = true;
int main(int argc, char*argv[]){

	cream = { 204, 204, 153, 255 };
	white = { 255, 255, 255, 255 };
	yellow = { 238, 224, 21, 255 };
	black = { 33, 33, 32, 255 };
	float frameTime = 0;
	float frameTime2 = 0;
	float frameTime3 = 0;
	int prevTime = 0;
	int currentTime = 0;
	float deltaTime = 0;
	bool game_run = true;
	bool begin_run = true;
	bool nextframe = false;
	bool top = true;
	int current_time;



	if (SDL_Init(SDL_INIT_EVERYTHING) == 0){

		window = SDL_CreateWindow("How TO (Kasari Ta) 1.0 (BETA)", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win_w, win_h, SDL_WINDOW_SHOWN);
		if (window != NULL){
			init_font();

			load();
		}
		else{
			cout << "cannot create window" << SDL_GetError() << endl;
		}

	}
	else{
		cout << "cannot initialize SDL" << SDL_GetError() << endl;
	}

	first.main_s("resources/audio/nepathay.wav");

	while (begin_run){
		while (SDL_PollEvent(&intros)){
			if (intros.type == SDL_KEYDOWN){
				if (intros.key.keysym.sym == SDLK_ESCAPE){
					counter += 1;
					if (counter == 3){
						begin_run = false;
					}
				}
			}
		}
		prevTime = currentTime;
		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - prevTime) / 1000.0f;
		frameTime3 += deltaTime;
		frameTime2 += deltaTime;
		if (frameTime2 <= 5.00f){
			if (frameTime3 >= 0.05){
				frameTime3 = 0;


				introd.destination.x += 10;

				SDL_RenderClear(texture_renderer);

				introd.render(texture_renderer);
				SDL_RenderPresent(texture_renderer);

			}


		}
		else if (frameTime2 <= 5.9f){
			SDL_RenderClear(texture_renderer);

			introd.render(texture_renderer);
			SDL_RenderPresent(texture_renderer);
		}
		else if (frameTime2 <= 6.00f){
			SDL_RenderClear(texture_renderer);

			//introd.render(texture_renderer);
			SDL_RenderPresent(texture_renderer);

		}

		else{
			begin_run = false;
		}


	}


	Mix_HaltChannel(-1);
	second.main_s("resources/audio/back.wav");
	while (game_run){

		if (page == 0){


			//SDL_RenderClear(texture_renderer);
			//main_render();
			//SDL_RenderPresent(texture_renderer);
			event.main_event = true;
			event.events(texture_renderer, howtoBut, help, options, credits, quit, here, howto_back, howto_logo, hamro_logo, &page, frameTime, prevTime, currentTime, deltaTime, frameTime2, &clouds, &bird, &top, &point);
			event.event_drag(texture_renderer, howtoBut, help, options, credits, quit, howto_back, howto_logo, hamro_logo, &page, frameTime, prevTime, currentTime, deltaTime, frameTime2, &clouds, &bird, &top, &point);
		}
		else if (page == 1){
			SDL_RenderClear(texture_renderer);
			how_to_render();
			SDL_RenderPresent(texture_renderer);
			howtoMENU.sub_event = true;
			howtoMENU.events(howtoMENU_option1, howtoMENU_option2, howtoMENU_option3, howtoMENU_option4, &page);
		}
		else if (page == 2){
			SDL_RenderClear(texture_renderer);
			help_render();
			SDL_RenderPresent(texture_renderer);
			helpMENU.sub_event = true;
			helpMENU.events(&page);
		}
		else if (page == 3){
			SDL_SetRenderDrawColor(texture_renderer, 0, 0, 0, 255);
			SDL_RenderClear(texture_renderer);
			options_render();
			SDL_RenderPresent(texture_renderer);
			optionsMENU.sub_event = true;
			optionsMENU.events(&page, options_options1, options_options2);
			optionsMENU.drag_event(texture_renderer, &options_options1, &options_options2, &sounds_play, &music_play, howtoMENU, optionsMENU_text, MENU_text_foot, options_options3, options_options4, bubble, bubble2);
		}
		else if (page == 4){

			SDL_RenderClear(texture_renderer);
			credits_render();
			SDL_RenderPresent(texture_renderer);
			creditsMENU.sub_event = true;
			creditsMENU.events(&page);
		}
		else if (page == 5){

			SDL_RenderClear(texture_renderer);
			quit_render();
			SDL_RenderPresent(texture_renderer);
			quitMENU.sub_event = true;
			quitMENU.events(&page, &game_run, quitMENU_YES, quitMENU_NO);
		}
		else if (page == 6){
			sound1.int_mixer();
			sound1.main_soundwav("resources/audio/back2.wav");


			tea_render();
			//MENU_text_foot.render(texture_renderer);
			SDL_RenderPresent(texture_renderer);
			main_game = true;
			g1.click = true;
			while (main_game){
				g1.click_loop(&main_game, water, milk, pot, sugar, salt, leaves, soundleaves, &fire, texture_renderer, button1, background, gas, milkdrop, waterdrop, leavesdrop, &page, &temp_p);
				g1.drag_event(&main_game, &water, &milk, &pot, &sugar, &salt, &leaves, texture_renderer, background, gas, waterdrop, milkdrop, sound1, sound2, leavesdrop, soundleaves, image_done, &fire, button1);


			}
		}
		else if (page == 7){


			game = true;
			loop.run_loop = true;
			welcomes();
			while (game){

				SDL_RenderClear(texture_renderer);
				crimp_render();
				// MENU_text_foot.render(texture_renderer);
				SDL_RenderPresent(texture_renderer);


				if (sub_page == 1)
				{
					cout << "yes" << endl;
					SDL_RenderClear(texture_renderer);

					type1.render_media(texture_renderer);
					st_through.render_media(texture_renderer);

					utp_big.render_media(texture_renderer);
					//msg.render_media(texture_renderer);
					//done.render_media(texture_renderer);
					SDL_RenderPresent(texture_renderer);
					loop.wire_sort(texture_renderer, &game, &sub_page, st_through, utp_big, msg, done, &ma, &counter, type1, type2);
				}

				if (sub_page == 2)
				{

					SDL_RenderClear(texture_renderer);
					table.render_media(texture_renderer);
					final_crimp.render_media(texture_renderer);
					bar.render_media(texture_renderer);
					bar_slider.render_media(texture_renderer);

					SDL_RenderPresent(texture_renderer);
					loop.final_crimp(texture_renderer, &game, &page, table, final_crimp, bar, &bar_slider, &page, &temp_p);

				}




			}
		}
		else if (page == 8){
			//system("D:\HOW TO\1stSEM_Project\HOWTO\HowTo(Kasari)\Release\The-How-To.exe");
			SDL_RenderClear(texture_renderer);
			computer_render();
			SDL_RenderPresent(texture_renderer);
			comp_game = true;
			ab.click = true;
			while (comp_game)
			{
				ab.click_check(&comp_game,text,last, mou, mon, pwr, key, lan2, backs, bkgrnd, sprt, texture_renderer, &page, &temp_p);
				ab.drag_event(&comp_game, &mou, &mon, &pwr, &key, &lan2, &bkgrnd, &usb_m, &vga, &power, &usb_k, &lanu, texture_renderer);
			}
		}
		else if (page == 9){

			SDL_RenderClear(texture_renderer);
			howtoMENU.render(texture_renderer);
			quitMENU_text.render(texture_renderer);
			quitMENU_ask.render(texture_renderer);
			quitMENU_YES.render(texture_renderer);
			quitMENU_NO.render(texture_renderer);
			MENU_text_foot.render(texture_renderer);
			SDL_RenderPresent(texture_renderer);
			quitMENU.sub_event = true;
			quitMENU.events(&page, &game_run, quitMENU_YES, quitMENU_NO);
		}
		else if (page == 10){

			SDL_RenderClear(texture_renderer);
			howtoMENU.render(texture_renderer);
			quitMENU_text.render(texture_renderer);
			quitMENU_ask.render(texture_renderer);
			quitMENU_YES.render(texture_renderer);
			quitMENU_NO.render(texture_renderer);
			MENU_text_foot.render(texture_renderer);
			SDL_RenderPresent(texture_renderer);
			quitMENU2.sub_event = true;
			quitMENU2.events2(&page, &game_run, quitMENU_YES, quitMENU_NO, &temp_p);
		}

	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(texture_renderer);
	TTF_CloseFont(upcli_150);
	TTF_CloseFont(upcli_50);
	TTF_CloseFont(outline_upcli_50);
	TTF_CloseFont(nep_60);
	TTF_CloseFont(outline_nep_60);
	TTF_CloseFont(outline_luna_29);
	TTF_CloseFont(luna_25);
	TTF_CloseFont(luna_29);
	SDL_Quit();
	return 0;
}
