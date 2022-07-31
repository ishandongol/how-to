#ifndef __comp__
#define __comp__

#include<string>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include<iostream>

using namespace std;

class obj;
class obj
{
public:
	void load_texture(SDL_Renderer *, const char*, int, int);
	void rendering(SDL_Renderer *);
	void click_check(bool *,obj, obj, obj, obj, obj, obj, obj, obj, obj, obj, SDL_Renderer*,int*,int*);
	void drag_event(bool *, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, obj*, SDL_Renderer*);
	void update(int x, int y);
	void check(obj*, obj*, obj*, obj*, obj*);
	SDL_Rect source, dest;
	float frameTime=0, currentTime=0, deltaTime, prevTime;
bool click = true;
	bool drag_drop = false;
protected:
	SDL_Surface *surface;
	SDL_Texture *texture1;
	int temp = 0;
	SDL_Event ev;

	int chk[10];
	bool sprite = false;
	int x[10];
};


#endif // __comp__
