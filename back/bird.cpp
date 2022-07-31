#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
using namespace std;
SDL_Window *window=NULL;
    SDL_Renderer *texture_renderer=NULL;
    int win_w=1200;
    int win_h=675;
    float frameTime=0;
    int prevTime=0;
    int currentTime=0;
    float deltaTime=0;
int main(){
window=SDL_CreateWindow("How TO (Kasari Ta) 1.0 (BETA)",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,win_w,win_h,SDL_WINDOW_SHOWN);

prevTime=currentTime;
        currentTime=SDL_GetTicks();
        deltaTime=(currentTime-prevTime)/1000.0f;
        frameTime+=deltaTime;
            if(frameTime>=0.02f){
                frameTime=0;
                clouds->destination.x-=1;
                if(clouds->destination.x==-(clouds->destination.w)){
                    clouds->destination.x=1200;
                }
return 0;

}
