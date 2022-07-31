
#ifndef __Game__
#define __Game__
//-----------------------------------------------------------------------------
//includes ------- SDL2 --------- CPP-------------------------------
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include<iostream>
//--------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------
class buttons;
class MAINMenu{
public:

    SDL_Rect source, destination;
    SDL_Texture *texture;
    bool howto;
    bool help_run;
    bool options_run;
    bool credits_run;
    bool quit_run;
    bool user_knows;
    void load(SDL_Renderer*, const char*, int x, int y);
    void render(SDL_Renderer*);
    void events(SDL_Renderer*,buttons,buttons,buttons,buttons,buttons,buttons,MAINMenu,MAINMenu,MAINMenu,int*, float, int, int, float,float, MAINMenu *, MAINMenu *,bool*,MAINMenu*);
    void event_drag(SDL_Renderer *,buttons,buttons,buttons,buttons,buttons,MAINMenu,MAINMenu,MAINMenu,int*,float, int, int, float,float, MAINMenu*, MAINMenu *,bool*,MAINMenu*);
    void update(int,int);
    void free_resources();
    bool main_event;
    bool drag_run;

    MAINMenu(){
        main_event=true;
        user_knows=false;
    }
   ~MAINMenu(){

    }



protected:

    SDL_Surface *surface;

    SDL_Event event;
    int temp_x,temp_y;


};
class buttons : public MAINMenu{
public:
    int counter;
    void load(SDL_Renderer*, const char*, int x, int y, TTF_Font*,TTF_Font*,SDL_Color, SDL_Color);
    void load_no_outline(SDL_Renderer *,const char*,int ,int , TTF_Font*,SDL_Color );
    void render_no_outline(SDL_Renderer *);
    void render(SDL_Renderer*);
    void free_resources();
    /*~buttons(){
        free_resources();
    }*/
    //void event_drag(SDL_Renderer *);
protected:
    SDL_Rect outline_source, outline_destination;
    SDL_Texture *outline_texture;



};
class subMENU1 : public MAINMenu{
public:
    void events(buttons, buttons, buttons, buttons,int *);

    bool sub_event;
    /*~subMENU1(){
    free_resources();
    }*/

    //void event_drag(SDL_Renderer *);

};
class subMENU2 : public subMENU1{
public:
    void events(int*);
    /* ~subMENU2(){
    free_resources();
    }*/

};
class subMENU3 : public subMENU1{
public:
    void events(int*, buttons,buttons);
    void drag_event(SDL_Renderer*, buttons*, buttons*, bool*,bool*,MAINMenu,buttons,buttons,buttons,buttons,subMENU3,subMENU3);
    /* ~subMENU3(){
    free_resources();
    }*/
    //void event_drag(SDL_Renderer *);
protected:
    bool sub_drag;
    int opt;

};
class subMENU4 : public subMENU1{
public:
    void events(int*);
    /* ~subMENU4(){
    free_resources();
    }*/
    //void event_drag(SDL_Renderer *);

};
class subMENU5 : public subMENU1{
public:
    void events(int*,bool*,buttons,buttons);
    void events2(int*,bool*,buttons,buttons,int*);
    /*~subMENU5(){
    free_resources();
    }*/
    //void event_drag(SDL_Renderer *);


};
class sounds : public MAINMenu{
public:
    sounds(){
        init_mixer();

    }
    ~sounds(){
        Mix_FreeChunk(sound);
        Mix_CloseAudio();
        cout<<"done"<<endl;
    }
    void init_mixer(){
            Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,2,4096);
    };
    void main_s(const char* url){
sound=Mix_LoadWAV(url);
   //music= Mix_LoadMUS("resources/audio/test.mp3");
    //Mix_FadeInMusic(music,-1,2000);
  Mix_FadeInChannel(-1,sound,-1,2000);
    };
    void pause_sound(){
        Mix_Pause(-1);
    };
     void resume_sound(){
        Mix_Resume(-1);
    };
    void volume();
protected:
    Mix_Chunk *sound;

};




#endif /* defined(__Game__) */
