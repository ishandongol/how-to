#include"game.h"

    SDL_Event intro;
    SDL_Window *window=NULL;
    SDL_Renderer *texture_renderer=NULL;
    int win_w=1200;
    int win_h=675;
    int help_x=629;
    int help_y=257;
    TTF_Font *upcli_150, *luna_29, *upcli_50,*luna_25,*nep_60, *outline_upcli_50, *outline_nep_60, *outline_luna_29;
    SDL_Color cream, white,red,black;
    MAINMenu howto_back, howto_logo, hamro_logo, introd, sub_menu, clouds, bird;
    subMENU1 howtoMENU, howtotea, howtocrimp;
    subMENU2 helpMENU;
    subMENU3 optionsMENU;
    subMENU4 creditsMENU;
    subMENU5 quitMENU;
    buttons howtoBut,here, options, credits, help, quit, howtoMENU_text, MENU_text_foot,howtoMENU_option1,howtoMENU_option2,howtoMENU_option3,howtoMENU_option4;
    buttons helpMENU_text,optionsMENU_text,creditsMENU_text,quitMENU_text,quitMENU_ask,quitMENU_YES,quitMENU_NO;
    buttons beginning[7], options_options1, options_options2, options_options3, options_options4;
    buttons RC;
    sounds first, second;
    MAINMenu event;
    tea gas;
    bool sounds_play=true;
    bool music_play=true;

