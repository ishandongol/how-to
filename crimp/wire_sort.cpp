#include "crimp.h"


void crimp :: wire_sorting(SDL_Renderer *texture_renderer,bool *game, crimp table, crimp *w_br,crimp *w_brw,crimp *w_b, crimp *w_bw, crimp *w_g, crimp *w_gw, crimp *w_o, crimp *w_ow,  int* p, crimp st_through, crimp crossover, crimp utp_big )
{
  while(run_loop)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT)
            {
                drag_drop=false;
                *game=false;
            }

            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                switch(event.button.button)
                {
                case SDL_BUTTON_LEFT:

                    if(event.button.x>w_b->destination.x && event.button.x<w_b->destination.x+w_b->destination.w &&
                            event.button.y>w_b->destination.y && event.button.y<w_b->destination.y+w_b->destination.h)
                    {

                        cout<<"pressed"<<endl;
                        obj=5;
                        //temp_x = w_b.destination.x;
                        temp_y = w_b->destination.y;

                        drag_drop=true;
                        running=false;
                        *game=true;
                    }

                    else if(event.button.x>w_g->destination.x && event.button.x<w_g->destination.x+w_g->destination.w &&
                            event.button.y>w_g->destination.y && event.button.y<w_g->destination.y+w_g->destination.h)
                    {

                        cout<<"pressed"<<endl;
                        obj=6;
                        //temp_x = w_g.destination.x;
                        temp_y = w_g->destination.y;

                        drag_drop=true;
                        running=false;
                        *game=true;
                    }

                    else if(event.button.x>w_ow->destination.x && event.button.x<w_ow->destination.x+w_ow->destination.w &&
                            event.button.y>w_ow->destination.y && event.button.y<w_ow->destination.y+w_ow->destination.h)
                    {

                        cout<<"pressed"<<endl;
                        obj=7;
                        //temp_x = w_ow.destination.x;
                        temp_y = w_ow->destination.y;

                        drag_drop=true;
                        running=false;
                        *game=true;
                    }
                    else if(event.button.x>w_br->destination.x && event.button.x<w_br->destination.x+w_br->destination.w &&
                            event.button.y>w_br->destination.y && event.button.y<w_br->destination.y+w_br->destination.h)
                    {

                        cout<<"pressed"<<endl;
                        obj=8;
                        //temp_x = w_br.destination.x;
                        temp_y = w_br->destination.y;

                        drag_drop=true;
                        running=false;
                        *game=true;
                    }
                    else if(event.button.x>w_o->destination.x && event.button.x<w_o->destination.x+w_o->destination.w &&
                            event.button.y>w_o->destination.y && event.button.y<w_o->destination.y+w_o->destination.h)
                    {

                        cout<<"pressed"<<endl;
                        obj=9;
                        //temp_x = w_o.destination.x;
                        temp_y = w_o->destination.y;

                        drag_drop=true;
                        running=false;
                        *game=true;
                    }
                    else if(event.button.x>w_brw->destination.x && event.button.x<w_brw->destination.x+w_brw->destination.w &&
                            event.button.y>w_brw->destination.y && event.button.y<w_brw->destination.y+w_brw->destination.h)
                    {

                        cout<<"pressed"<<endl;
                        obj=10;
                       // temp_x = w_brw.destination.x;
                        temp_y = w_brw->destination.y;

                        drag_drop=true;
                        running=false;
                        *game=true;
                    }
                    else if(event.button.x>w_bw->destination.x && event.button.x<w_bw->destination.x+w_bw->destination.w &&
                            event.button.y>w_bw->destination.y && event.button.y<w_bw->destination.y+w_bw->destination.h)
                    {int page = 0;

                        cout<<"pressed"<<endl;
                        obj=11;
                        //temp_x = w_bw.destination.x;
                        temp_y = w_bw->destination.y;

                        drag_drop=true;
                        running=false;
                        *game=true;
                    }
                    else if(event.button.x>w_gw->destination.x && event.button.x<w_gw->destination.x+w_gw->destination.w &&
                            event.button.y>w_gw->destination.y && event.button.y<w_gw->destination.y+w_gw->destination.h)
                    {

                        cout<<"pressed"<<endl;
                        obj=12;
                        //temp_x = w_gw.destination.x;
                        temp_y = w_gw->destination.y;

                        drag_drop=true;
                        running=false;
                        *game=true;
                    }
                    break;
                }
            }

            else if(event.type==SDL_MOUSEMOTION)
            {

                    if(obj==5)
                    {
                        w_b->update(event.button.x, event.button.y);

                    }
                     else if(obj==6)
                    {
                        w_g->update(event.button.x, event.button.y);

                    }
                     else if(obj==7)
                    {
                        w_ow->update(event.button.x, event.button.y);

                    }
                     else if(obj==8)
                    {
                        w_br->update(event.button.x, event.button.y);

                    }
                     else if(obj==9)
                    {
                        w_o->update(event.button.x, event.button.y);

                    }
                     else if(obj==10)
                    {
                        w_brw->update(event.button.x, event.button.y);

                    }
                     else if(obj==11)
                    {
                        w_bw->update(event.button.x, event.button.y);

                    }
                     else if(obj==12)
                    {
                        w_gw->update(event.button.x, event.button.y);

                    }
                    SDL_RenderClear(texture_renderer);

            //table.render_media(texture_renderer);
            w_br->render_media(texture_renderer);
            w_brw->render_media(texture_renderer);
            w_b->render_media(texture_renderer);
            w_bw->render_media(texture_renderer);
            w_g->render_media(texture_renderer);
            w_gw->render_media(texture_renderer);
            w_o->render_media(texture_renderer);
            w_ow->render_media(texture_renderer);
            st_through.render_media(texture_renderer);
            crossover.render_media(texture_renderer);
            utp_big.render_media(texture_renderer);
            SDL_RenderPresent(texture_renderer);
            }

            else if(event.type==SDL_MOUSEBUTTONUP )
            {


                if((event.button.x>table.destination.x && event.button.x<table.destination.x+table.destination.w &&
                        event.button.y>table.destination.y && event.button.y<table.destination.y+table.destination.h) )
                {

                        if(obj == 5)
                        {
                            run_loop=false;
                            running=true;
                            *game=true;
                            //*p = 5;
                        }
                        if(obj == 6)
                        {
                            run_loop=false;
                            running=true;
                            *game=true;
                            //*p = 6;
                        }
                        else if(obj == 7)
                        {
                            run_loop=false;
                            running=true;
                            *game=true;
                            //*p = 7;
                        }
                        else if(obj == 8)
                        {
                            run_loop=false;
                            running=true;
                            *game=true;
                            //*p = 1;
                        }
                        else if(obj == 9)
                        {
                            run_loop=false;
                            running=true;
                            *game=true;
                            //*p =9;
                        }
                        else if(obj == 10)
                        {
                            run_loop=false;
                            running=true;
                            *game=true;
                            //*p = 10;
                        }
                        else if(obj == 11)
                        {
                            run_loop=false;
                            running=true;
                            *game=true;
                           // *p = 11;
                        }
                        else if(obj == 12)
                        {
                            run_loop=false;
                            running=true;
                            *game=true;
                            //*p = 12;
                        }
                        SDL_RenderClear(texture_renderer);

            //table.render_media(texture_renderer);
            w_br->render_media(texture_renderer);
            w_brw->render_media(texture_renderer);
            w_b->render_media(texture_renderer);
            w_bw->render_media(texture_renderer);
            w_g->render_media(texture_renderer);
            w_gw->render_media(texture_renderer);
            w_o->render_media(texture_renderer);
            w_ow->render_media(texture_renderer);
            st_through.render_media(texture_renderer);
            crossover.render_media(texture_renderer);
            utp_big.render_media(texture_renderer);
            SDL_RenderPresent(texture_renderer);

                }
/*
                else
                {
                    if(obj == 1)
                    {
                        crimper->destination.x = temp_x;
                        crimper->destination.y = temp_y;

                        cout<<"done"<<endl;
                        cout<<event.button.x<<event.button.y<<endl;

                        drag_drop=false;
                        running=true;
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
                        running=true;
                        *game=true;


                    }
*/

                }
            /*}
            SDL_RenderClear(texture_renderer);

            //table.render_media(texture_renderer);
            w_br->render_media(texture_renderer);
            w_brw->render_media(texture_renderer);
            w_b->render_media(texture_renderer);
            w_bw->render_media(texture_renderer);
            w_g->render_media(texture_renderer);
            w_gw->render_media(texture_renderer);
            w_o->render_media(texture_renderer);
            w_ow->render_media(texture_renderer);
            st_through.render_media(texture_renderer);
            crossover.render_media(texture_renderer);
            utp_big.render_media(texture_renderer);
            SDL_RenderPresent(texture_renderer);
}

*/


        }
            SDL_RenderClear(texture_renderer);

            //table.render_media(texture_renderer);
            w_br->render_media(texture_renderer);
            w_brw->render_media(texture_renderer);
            w_b->render_media(texture_renderer);
            w_bw->render_media(texture_renderer);
            w_g->render_media(texture_renderer);
            w_gw->render_media(texture_renderer);
            w_o->render_media(texture_renderer);
            w_ow->render_media(texture_renderer);
            st_through.render_media(texture_renderer);
            crossover.render_media(texture_renderer);
            utp_big.render_media(texture_renderer);
            SDL_RenderPresent(texture_renderer);
    }
     SDL_Delay(10);
}

/*while(drag_drop)
{

        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT)
            {
                drag_drop=false;
                *game=false;
            }             */


