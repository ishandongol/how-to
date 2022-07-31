
#include"crimp.h"

void crimp :: running_loop (SDL_Renderer *texture_renderer,bool *game, crimp table, crimp crimper, crimp jack, crimp utp,crimp utp2, crimp bar, crimp *bar_slider,   int* p, int* c, int* co, crimp final_crimp, int*p2, int*temp_p )
{
    *temp_p=*p2;
    while(run_loop)
    {



        while(SDL_PollEvent(&event))
        {


            if(event.type==SDL_QUIT)
            {
               run_loop=false;
                *game=false;
                *p2=10;

            }

            else if(event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                                {
                                case SDLK_ESCAPE:
                                    run_loop=false;
                                *game=false;
                                *p2=10;
                                    break;
                                }
                if(event.key.keysym.sym == SDLK_SPACE)
                {
                    SDL_RenderClear(texture_renderer);

                    table.render_media(texture_renderer);

                    utp.render_media(texture_renderer);
                    jack.render_media(texture_renderer);
                    crimper.render_media(texture_renderer);
                   // bar.render_media(texture_renderer);
                    //bar_slider->render_media(texture_renderer);

                    SDL_RenderPresent(texture_renderer);

                }
            }

            else if(event.type==SDL_MOUSEBUTTONDOWN)
            {

                switch(event.button.button)
                {
                case SDL_BUTTON_LEFT:



                    if(event.button.x>crimper.destination.x && event.button.x<crimper.destination.x+crimper.destination.w &&
                            event.button.y>crimper.destination.y && event.button.y<crimper.destination.y+crimper.destination.h)
                    {

                        cout<<"pressed"<<endl;
                        obj=1;
                        temp_x = crimper.destination.x;
                        temp_y = crimper.destination.y;

                        drag_drop=true;
                        run_loop=false;
                        *game=true;
                    }

                    else if(event.button.x>jack.destination.x && event.button.x<jack.destination.x+jack.destination.w &&
                            event.button.y>jack.destination.y && event.button.y<jack.destination.y+jack.destination.h)
                    {

                        cout<<"pressed"<<endl;
                        obj=2;
                        temp_x = jack.destination.x;
                        temp_y = jack.destination.y;


                        drag_drop=true;
                        run_loop=false;
                        *game=true;
                    }

                    else if(event.button.x>utp.destination.x && event.button.x<utp.destination.x+utp.destination.w &&
                                event.button.y>utp.destination.y && event.button.y<utp.destination.y+utp.destination.h )
                        {

                            cout<<"pressed"<<endl;
                            obj=3;
                            temp_x = utp.destination.x;
                            temp_y = utp.destination.y;

                            drag_drop=true;
                            run_loop=false;
                            *game=true;
                        }




                    else if(event.button.x>bar_slider->destination.x && event.button.x<bar_slider->destination.x+bar_slider->destination.w &&
                            event.button.y>bar_slider->destination.y && event.button.y<bar_slider->destination.y+bar_slider->destination.h)
                    {

                        cout<<"pressed"<<endl;
                        obj=4;
                        temp_x = bar_slider->destination.x;
                        temp_y = bar_slider->destination.y;

                        drag_drop=true;
                        run_loop=false;
                        *game=true;
                    }

                    break;
                }
            }

        }
    }
    SDL_Delay(10);
}


void crimp :: drag_loop(bool *game,crimp *crimper, crimp *jack, crimp *utp,crimp *utp2, crimp *bar_slider, SDL_Renderer *texture_renderer, crimp table, crimp bar, int* p, int* c, int* co)
{
    while(drag_drop)
    {

        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT)
            {
                drag_drop=false;
                *game=false;

            }

            if(event.type==SDL_MOUSEMOTION)
            {
                sort_loop = true;

                if(obj==1)
                {
                    crimper->update(event.button.x, event.button.y);
                    cout<<event.button.x<<","<<event.button.y;
                }

                else if(obj==2)
                {
                    jack->update(event.button.x, event.button.y);
                    cout<<event.button.x<<","<<event.button.y;
                }

                else if(obj == 3)
                {
                    if(*c == 1)
                    {
                        utp2->update(event.button.x, event.button.y);
                        cout<<event.button.x<<","<<event.button.y;
                    }
                    else
                    {
                        utp->update(event.button.x, event.button.y);
                        cout<<event.button.x<<","<<event.button.y;
                    }

                }

                else if(obj==4)
                {
                    bar_slider->destination.x=event.button.x;
                    cout<<event.button.x<<","<<event.button.y;
                    //need to add a condition that the slider can only slide between the specified area ie the bar

                }

            }

            else if(event.type==SDL_MOUSEBUTTONUP )
            {


                if((event.button.x>table.destination.x && event.button.x<table.destination.x+table.destination.w &&
                        event.button.y>table.destination.y && event.button.y<table.destination.y+table.destination.h) )
                {

                    if(obj == 1)
                    {
                        drag_drop=false;
                            run_loop=true;
                            *game=true;

                            *p = 2;


                    }
                    else if(obj == 2)
                    {
                        drag_drop=false;
                        run_loop=true;
                        *game=true;
                        *co = 1;

                    }

                    else if(obj == 3)
                    {
                        drag_drop=false;
                        run_loop = true;

                        *game=true;
                        *p = 1;

                    }
                    else if(obj == 4)
                    {
                        drag_drop=false;
                        run_loop= true;
                        *game=true;
                    }

                }

                else
                {
                    if(obj == 1)
                    {
                        crimper->destination.x = temp_x;
                        crimper->destination.y = temp_y;

                        cout<<"done"<<endl;
                        cout<<event.button.x<<event.button.y<<endl;

                        drag_drop=false;
                        run_loop=true;
                        *game=true;
                        //write this in another place another loop or main loop
                    }

                    else if(obj == 2)
                    {

                        jack->destination.x = temp_x;
                        jack->destination.y = temp_y;

                        cout<<"done"<<endl;
                        cout<<event.button.x<<event.button.y<<endl;
                        drag_drop=false;
                        run_loop=true;
                        *game=true;
                        *co = 1;

                    }

                    else if( obj == 3)
                    {

                        utp->destination.x = temp_x;
                        utp->destination.y = temp_y;

                        cout<<"done"<<endl;
                        cout<<event.button.x<<event.button.y<<endl;
                        drag_drop=false;
                        run_loop=true;
                        *game=true;
                        //write this in another place another loop or main loop
                    }



                    else if(obj == 4)
                    {

                        bar_slider->destination.x = temp_x;
                        bar_slider->destination.y = temp_y;

                        cout<<"done"<<endl;
                        cout<<event.button.x<<event.button.y<<endl;
                        drag_drop=false;
                        run_loop=true;
                        *game=true;

                    }
                }

            }

        }
        SDL_RenderClear(texture_renderer);
        table.render_media(texture_renderer);

        if(*c ==   1)
        {
            utp2->render_media(texture_renderer);
        }
        else
        {
            utp->render_media(texture_renderer);
        }

        jack->render_media(texture_renderer);
        crimper->render_media(texture_renderer);
        //bar.render_media(texture_renderer);
        //bar_slider->render_media(texture_renderer);

        SDL_RenderPresent(texture_renderer);

    }
}