void init_font(){
if(TTF_Init()== 0){
    upcli_150= TTF_OpenFont("resources/font/upcli.ttf", 150);
    luna_29= TTF_OpenFont("resources/font/luna.ttf", 29);
    upcli_50 = TTF_OpenFont("resources/font/upcli.ttf", 50);
    luna_25= TTF_OpenFont("resources/font/luna.ttf", 25);
    nep_60 = TTF_OpenFont("resources/font/nep.ttf", 60);
    outline_upcli_50 = TTF_OpenFont("resources/font/upcli.ttf", 50);
    outline_nep_60 = TTF_OpenFont("resources/font/nep.ttf", 60);
    outline_luna_29= TTF_OpenFont("resources/font/luna.ttf", 29);
    TTF_SetFontOutline(outline_upcli_50, 1);
    TTF_SetFontOutline(outline_nep_60, 1);
    TTF_SetFontOutline(outline_luna_29, 1);


    }
    else{
        cout<<"cannot open font"<<TTF_GetError()<<endl;
    }
}
/*
void main_render(){

        howto_back.render(texture_renderer);
        howto_logo.render(texture_renderer);
        hamro_logo.render(texture_renderer);
        howtoBut.render(texture_renderer);
        help.render(texture_renderer);
        options.render(texture_renderer);
        credits.render(texture_renderer);
        quit.render(texture_renderer);


        cout<<"yes"<<endl;

}*/
void load(){
                texture_renderer=SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED);
                SDL_SetRenderDrawColor(texture_renderer,6,140,179,255);
                clouds.load(texture_renderer,"resources/images/test.png",1000,0);
                bird.load(texture_renderer,"resources/images/bird.png",400,675);
                bird.destination.w=bird.source.w/8;
                 //bird.source.x+=160;
                //bird.destination.h=bird.source.h/3;
                bird.source.w=bird.source.w/8;
                //bird.source.h=bird.source.h/3;
                howto_back.load(texture_renderer,"resources/images/b.jpg",0,0);
                introd.load(texture_renderer,"resources/images/hamro.png",win_w/2+60,win_h/2+80);
                howto_logo.load(texture_renderer,"resources/images/log.png",70,70);
                hamro_logo.load(texture_renderer,"resources/images/portal.png",985,40);
                howtoMENU.load(texture_renderer,"resources/images/sub_howto.jpg",0,0);
                howtotea.load(texture_renderer,"resources/images/tex.jpg",0,0);
                gas.load(texture_renderer,"resources/images/tea/gas.png",200,500);
                howtocrimp.load(texture_renderer,"resources/images/crimp.jpg",0,0);
                howtoMENU_text.load(texture_renderer,"howto",60, 60, nep_60, outline_nep_60,black, white);
                MENU_text_foot.load(texture_renderer,"CODE-O-METRY",900, 600,upcli_50,outline_upcli_50,black, red);
                beginning[4].load_no_outline(texture_renderer,"CODE-O-METRY",win_w/2, win_h/2,upcli_150,white);
                beginning[4].destination.x=win_w/2-beginning[4].destination.w/2;
                beginning[4].destination.y=win_h/2-beginning[4].destination.h/2;
                sub_menu.load(texture_renderer,"resources/images/b2.jpg",0,0);
                beginning[6].load_no_outline(texture_renderer,"JUST DRAG & DROP ON THE SUN",230, 400,upcli_50,white);
                howtoMENU_option1.load_no_outline(texture_renderer,"1  MAKE TEA",150, 250, luna_29,white);
                howtoMENU_option2.load_no_outline(texture_renderer,"2  CRIMP RJ45",150, 350, luna_29, white);
                howtoMENU_option3.load_no_outline(texture_renderer,"3  SETUP COMPUTER",150, 450, luna_29, white);
                howtoMENU_option4.load_no_outline(texture_renderer,"4  MAKE STRETCHER",150, 550, luna_29,white);
                options_options1.load_no_outline(texture_renderer,"SOUNDS",200, 300, luna_29,white);
                options_options3.load_no_outline(texture_renderer,"YES",200, 200, luna_29,black);
                options_options4.load_no_outline(texture_renderer,"NO",700, 200, luna_29,black);
                options_options2.load_no_outline(texture_renderer,"MUSIC",200, 400, luna_29,white);
                here.load_no_outline(texture_renderer,"Drop Here!!",700,500,luna_25,red);
                helpMENU_text.load(texture_renderer,"help",60, 60, nep_60, outline_nep_60,black, white);
                optionsMENU_text.load(texture_renderer,"options",60, 60, nep_60, outline_nep_60,black, white);
                creditsMENU_text.load(texture_renderer,"credits",60, 60, nep_60, outline_nep_60,black, white);
                quitMENU_text.load(texture_renderer,"quit",60, 60, nep_60, outline_nep_60,black, white);
                quitMENU_ask.load(texture_renderer,"DO YOU REALLY WANT TO QUIT ? ? ",60,400, upcli_50, outline_upcli_50,red, black);
                quitMENU_YES.load(texture_renderer,"YES",220,500, upcli_50, outline_upcli_50,black, white);
                quitMENU_NO.load(texture_renderer,"NO",60,500, upcli_50, outline_upcli_50,black, white);
                howtoBut.load(texture_renderer,"how to",954,400,nep_60,outline_nep_60,black,white);
                help.load_no_outline(texture_renderer,"Help",help_x,help_y,luna_29,white);
                options.load_no_outline(texture_renderer,"Options",help_x+help.destination.w+16,help_y+help.destination.h+6,luna_29,white);
                credits.load_no_outline(texture_renderer,"Credits",options.destination.x+options.destination.w+16,options.destination.y-50,luna_29,white);
                quit.load_no_outline(texture_renderer,"Quit",credits.destination.x+credits.destination.w+16,credits.destination.y-50,luna_29,white);

}
void how_to_render(){
howtoMENU.render(texture_renderer);
            howtoMENU_text.render(texture_renderer);
            MENU_text_foot.render(texture_renderer);
            howtoMENU_option1.render_no_outline(texture_renderer);
            howtoMENU_option2.render_no_outline(texture_renderer);
            howtoMENU_option3.render_no_outline(texture_renderer);
            howtoMENU_option4.render_no_outline(texture_renderer);
}
void help_render(){
    sub_menu.render(texture_renderer);
            helpMENU_text.render(texture_renderer);
            MENU_text_foot.render(texture_renderer);
}
void options_render(){
    sub_menu.render(texture_renderer);
            optionsMENU_text.render(texture_renderer);
            MENU_text_foot.render(texture_renderer);
            SDL_RenderDrawLine(texture_renderer,500,200,500,500);
            options_options1.render(texture_renderer);
            options_options2.render(texture_renderer);
            options_options3.render(texture_renderer);
            options_options4.render(texture_renderer);
}
void credits_render(){
    sub_menu.render(texture_renderer);
            creditsMENU_text.render(texture_renderer);
            MENU_text_foot.render(texture_renderer);
}
void quit_render(){
     howtoMENU.render(texture_renderer);
            quitMENU_text.render(texture_renderer);
            quitMENU_ask.render(texture_renderer);
            quitMENU_YES.render(texture_renderer);
            quitMENU_NO.render(texture_renderer);
            MENU_text_foot.render(texture_renderer);
}
int main(int argc, char*argv[]){
     cream= {204,204,153,255};
      white= {255,255,255,255};
      red={255,49,49,255};
      black={33,33,32,255};
      float frameTime=0;
      float frameTime2=0;
    int prevTime=0;
    int currentTime=0;
    float deltaTime=0;
    bool game_run=true;
    bool begin_run=true;
    bool top=true;
    int current_time;
    int page=0;


    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
    window=SDL_CreateWindow("How TO (Kasari Ta) 1.0 (BETA)",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,win_w,win_h,SDL_WINDOW_SHOWN);
    init_font();
    if(window != NULL){
        load();
    }
    else{
        cout<<"cannot create window"<<SDL_GetError()<<endl;
    }

    }
    else{
        cout<<"cannot initialize SDL"<<SDL_GetError()<<endl;
    }
    if(sounds_play){
      first.main_s("resources/audio/nepathay.wav");
    }

