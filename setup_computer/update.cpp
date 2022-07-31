#include "Header.h"

void obj :: update( int x,int y)
{
    cout<<"Running"<<endl;
    this->dest.x=x-this->dest.w/2;
	this->dest.y = y - this->dest.h / 2;
}
