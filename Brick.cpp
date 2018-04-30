#include "Brick.h"

Brick::Brick(float x, float y, float w, float h)
{
	this->x = x;
	this->y=y;
	this->w=w;
	this->h=h;
	hits=1;
}
Brick::Brick(float x, float y, float w, float h, int hp)
{
	this->x = x;
	this->y=y;
	this->w=w;
	this->h=h;
	hits=hp;
}
void Brick::draw()
{
	glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x,y-h);
    glVertex2f(x+w,y-h);
    glVertex2f(x+w,y);
    glEnd();
}
int Brick::inside(float i, float j)//outisde = 0, top/bottom = 1, l/r = 2
{
	if(i>=x&&i<=x+w&&j<=y&&j>=y-h)
		return 1;
	return -1;

}

float Brick::getX() const
{
	return x;
}

float Brick::getY() const
{
	return y;
}

float Brick::getW() const
{
	return w;
}

float Brick::getH() const
{
	return h;
}