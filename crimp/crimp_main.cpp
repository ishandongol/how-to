#include"crimp.h"
int win_w=1200;
int win_h=675;
SDL_Window *window=NULL;
SDL_Renderer *texture_renderer=NULL;
SDL_Texture *texture=NULL;
 int temp_x=0, temp_y=0;
bool next_table;
int page = 0;
int *p=0;
int counter = 0;
int cou = 0;
int ma=0;


void create_window()
{
         if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
        {
            window = SDL_CreateWindow ("Crimp the RJ-45",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          win_w,win_h,
                                          SDL_WINDOW_SHOWN
                                          );

        }

        else
        {
            cout<<"cannot initialize "<<SDL_GetError()<<endl;
        }

        if(window==NULL)
        {
            cout<<"Cannot create window"<<SDL_GetError()<<endl;

        }

        else
        {
            texture_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        }



}

crimp welcome,table, crimper, jack, utp,utp2, bar, bar_slider, loop, st_through, crossover,utp_big, msg, done, type1, type2, final_crimp;
bool game = true;
int main(int agrc, char* argv[])
{
    create_window();

    welcome.load_media(texture_renderer, "resources/images/welcome.png", 0,0);
    table.load_media(texture_renderer, "resources/images/table.png", 85, 95);
    crimper.load_media(texture_renderer, "resources/images/crimper-side.png",1070, 80);
    final_crimp.load_media(texture_renderer,"resources/images/crimp_fix.png",506,173);

final_crimp.destination.w=final_crimp.source.w/4;
final_crimp.source.w=final_crimp.source.w/4;
    utp.load_media(texture_renderer, "resources/images/utp.png", 500, 20);
    utp2.load_media(texture_renderer, "resources/images/utp2.png", 230, 230);

    bar.load_media(texture_renderer, "resources/images/bar.png", 110, 586);
    bar_slider.load_media(texture_renderer, "resources/images/bar_slider.png", 120, 578);

    st_through.load_media(texture_renderer, "resources/images/st_through.jpg", 800, 230);

    utp_big.load_media(texture_renderer, "resources/images/utp_big.png", -60,230);
    msg.load_media(texture_renderer, "resources/images/msg.png", 320, 220);
    done.load_media(texture_renderer, "resources/images/done.png", 510, 340);
    type1.load_media(texture_renderer,"resources/images/type1.png",240,230);
    type2.load_media(texture_renderer,"resources/images/type2.png",240,230);

    SDL_SetRenderDrawColor(texture_renderer,204,204,153,255);
    SDL_RenderClear(texture_renderer);
    welcome.render_media(texture_renderer);
    SDL_RenderPresent(texture_renderer);
    SDL_Delay(1000);


    while(game)

    {
        if(cou == 1)
        {
            cout<<":D :D :D"<<endl;
            jack.load_media(texture_renderer, "resources/images/jack2.png", jack.destination.x, jack.destination.y);
            SDL_RenderClear(texture_renderer);
            jack.render_media(texture_renderer);
            SDL_RenderPresent(texture_renderer);
        }
    else
    {
        jack.load_media(texture_renderer, "resources/images/jack.png", 1040, 535);
    }
        if(page == 0)
        {
        SDL_RenderClear(texture_renderer);
        table.render_media(texture_renderer);

        if(counter == 1){utp2.render_media(texture_renderer);}
        else{utp.render_media(texture_renderer);}
        jack.render_media(texture_renderer);
        crimper.render_media(texture_renderer);
        //bar.render_media(texture_renderer);
        //bar_slider.render_media(texture_renderer);

            SDL_RenderPresent(texture_renderer);
            loop.running_loop(texture_renderer,&game,table, crimper, jack, utp,utp2, bar, &bar_slider, &page, &counter,&cou, final_crimp);
            loop.drag_loop(&game,&crimper,&jack,&utp, &utp2, &bar_slider,texture_renderer,table,bar, &page,&counter,&cou);
        }

        if(page == 1)
        {
                SDL_RenderClear(texture_renderer);

                type1.render_media(texture_renderer);
                st_through.render_media(texture_renderer);

                utp_big.render_media(texture_renderer);
                //msg.render_media(texture_renderer);
                //done.render_media(texture_renderer);
                SDL_RenderPresent(texture_renderer);
                loop.wire_sort(texture_renderer, &game, &page, st_through, utp_big, msg, done, &ma, &counter, type1, type2);
        }

        if(page == 2)
        {

                SDL_RenderClear(texture_renderer);
                table.render_media(texture_renderer);
                final_crimp.render_media(texture_renderer);
                bar.render_media(texture_renderer);
                bar_slider.render_media(texture_renderer);

                SDL_RenderPresent(texture_renderer);
                loop.final_crimp(texture_renderer, &game, &page, table, final_crimp, bar, &bar_slider);

        }


    }


}
