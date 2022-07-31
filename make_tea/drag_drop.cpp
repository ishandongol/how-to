#include "make_tea.h"

void level1 ::click_loop(bool *main_game,level1 water,level1 milk,level1 pot,level1 sugar,level1 salt,level1 leaves,level1 soundleaves,
                         level1 *fire,SDL_Renderer *texture_renderer,level1 button1,
                         level1 background,level1 gas,level1 milkdrop,level1 waterdrop,level1 leavesdrop,int*p, int*temp_p){

*temp_p=*p;




    while(click){





            if(burner){

                        prevTime=currentTime;
                        currentTime=SDL_GetTicks();
                        deltaTime=(currentTime-prevTime)/1000.0f;
                        frameTime+=deltaTime;
                        if(frameTime>=0.2f){
                        frameTime=0;
                        fire->source.x+=140;
                        if(fire->source.x>=1260){
                        fire->source.x=0;
                }
                         SDL_RenderClear(texture_renderer);
                          //fire->render_gameplay1(texture_renderer);
                          background.render_gameplay1(texture_renderer);
                          gas.render_gameplay1(texture_renderer);
                          pot.render_gameplay1(texture_renderer);
                            if(check[2]!=2)
                            milk.render_gameplay1(texture_renderer);
                            if(check[5]!=5)
                            salt.render_gameplay1(texture_renderer);
                            if(check[4]!=4)
                            sugar.render_gameplay1(texture_renderer);
                            if(check[3]!=3)
                            water.render_gameplay1(texture_renderer);
                            if(check[6]!=6)
                            leaves.render_gameplay1(texture_renderer);
                            if(check[3]==3)
                            waterdrop.render_gameplay1(texture_renderer);
                            if(check[2]==2)
                            milkdrop.render_gameplay1(texture_renderer);
                            if(check[6]==6)
                            leavesdrop.render_gameplay1(texture_renderer);
                            fire->render_gameplay1(texture_renderer);
                            button1.render_gameplay1(texture_renderer);
                            // button1.render_gameplay1(texture_renderer);

                            SDL_RenderPresent(texture_renderer);



                        }


               }

               else if(x[10]==10)
               {
                SDL_RenderClear(texture_renderer);
                          //fire->render_gameplay1(texture_renderer);
                          background.render_gameplay1(texture_renderer);
                          gas.render_gameplay1(texture_renderer);
                          pot.render_gameplay1(texture_renderer);
                            if(check[2]!=2)
                            milk.render_gameplay1(texture_renderer);
                            if(check[5]!=5)
                            salt.render_gameplay1(texture_renderer);
                            if(check[4]!=4)
                            sugar.render_gameplay1(texture_renderer);
                            if(check[3]!=3)
                            water.render_gameplay1(texture_renderer);
                            if(check[6]!=6)
                            leaves.render_gameplay1(texture_renderer);
                            if(check[3]==3)
                            waterdrop.render_gameplay1(texture_renderer);
                            if(check[2]==2)
                            milkdrop.render_gameplay1(texture_renderer);
                            if(check[6]==6)
                            leavesdrop.render_gameplay1(texture_renderer);
                           // fire->render_gameplay1(texture_renderer);
                            button1.render_gameplay1(texture_renderer);
                            // button1.render_gameplay1(texture_renderer);

                            SDL_RenderPresent(texture_renderer);



               }

            while(SDL_PollEvent(&event)){
                     if(event.type==SDL_QUIT)
            {
                click=false;
                *main_game=false;
                *p=10;
            }

                                else if(event.type == SDL_KEYDOWN)
                        {
                            switch (event.key.keysym.sym)
                                {
                                case SDLK_ESCAPE:
                                    click=false;
                *main_game=false;
                *p=10;
                                    break;
                                case SDLK_SPACE:
                                    cout<<"Space hanyo"<<endl;
                                    x[10]=10;
                                    SDL_RenderClear(texture_renderer);
                        background.render_gameplay1(texture_renderer);
                        gas.render_gameplay1(texture_renderer);
                        pot.render_gameplay1(texture_renderer);
                        if(check[3]==3){
                        waterdrop.render_gameplay1(texture_renderer);}
                        if(check[2]==2){
                        milkdrop.render_gameplay1(texture_renderer);}
                        if(check[6]==6){
                        leavesdrop.render_gameplay1(texture_renderer);}

                        if(check[2]!=2){
                        milk.render_gameplay1(texture_renderer);
                        }
                        if(check[5]!=5){
                        salt.render_gameplay1(texture_renderer);}
                        if(check[4]!=4){
                        sugar.render_gameplay1(texture_renderer);}
                        if(check[3]!=3){
                        water.render_gameplay1(texture_renderer);}
                        if(check[6]!=6){
                        leaves.render_gameplay1(texture_renderer);}
                        button1.render_gameplay1(texture_renderer);


                        SDL_RenderPresent(texture_renderer);


                                    SDL_RenderClear(texture_renderer);

                                    pot.destination.x=800;pot.destination.y=500;
                                    pot.render_gameplay1(texture_renderer);


                                    milk.destination.x=100;milk.destination.y=90;
                                     milk.render_gameplay1(texture_renderer);

                                    water.destination.x=190;water.destination.y=90;
                                    water.render_gameplay1(texture_renderer);

                                    sugar.destination.x=280;sugar.destination.y=140;
                                    sugar.render_gameplay1(texture_renderer);

                                    salt.destination.x=370;salt.destination.y=140;
                                    salt.render_gameplay1(texture_renderer);

                                    leaves.destination.x=470;leaves.destination.y=120;
                                    leaves.render_gameplay1(texture_renderer);


                                    SDL_RenderPresent(texture_renderer) ;


                                    break;
                                }




                    }


                    if(event.type==SDL_QUIT){
                                *main_game=false;
                                 click = false;
                    }


                    else if(event.type==SDL_MOUSEBUTTONDOWN){
                        switch(event.button.button){
                            case SDL_BUTTON_LEFT:
                                if(event.button.x>water.destination.x && event.button.x<water.destination.x+water.destination.w && event.button.y>water.destination.y && event.button.y<water.destination.y+water.destination.h && check[1]==1 && lock!=1){ // check 1 le pot paila lock bhaysi matra move garauxa
                                    cout<<" water pressed"<<endl;
                                    cout<<"Click bhayo"<<endl;
                                     soundleaves.int_mixer();
                                     soundleaves.main_soundmus("resources/audio/4E.ogg");

                                        drag_drop= true;
                                        *main_game=true;
                                        click= false;
                                        temp=1;


                    }

                    if(event.button.x>milk.destination.x && event.button.x<milk.destination.x+milk.destination.w && event.button.y>milk.destination.y && event.button.y<milk.destination.y+milk.destination.h && check[1]==1 && lock!=1 ){
                                    cout<<" milk pressed"<<endl;
                                    soundleaves.int_mixer();
                                     soundleaves.main_soundmus("resources/audio/4E.ogg");


                                        drag_drop= true;
                                        *main_game=true;
                                        click= false;
                                        temp=2;



                    }

                    if(event.button.x>pot.destination.x && event.button.x<pot.destination.x+pot.destination.w && event.button.y>pot.destination.y && event.button.y<pot.destination.y+pot.destination.h && x[1]!=1  ){
                                    cout<<" pot pressed"<<endl;
                                    soundleaves.int_mixer();
                                     soundleaves.main_soundmus("resources/audio/4E.ogg");


                                        drag_drop= true;
                                        *main_game=true;
                                        click= false;
                                        temp=3;

                    }

                    if(event.button.x>sugar.destination.x && event.button.x<sugar.destination.x+sugar.destination.w && event.button.y>sugar.destination.y && event.button.y<sugar.destination.y+sugar.destination.h && check[1]==1  && lock!=1 ){
                                    cout<<" sugar pressed"<<endl;
                                    soundleaves.int_mixer();
                                     soundleaves.main_soundmus("resources/audio/4E.ogg");


                                        drag_drop= true;
                                        *main_game=true;
                                        click= false;
                                        temp=4;

                    }

                    if(event.button.x>salt.destination.x && event.button.x<salt.destination.x+salt.destination.w && event.button.y>salt.destination.y && event.button.y<salt.destination.y+salt.destination.h && check[1]==1  && lock!=1){
                                    cout<<" salt pressed"<<endl;
                                    soundleaves.int_mixer();
                                     soundleaves.main_soundmus("resources/audio/4E.ogg");


                                        drag_drop= true;
                                        *main_game=true;
                                        click= false;
                                        temp=5;

                    }
                        if(event.button.x>leaves.destination.x && event.button.x<leaves.destination.x+leaves.destination.w && event.button.y>leaves.destination.y && event.button.y<leaves.destination.y+leaves.destination.h && check[1]==1  && lock!=1){
                                    cout<<" leaves pressed"<<endl;
                                    soundleaves.int_mixer();
                                     soundleaves.main_soundmus("resources/audio/4E.ogg");


                                        drag_drop= true;
                                        *main_game=true;
                                        click= false;
                                        temp=6;

                    }






                     if(event.button.x>button1.destination.x && event.button.x<button1.destination.x+button1.destination.w && event.button.y>button1.destination.y && event.button.y<button1.destination.y+button1.destination.h ){

                        cout<<"button gas ko press bhayo"<<endl;
                            //burner=true;
                            drag_drop= true;
                            *main_game=true;
                            counter+=1;
                            lock=1;
                            if(counter == 1)
                            {
                                click=false;
                                burner=true;
                            }


                            else if(counter ==  2)
                            {
                                counter=0;
                                burner=false;
                                 SDL_RenderClear(texture_renderer);
                          fire->render_gameplay1(texture_renderer);
                          background.render_gameplay1(texture_renderer);
                          gas.render_gameplay1(texture_renderer);
                          pot.render_gameplay1(texture_renderer);
                          if(check[2]!=2)
                            milk.render_gameplay1(texture_renderer);
                            if(check[5]!=5)
                            salt.render_gameplay1(texture_renderer);
                            if(check[4]!=4)
                            sugar.render_gameplay1(texture_renderer);
                            if(check[3]!=3)
                            water.render_gameplay1(texture_renderer);
                            if(check[6]!=6)
                            leaves.render_gameplay1(texture_renderer);
                            if(check[3]==3)
                            waterdrop.render_gameplay1(texture_renderer);
                            if(check[2]==2)
                            milkdrop.render_gameplay1(texture_renderer);
                            if(check[6]==6)
                            leavesdrop.render_gameplay1(texture_renderer);

                            fire->render_gameplay1(texture_renderer);
                            button1.render_gameplay1(texture_renderer);
                            SDL_RenderPresent(texture_renderer);


                            }
                            click= false;

                     }









                        break;

                        }

                        }

            }




    }
}

