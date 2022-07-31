#include "make_tea.h"

 SDL_Window* window=NULL;
 SDL_Renderer* texture_renderer=NULL;
 SDL_Event event;
 int win_w=1200;
 int win_h=675;





int create_window(){
    if (SDL_Init(SDL_INIT_EVERYTHING)==0){

        window=SDL_CreateWindow(
                                "Level 1 Make Tea)",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                win_w,
                                win_h,
                                SDL_WINDOW_SHOWN);
    }
    else{
    cout<<"Cannot initialize SDL "<<SDL_GetError()<<endl;
    return 1;
    }
    if(window==NULL){
        cout<<"Cannot create window"<<SDL_GetError()<<endl;
        return 1;
    }
    else{
        texture_renderer=SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED);


    }

}

level1 background,pot,milk,sugar,salt,water,gas,event_drag,g1,
                    leaves,sound1,waterdrop,milkdrop,sound2,
                                leavesdrop,soundleaves,image_done,help_text,help_pot,intro,fire,button1;
bool main_game=true;







int main(int argc , char* argv[]){




sound1.int_mixer();
sound1.main_soundwav("resources/audio/back2.wav");



 create_window();


 background.load_image(texture_renderer,"resources/images/gameplay1/kitchen.jpg",0,0);
 gas.load_image(texture_renderer,"resources/images/gameplay1/gas.png",200,500);
 pot.load_image(texture_renderer,"resources/images/gameplay1/pot.png",800,500);
 milk.load_image(texture_renderer,"resources/images/gameplay1/milk.png",100,90);
 salt.load_image(texture_renderer,"resources/images/gameplay1/box_salt.png",370,140);
 sugar.load_image(texture_renderer,"resources/images/gameplay1/box_sugar.png",280,140);
 water.load_image(texture_renderer,"resources/images/gameplay1/water.png",190,90);
 leaves.load_image(texture_renderer,"resources/images/gameplay1/tealeaves.png",470,120);
 waterdrop.load_image(texture_renderer,"resources/images/gameplay1/waterdrop.png",243,500);
 milkdrop.load_image(texture_renderer,"resources/images/gameplay1/milkdrop.png",243,500);
 leavesdrop.load_image(texture_renderer,"resources/images/gameplay1/leavesdrop.png",243,500);
 image_done.load_image(texture_renderer,"resources/images/gameplay1/ready.png",700,300);
 intro.load_image(texture_renderer,"resources/images/gameplay1/Intro.png",0,0);
 fire.load_image(texture_renderer,"resources/images/gameplay1/fire2.png",230,410);
 fire.destination.w=fire.source.w/9;
 fire.source.w=fire.source.w/9;

 button1.load_image(texture_renderer,"resources/images/gameplay1/gas_button.png",200,610);



 SDL_RenderClear(texture_renderer);
 background.render_gameplay1(texture_renderer);
 gas.render_gameplay1(texture_renderer);
 pot.render_gameplay1(texture_renderer);
 milk.render_gameplay1(texture_renderer);
 salt.render_gameplay1(texture_renderer);
 sugar.render_gameplay1(texture_renderer);
 water.render_gameplay1(texture_renderer);
 leaves.render_gameplay1(texture_renderer);
// help_text.render_gameplay1(texture_rendere);
 //intro.render_gameplay1(texture_renderer);
 //fire.render_gameplay1(texture_renderer);
 button1.render_gameplay1(texture_renderer);
  intro.render_gameplay1(texture_renderer);
  //image_done.render_gameplay1(texture_renderer);



 SDL_RenderPresent(texture_renderer);









while(main_game){
g1.click_loop(&main_game,water,milk,pot,sugar,salt,leaves,soundleaves,&fire,texture_renderer,button1,background,gas,milkdrop,waterdrop,leavesdrop);
    g1.drag_event(&main_game,&water,&milk,&pot,&sugar,&salt,&leaves,texture_renderer,background,gas,waterdrop,milkdrop,sound1,sound2,leavesdrop,soundleaves,image_done,&fire,button1);


}



 }
