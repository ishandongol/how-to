#ifndef __Crimp__
#define __Crimp__


#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<iostream>
#include<SDL_mixer.h>

using namespace std;

class crimp
{
protected:




    SDL_Texture *texture=NULL;
    SDL_Surface *surface=NULL;

    int temp_x=0, temp_y=0;
    SDL_Event event;
    //const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    int obj=0;


public:
    bool running=true;
    bool drag_drop=false;
    bool game=true;
    bool run_loop = true;
    bool sort_loop = true;
    bool crimp_loop = true;
float prevTime=0 , currentTime=0, deltaTime = 0, frameTime = 0;



    SDL_Rect source, destination;
    void load_media(SDL_Renderer*, const char*, int , int );
    void render_media(SDL_Renderer *);
    void running_loop(SDL_Renderer*, bool *, crimp , crimp , crimp , crimp, crimp, crimp, crimp*/*made pointer*/, int*,int*,int*, crimp, int*, int*);
    void drag_loop(bool *,crimp*, crimp*, crimp*,crimp* ,crimp*, SDL_Renderer*, crimp, crimp, int*,int*,int*);
    void update(int, int);
    void wire_sort( SDL_Renderer*, bool *,  /*crimp*, crimp*, crimp*, crimp*, crimp*, crimp*,crimp*,crimp*,*/ int*, crimp, crimp, crimp, crimp,int*, int*, crimp type1, crimp type2);
    void final_crimp(SDL_Renderer*, bool *,int*, crimp, crimp, crimp, crimp*,int*,int*);

};
#endif // __Game__

