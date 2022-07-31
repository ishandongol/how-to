#include"crimp.h"

void crimp::final_crimp(SDL_Renderer *texture_renderer, bool *game,  int* p, crimp table, crimp final_crimp, crimp bar, crimp *bar_slider,int *p2,int*temp_p)
{
    *temp_p=*p2;
    while(crimp_loop)
    {
                SDL_RenderClear(texture_renderer);
                table.render_media(texture_renderer);
                final_crimp.render_media(texture_renderer);
                bar.render_media(texture_renderer);
                bar_slider->render_media(texture_renderer);

                SDL_RenderPresent(texture_renderer);

                while(SDL_PollEvent(&event))
                {
                     if(event.type==SDL_QUIT)
            {
               crimp_loop=false;
                *game=false;
                *p2=10;

            }



                    else if(event.type == SDL_KEYDOWN)
                    {
                        switch (event.key.keysym.sym)
                                {
                                case SDLK_ESCAPE:
                                    crimp_loop=false;
                                *game=false;
                                *p2=10;
                                    break;
                                }
                           if(event.key.keysym.sym == SDLK_RIGHT)
                           {


                                    if(bar_slider->destination.x>bar.destination.x+bar.destination.w){
                                        bar_slider->destination.x=bar_slider->destination.x;
                                    }
                                    else{
                                            bar_slider->destination.x=bar_slider->destination.x+55;
                                            final_crimp.source.x+=200;
                                            if(final_crimp.source.x>=600){
                                                final_crimp.source.x=0;
                                    }
                                    }
                                    cout<<"yes keyboard event"<<endl;

                                    SDL_RenderClear(texture_renderer);
                                    table.render_media(texture_renderer);
                                    final_crimp.render_media(texture_renderer);
                                   // bar.render_media(texture_renderer);
                                   // bar_slider->render_media(texture_renderer);

                                    SDL_RenderPresent(texture_renderer);
                           }


                    }

                SDL_RenderClear(texture_renderer);
                table.render_media(texture_renderer);
                final_crimp.render_media(texture_renderer);
                bar.render_media(texture_renderer);
                bar_slider->render_media(texture_renderer);
                SDL_RenderPresent(texture_renderer);


                }

    }

}
