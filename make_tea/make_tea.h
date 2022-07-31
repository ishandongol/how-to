#ifndef __Make_tea__
#define __Make_tea__

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include<iostream>

using namespace std;

class level1;
class level1{

 public:
     void load_image(SDL_Renderer *, const char*, int, int);
     void render_gameplay1(SDL_Renderer *);

     void click_loop(bool * ,level1,level1,level1,level1,level1,level1,level1,level1 *,SDL_Renderer *,level1,level1,level1,level1,level1,level1,int *p, int*temp_p);


     void drag_event(bool * ,level1*,level1*,level1*,level1*,level1*,level1*,
                     SDL_Renderer*,level1,level1,level1,level1,
                     level1,level1,level1,level1,level1,level1 *,level1);



        void update(int , int );
     SDL_Rect source,destination;
      int temp_x,temp_y;
      int i=0;
      bool burner;
      int startx[10],starty[10];


void int_mixer(){
                Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,2,4096);

}

void main_soundwav(const char *url){
        sound=Mix_LoadWAV(url);
        Mix_FadeInChannel(-1,sound,-1,2000);
        Mix_PlayMusic(music,-1);
            }


void main_soundmus(const char *url){
    music=Mix_LoadMUS(url);
    Mix_FadeInChannel(-1,sound,-1,2000);
    Mix_PlayMusic(music,1);
            }
 bool click=true;
 protected:
    SDL_Surface *surface;
    SDL_Texture *texture;
    Mix_Chunk *sound=NULL;
    Mix_Music *music=NULL;
    int temp=0;
    SDL_Event event;

    bool drag_drop= false;
    int x[10];
    int check[10]={0,0,0,0,0,0,0,0,0,0};
    int prevTime=0,currentTime=0;
    float frameTime,deltaTime;
    int counter=0;
    int test=0;
    int lock=0;






 };




#endif // __Make_tea__
