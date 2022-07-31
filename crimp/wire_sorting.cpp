#include "crimp.h"


void crimp :: wire_sort(SDL_Renderer *texture_renderer,bool *game,  int* p, crimp st_through, crimp utp_big, crimp msg, crimp done, int* m, int* c, crimp type1, crimp type2)
{
    int i;
    if(*c ==1){sort_loop = false; *p=0;}


    while(sort_loop)
    {

        while(SDL_PollEvent(&event))
        {

            if(event.type==SDL_QUIT)
            {
                running=false;
                sort_loop = false;
                *game=false;
            }

            else if(event.type==SDL_MOUSEBUTTONDOWN)
            {
                switch(event.button.button)
                {
                case SDL_BUTTON_LEFT:
                    if(event.button.x>st_through.destination.x && event.button.x<st_through.destination.x+st_through.destination.w &&
                            event.button.y>st_through.destination.y && event.button.y<st_through.destination.y+st_through.destination.h)
                            {
                                SDL_RenderClear(texture_renderer);

                                type2.render_media(texture_renderer);
                                st_through.render_media(texture_renderer);
                                utp_big.render_media(texture_renderer);

                                //msg.render_media(texture_renderer);
                                //done.render_media(texture_renderer);

                                SDL_RenderPresent(texture_renderer);

                                SDL_Delay(1000);

                                SDL_RenderClear(texture_renderer);

                                msg.render_media(texture_renderer);
                                done.render_media(texture_renderer);

                                SDL_RenderPresent(texture_renderer);
                                cout<<"pressed"<<endl;


                            }

                                if(event.button.x>done.destination.x && event.button.x<done.destination.x+done.destination.w &&
                                    event.button.y>done.destination.y && event.button.y<done.destination.y+done.destination.h)
                                    {
                                        cout<<"chalyo chalyo yay yay"<<endl;
                                            *c = 1;
                                            *p =0;
                                            sort_loop = false;
                                            run_loop = true;
                                            *game=true;
                                    }

                            }


                            break;
                }


            }

        }
    }