while(begin_run){
            while(SDL_PollEvent(&intro)){
                if(intro.type == SDL_KEYDOWN){
                    if(intro.key.keysym.sym== SDLK_ESCAPE){
                        begin_run=false;
                    }
                }
            }
            current_time=SDL_GetTicks();

    if(current_time<8000){

                SDL_RenderClear(texture_renderer);
                howtoMENU.render(texture_renderer);
                hamro_logo.render(texture_renderer);
                beginning[6].render(texture_renderer);
                SDL_RenderPresent(texture_renderer);

        }
        else if(current_time>=8300 && current_time<10000){
               introd.render(texture_renderer);
               SDL_RenderPresent(texture_renderer);
               howtoMENU.render(texture_renderer);
                SDL_RenderClear(texture_renderer);
                    howtoMENU.render(texture_renderer);
                SDL_RenderPresent(texture_renderer);
                SDL_RenderClear(texture_renderer);
                howtoMENU.render(texture_renderer);
                SDL_RenderPresent(texture_renderer);



        }

     else if(current_time>=10000&& current_time<10695){
    SDL_RenderClear(texture_renderer);
    howto_logo.render(texture_renderer);
    SDL_RenderPresent(texture_renderer);
    SDL_RenderClear(texture_renderer);
    SDL_RenderPresent(texture_renderer);
    SDL_RenderClear(texture_renderer);
    SDL_RenderPresent(texture_renderer);

}



    else if(current_time>=10695){
        begin_run=false;

    }





    }


Mix_HaltChannel(-1);
second.main_s("resources/audio/back.wav");
while(game_run){

            if(page==0){

                //SDL_RenderClear(texture_renderer);
                //main_render();
                //SDL_RenderPresent(texture_renderer);
                event.main_event=true;
                event.events(texture_renderer,howtoBut,help,options,credits,quit,here,howto_back,howto_logo,hamro_logo,&page, frameTime, prevTime, currentTime, deltaTime,frameTime2, &clouds, &bird,top);
                event.event_drag(texture_renderer,howtoBut,help,options,credits,quit, howto_back, howto_logo,hamro_logo,&page, frameTime, prevTime, currentTime, deltaTime,frameTime2, &clouds,&bird,top);
            }
            else if(page==1){
            SDL_RenderClear(texture_renderer);
            how_to_render();
            SDL_RenderPresent(texture_renderer);
            howtoMENU.sub_event=true;
            howtoMENU.events(howtoMENU_option1,howtoMENU_option2,howtoMENU_option3,howtoMENU_option4,&page);
            }
            else if(page==2){
            SDL_RenderClear(texture_renderer);
            help_render();
            SDL_RenderPresent(texture_renderer);
            helpMENU.sub_event=true;
            helpMENU.events(&page);
            }
            else if(page==3){
            SDL_SetRenderDrawColor(texture_renderer,0,0,0,255);
            SDL_RenderClear(texture_renderer);
            options_render();
            SDL_RenderPresent(texture_renderer);
            optionsMENU.sub_event=true;
            optionsMENU.events(&page,options_options1,options_options2);
            optionsMENU.drag_event(texture_renderer,&options_options1,&options_options2,&sounds_play,&music_play,sub_menu,optionsMENU_text,MENU_text_foot,options_options3,options_options4);
            }
            else if(page==4){

            SDL_RenderClear(texture_renderer);
            credits_render();
            SDL_RenderPresent(texture_renderer);
            creditsMENU.sub_event=true;
            creditsMENU.events(&page);
            }
             else if(page==5){

             SDL_RenderClear(texture_renderer);
            quit_render();
            SDL_RenderPresent(texture_renderer);
            quitMENU.sub_event=true;
            quitMENU.events(&page,&game_run,quitMENU_YES, quitMENU_NO);
            }
             else if(page==6){

             SDL_RenderClear(texture_renderer);
             howtotea.render(texture_renderer);
             gas.render(texture_renderer);
            MENU_text_foot.render(texture_renderer);
            SDL_RenderPresent(texture_renderer);
            quitMENU.sub_event=true;
            quitMENU.events(&page,&game_run,quitMENU_YES,quitMENU_NO);
            }
            else if(page==7){

             SDL_RenderClear(texture_renderer);
             howtocrimp.render(texture_renderer);
            MENU_text_foot.render(texture_renderer);
            SDL_RenderPresent(texture_renderer);
            quitMENU.sub_event=true;
            quitMENU.events(&page,&game_run,quitMENU_YES,quitMENU_NO);
            }
            else if(page==8){

             SDL_RenderClear(texture_renderer);
             howtoMENU.render(texture_renderer);
            SDL_RenderPresent(texture_renderer);
            quitMENU.sub_event=true;
            quitMENU.events(&page,&game_run,quitMENU_YES,quitMENU_NO);
            }
            else if(page==9){

             SDL_RenderClear(texture_renderer);
             howtoMENU.render(texture_renderer);
            quitMENU_text.render(texture_renderer);
            quitMENU_ask.render(texture_renderer);
            quitMENU_YES.render(texture_renderer);
            quitMENU_NO.render(texture_renderer);
            MENU_text_foot.render(texture_renderer);
            SDL_RenderPresent(texture_renderer);
            quitMENU.sub_event=true;
            quitMENU.events(&page,&game_run,quitMENU_YES,quitMENU_NO);
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
