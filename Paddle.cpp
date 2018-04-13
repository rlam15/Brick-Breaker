#include "Paddle.h"
#include "App.h"
#include <cmath>

Paddle::Paddle()
{
	x = -.3; y = -.9; w = .6; h = .2, speed = .01;
	dX = 0; dY = 0;
}
void Paddle::draw()
{
	glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x,y-h);
    glVertex2f(x+w,y-h);
    glVertex2f(x+w,y);
    glEnd();
}
bool Paddle::checkCollision(Ball* b)
{
	float bX = b->getX(), bY = b->getY();
	if(bX>x&&bX<x+w&&bY<y&&bY>y-h)
	{
		float fac = bX-x;
		fac = fac/w;
		b->collide(M_PI-(M_PI*(fac)),y);
		// std::cout<<M_PI*fac<<std::endl;
	}
}
void Paddle::update(float x, float y)
{
	dX = x; dY = y;
}

void Paddle::update()
{
if(dX<=1&&dX>=-1){
	if(dX<x+(w/2))
		if(x>-1)
		{
			x-=speed;
		}
	if(dX>x+(w/2))
		if(x+w<1)
		{
			x+=speed;
		}
	}
}

void Paddle::update(char c)
{
	dX = -2;
	if(c == 'd' || c == 'D')
	{
		if(x+w<1)
		{
			x+=speed;
		}
	}
	else if(c=='a'||c=='A')
	{
		if(x>-1)
		{
			x-=speed;
		}
	}
}