void level1 :: drag_event(bool *main_game,level1 *water,level1 *milk,level1 *pot,level1 *sugar,level1 *salt,
                          level1 *leaves,SDL_Renderer *texture_renderer,level1 background,level1 gas,level1 waterdrop,
                          level1 milkdrop,level1 sound1,level1 sound2,level1 leavesdrop,level1 soundleaves,level1 image_done,level1 *fire,level1 button1){
     while(drag_drop){
               if(burner){
                        prevTime=currentTime;
                        currentTime=SDL_GetTicks();
                        deltaTime=(currentTime-prevTime)/1000.0f;
                        frameTime+=deltaTime;
                        if(frameTime>=0.2f){
                        frameTime=0;
                        fire->source.x+=140;
                        if(fire->source.x>=1260){
                        fire->source.x=0;
                }
                         SDL_RenderClear(texture_renderer);
                          //fire->render_gameplay1(texture_renderer);
                          background.render_gameplay1(texture_renderer);
                          gas.render_gameplay1(texture_renderer);
                          pot->render_gameplay1(texture_renderer);
                          if(check[2]!=2)
                            milk->render_gameplay1(texture_renderer);
                            if(check[5]!=5)
                            salt->render_gameplay1(texture_renderer);
                            if(check[4]!=4)
                            sugar->render_gameplay1(texture_renderer);
                            if(check[3]!=3)
                            water->render_gameplay1(texture_renderer);
                            if(check[6]!=6)
                            leaves->render_gameplay1(texture_renderer);
                            if(check[3]==3)
                            waterdrop.render_gameplay1(texture_renderer);
                            if(check[2]==2)
                            milkdrop.render_gameplay1(texture_renderer);
                            if(check[6]==6)
                            leavesdrop.render_gameplay1(texture_renderer);

                            fire->render_gameplay1(texture_renderer);
                            button1.render_gameplay1(texture_renderer);
                            image_done.render_gameplay1(texture_renderer);

                            SDL_RenderPresent(texture_renderer);



                        }

               }



       while(SDL_PollEvent(&event)){
            if(event.type==SDL_MOUSEMOTION){
             cout<<event.button.x<<","<<event.button.y<<endl;
                        if (temp== 2)//water
                        {
                            cout<<"motions"<<endl;
                            if(check[2]!=2){
                        milk->update(event.button.x, event.button.y);
                            }
                        SDL_RenderClear(texture_renderer);
                        background.render_gameplay1(texture_renderer);
                        gas.render_gameplay1(texture_renderer);
                        pot->render_gameplay1(texture_renderer);
                        if(check[2]!=2){
                        milk->render_gameplay1(texture_renderer);
                        if(check[3]!=3){
                        water->render_gameplay1(texture_renderer);}
                        if(check[3]==3){
                        waterdrop.render_gameplay1(texture_renderer);}
                        if(check[2]==2){
                        milkdrop.render_gameplay1(texture_renderer);}
                        if(check[6]==6){
                        leavesdrop.render_gameplay1(texture_renderer);}
                        }
                        if(check[5]!=5){
                        salt->render_gameplay1(texture_renderer);}
                        if(check[4]!=4){
                        sugar->render_gameplay1(texture_renderer);}
                        if(check[6]!=6){
                        leaves->render_gameplay1(texture_renderer);}
                        button1.render_gameplay1(texture_renderer);
                         if(burner)
                        fire->render_gameplay1(texture_renderer);


                        SDL_RenderPresent(texture_renderer);
                        }

                        else if (temp== 1)//water
                        {
                            cout<<"motions"<<endl;
                        water->update(event.button.x, event.button.y);
                        SDL_RenderClear(texture_renderer);
                        background.render_gameplay1(texture_renderer);
                        gas.render_gameplay1(texture_renderer);
                        pot->render_gameplay1(texture_renderer);
                        if(check[3]!=3){
                        water->render_gameplay1(texture_renderer);}
                        if(check[2]!=2){
                        milk->render_gameplay1(texture_renderer);}
                        if(check[3]==3){
                        waterdrop.render_gameplay1(texture_renderer);}
                        if(check[2]==2){
                        milkdrop.render_gameplay1(texture_renderer);}
                        if(check[6]==6){
                        leavesdrop.render_gameplay1(texture_renderer);}
                        if(check[5]!=5){
                        salt->render_gameplay1(texture_renderer);}
                        if(check[4]!=4){
                        sugar->render_gameplay1(texture_renderer);}
                        if(check[6]!=6){
                        leaves->render_gameplay1(texture_renderer);}
                         button1.render_gameplay1(texture_renderer);


                        SDL_RenderPresent(texture_renderer);
                        }
                        else if (temp== 3)//water
                        {
                            cout<<"motions"<<endl;
                        pot->update(event.button.x, event.button.y);
                        SDL_RenderClear(texture_renderer);
                        background.render_gameplay1(texture_renderer);
                        gas.render_gameplay1(texture_renderer);
                        pot->render_gameplay1(texture_renderer);
                        if(check[3]==3){
                        waterdrop.render_gameplay1(texture_renderer);}
                        if(check[2]==2){
                        milkdrop.render_gameplay1(texture_renderer);}
                        if(check[6]==6){
                        leavesdrop.render_gameplay1(texture_renderer);}
                        if(check[2]!=2){
                        milk->render_gameplay1(texture_renderer);}
                        if(check[5]!=5){
                        salt->render_gameplay1(texture_renderer);}
                        if(check[4]!=4){
                        sugar->render_gameplay1(texture_renderer);}
                        if(check[3]!=3){
                        water->render_gameplay1(texture_renderer);}
                        if(check[6]!=6){
                        leaves->render_gameplay1(texture_renderer);}
                         button1.render_gameplay1(texture_renderer);
                         if(burner)
                         fire->render_gameplay1(texture_renderer);


                        SDL_RenderPresent(texture_renderer);
                        }

                        else if (temp== 4)//water
                        {
                            cout<<"motions"<<endl;
                        sugar->update(event.button.x, event.button.y);
                        SDL_RenderClear(texture_renderer);
                        background.render_gameplay1(texture_renderer);
                        gas.render_gameplay1(texture_renderer);
                        pot->render_gameplay1(texture_renderer);
                        if(check[3]==3){
                        waterdrop.render_gameplay1(texture_renderer);}
                        if(check[2]==2){
                        milkdrop.render_gameplay1(texture_renderer);}
                        if(check[6]==6){
                        leavesdrop.render_gameplay1(texture_renderer);}
                        if(check[2]!=2){
                        milk->render_gameplay1(texture_renderer);}
                        if(check[5]!=5){
                        salt->render_gameplay1(texture_renderer);}
                        if(check[4]!=4){
                        sugar->render_gameplay1(texture_renderer);}
                        if(check[3]!=3){
                        water->render_gameplay1(texture_renderer);}
                        if(check[6]!=6){
                        leaves->render_gameplay1(texture_renderer);}
                         button1.render_gameplay1(texture_renderer);


                        SDL_RenderPresent(texture_renderer);
                        }

                        else if (temp== 5)//water
                        {
                            cout<<"motions"<<endl;
                        salt->update(event.button.x, event.button.y);
                        SDL_RenderClear(texture_renderer);
                        background.render_gameplay1(texture_renderer);
                        gas.render_gameplay1(texture_renderer);
                        pot->render_gameplay1(texture_renderer);
                        if(check[3]==3){
                        waterdrop.render_gameplay1(texture_renderer);}
                        if(check[2]==2){
                        milkdrop.render_gameplay1(texture_renderer);}
                        if(check[6]==6){
                        leavesdrop.render_gameplay1(texture_renderer);}
                        if(check[2]!=2){
                        milk->render_gameplay1(texture_renderer);}
                        if(check[5]!=5){
                        salt->render_gameplay1(texture_renderer);}
                        if(check[4]!=4){
                        sugar->render_gameplay1(texture_renderer);}
                        if(check[3]!=3){
                        water->render_gameplay1(texture_renderer);}
                        if(check[6]!=6){
                        leaves->render_gameplay1(texture_renderer);}
                         button1.render_gameplay1(texture_renderer);


                        SDL_RenderPresent(texture_renderer);
                        }

                        else if (temp== 6)//water
                        {
                            cout<<"motions"<<endl;
                        leaves->update(event.button.x, event.button.y);
                        SDL_RenderClear(texture_renderer);
                        background.render_gameplay1(texture_renderer);
                        gas.render_gameplay1(texture_renderer);
                        pot->render_gameplay1(texture_renderer);
                        if(check[3]==3){
                        waterdrop.render_gameplay1(texture_renderer);}
                        if(check[2]==2){
                        milkdrop.render_gameplay1(texture_renderer);}
                        if(check[6]==6){
                        leavesdrop.render_gameplay1(texture_renderer);}
                        if(check[2]!=2){
                        milk->render_gameplay1(texture_renderer);}
                        if(check[5]!=5){
                        salt->render_gameplay1(texture_renderer);}
                        if(check[4]!=4){
                        sugar->render_gameplay1(texture_renderer);}
                        if(check[3]!=3){
                        water->render_gameplay1(texture_renderer);}
                        if(check[6]!=6){
                        leaves->render_gameplay1(texture_renderer);}
                         button1.render_gameplay1(texture_renderer);


                        SDL_RenderPresent(texture_renderer);
                        }


       }

       else if(event.type == SDL_MOUSEBUTTONUP)
       {


           drag_drop=false;
           click=true;


           if(event.button.x>gas.destination.x &&event.button.y>gas.destination.y && event.button.x<(gas.destination.x+gas.destination.w) && event.button.y<(gas.destination.h+gas.destination.y) && temp==3)
           {
               drag_drop=false;
               click=true;

                   pot->update(343,546);
                   check[1]=1;
                   x[1]=1;

                        SDL_RenderClear(texture_renderer);
                        background.render_gameplay1(texture_renderer);
                        gas.render_gameplay1(texture_renderer);
                        pot->render_gameplay1(texture_renderer);
                        if(check[3]==3){
                        waterdrop.render_gameplay1(texture_renderer);}
                        if(check[2]==2){
                        milkdrop.render_gameplay1(texture_renderer);}
                        if(check[6]==6){
                        leavesdrop.render_gameplay1(texture_renderer);}
                        if(check[2]!=2){
                        milk->render_gameplay1(texture_renderer);
                        }
                        if(check[5]!=5){
                        salt->render_gameplay1(texture_renderer);}
                        if(check[4]!=4){
                        sugar->render_gameplay1(texture_renderer);}
                        water->render_gameplay1(texture_renderer);
                        if(check[6]!=6){
                        leaves->render_gameplay1(texture_renderer);}
                         button1.render_gameplay1(texture_renderer);





                        SDL_RenderPresent(texture_renderer);





           }

           if(event.button.x>gas.destination.x &&event.button.y>gas.destination.y && event.button.x<gas.destination.x+200 && event.button.y<gas.destination.y+100 && temp==2)
           {
               drag_drop=false;
               click=true;

                  // pot->update(343,546);
                   check[2]=2;//check value for milk
                    sound2.int_mixer();
                        sound2.main_soundmus("resources/audio/waterfalling.mp3");

                        SDL_RenderClear(texture_renderer);
                        background.render_gameplay1(texture_renderer);
                        gas.render_gameplay1(texture_renderer);
                        pot->render_gameplay1(texture_renderer);
                        if(check[3]==3){
                        waterdrop.render_gameplay1(texture_renderer);}
                        if(check[2]==2){
                        milkdrop.render_gameplay1(texture_renderer);}
                        if(check[6]==6){
                        leavesdrop.render_gameplay1(texture_renderer);}
                        //milk->render_gameplay1(texture_renderer);
                        if(check[5]!=5){
                        salt->render_gameplay1(texture_renderer);}
                        if(check[4]!=4){
                        sugar->render_gameplay1(texture_renderer);}
                        if(check[3]!=3){
                        water->render_gameplay1(texture_renderer);}
                        if(check[6]!=6){
                        leaves->render_gameplay1(texture_renderer);}
                        button1.render_gameplay1(texture_renderer);


                        SDL_RenderPresent(texture_renderer);
                        sound2.int_mixer();
                        sound2.main_soundmus("resources/audio/waterfalling.mp3");



           }

           if(event.button.x>gas.destination.x &&event.button.y>gas.destination.y && event.button.x<gas.destination.x+200 && event.button.y<gas.destination.y+100 && temp==1)
           {
               drag_drop=false;
               click=true;
                sound2.int_mixer();
                sound2.main_soundmus("resources/audio/waterfalling.mp3");

                  // pot->update(343,546);
                   check[3]=3;//check value for water

                        SDL_RenderClear(texture_renderer);
                        background.render_gameplay1(texture_renderer);
                        gas.render_gameplay1(texture_renderer);
                        pot->render_gameplay1(texture_renderer);
                        if(check[3]==3){
                        waterdrop.render_gameplay1(texture_renderer);}
                        if(check[2]==2){
                        milkdrop.render_gameplay1(texture_renderer);}
                        if(check[6]==6){
                        leavesdrop.render_gameplay1(texture_renderer);}
                        if(check[2]!=2){
                        milk->render_gameplay1(texture_renderer);}
                        if(check[5]!=5){
                        salt->render_gameplay1(texture_renderer);}
                        if(check[4]!=4){
                        sugar->render_gameplay1(texture_renderer);}
                        //water->render_gameplay1(texture_renderer);
                        if(check[6]!=6){
                        leaves->render_gameplay1(texture_renderer);}
                        button1.render_gameplay1(texture_renderer);


                        SDL_RenderPresent(texture_renderer);
                        sound2.int_mixer();
                        sound2.main_soundmus("resources/audio/waterfalling.mp3");

           }

           if(event.button.x>gas.destination.x &&event.button.y>gas.destination.y && event.button.x<gas.destination.x+200 && event.button.y<gas.destination.y+100 && temp==4)
           {
               drag_drop=false;
               click=true;

                  // pot->update(343,546);
                   check[4]=4;//check value for sugar

                        SDL_RenderClear(texture_renderer);
                        background.render_gameplay1(texture_renderer);
                        gas.render_gameplay1(texture_renderer);
                        pot->render_gameplay1(texture_renderer);
                        if(check[3]==3){
                        waterdrop.render_gameplay1(texture_renderer);}
                        if(check[2]==2){
                        milkdrop.render_gameplay1(texture_renderer);}
                        if(check[6]==6){
                        leavesdrop.render_gameplay1(texture_renderer);}
                        if(check[2]!=2){
                        milk->render_gameplay1(texture_renderer);}
                        if(check[5]!=5){
                        salt->render_gameplay1(texture_renderer);}
                        //sugar->render_gameplay1(texture_renderer);
                        if(check[3]!=3){
                        water->render_gameplay1(texture_renderer);}
                        if(check[6]!=6){
                        leaves->render_gameplay1(texture_renderer);}
                        button1.render_gameplay1(texture_renderer);


                        SDL_RenderPresent(texture_renderer);



           }

           if(event.button.x>gas.destination.x &&event.button.y>gas.destination.y && event.button.x<gas.destination.x+200 && event.button.y<gas.destination.y+100 && temp==5)
           {
               drag_drop=false;
               click=true;

                  // pot->update(343,546);
                   check[5]=5;//check value for salt

                        SDL_RenderClear(texture_renderer);
                        background.render_gameplay1(texture_renderer);
                        gas.render_gameplay1(texture_renderer);
                        pot->render_gameplay1(texture_renderer);
                        if(check[3]==3){
                        waterdrop.render_gameplay1(texture_renderer);}
                        if(check[2]==2){
                        milkdrop.render_gameplay1(texture_renderer);}
                        if(check[6]==6){
                        leavesdrop.render_gameplay1(texture_renderer);}
                        if(check[2]!=2){
                        milk->render_gameplay1(texture_renderer);}
                        //salt->render_gameplay1(texture_renderer);
                        if(check[4]!=4){
                        sugar->render_gameplay1(texture_renderer);}
                        if(check[3]!=3){
                        water->render_gameplay1(texture_renderer);}
                        if(check[6]!=6){
                        leaves->render_gameplay1(texture_renderer);}
                        button1.render_gameplay1(texture_renderer);


                        SDL_RenderPresent(texture_renderer);

           }

           if(event.button.x>gas.destination.x &&event.button.y>gas.destination.y && event.button.x<gas.destination.x+200 && event.button.y<gas.destination.y+100 && temp==6)
           {
               drag_drop=false;
               click=true;

                  // pot->update(343,546);
                   check[6]=6;//check value for tealeaves

                        SDL_RenderClear(texture_renderer);
                        background.render_gameplay1(texture_renderer);
                        gas.render_gameplay1(texture_renderer);
                        pot->render_gameplay1(texture_renderer);
                        if(check[3]==3){
                        waterdrop.render_gameplay1(texture_renderer);}
                        if(check[2]==2){
                        milkdrop.render_gameplay1(texture_renderer);}
                        if(check[6]==6){
                        leavesdrop.render_gameplay1(texture_renderer);}
                        if(check[2]!=2){
                        milk->render_gameplay1(texture_renderer);}
                        if(check[5]!=5){
                        salt->render_gameplay1(texture_renderer);}
                        if(check[4]!=4){
                        sugar->render_gameplay1(texture_renderer);}
                        if(check[3]!=3){
                        water->render_gameplay1(texture_renderer);}
                        button1.render_gameplay1(texture_renderer);



                        //leaves->render_gameplay1(texture_renderer);
                        SDL_RenderPresent(texture_renderer);
                        soundleaves.int_mixer();
                       // soundleaves.main_soundmus("resources/audio/4E.ogg");


           }

                        if(check[1]==1 && lock==1)
                        {
                            for(int a=0; a<10000; a++)
                                cout<<"....."<<endl;
                        cout<<"Ready to make tea..:D"<<endl;
                        cout<<"Texture is locked"<<endl;

                        if(check[2]==2 && check[3]==3 && check[4]==4 &&check[6]==6 &&check[5]!=5){
                            cout<<"Correctly made"<<endl;
                        SDL_RenderClear(texture_renderer);
                        image_done.render_gameplay1(texture_renderer);
                        background.render_gameplay1(texture_renderer);
                        gas.render_gameplay1(texture_renderer);
                        pot->render_gameplay1(texture_renderer);
                        if(check[3]==3){
                        waterdrop.render_gameplay1(texture_renderer);}
                        if(check[2]==2){
                        milkdrop.render_gameplay1(texture_renderer);}
                        if(check[6]==6){
                        leavesdrop.render_gameplay1(texture_renderer);}
                        if(check[2]!=2){
                        milk->render_gameplay1(texture_renderer);}
                        if(check[5]!=5){
                        salt->render_gameplay1(texture_renderer);}
                        if(check[4]!=4){
                        sugar->render_gameplay1(texture_renderer);}
                        if(check[3]!=3){
                        water->render_gameplay1(texture_renderer);}
                        if(check[6]!=6)
                        leaves->render_gameplay1(texture_renderer);
                        image_done.render_gameplay1(texture_renderer);
                        button1.render_gameplay1(texture_renderer);
                        image_done.render_gameplay1(texture_renderer);



                        SDL_RenderPresent(texture_renderer);
                        }
                        else
                        {
                           cout<<"Level failed"<<endl;
                        }







                        }










       }
     }
     }
}









