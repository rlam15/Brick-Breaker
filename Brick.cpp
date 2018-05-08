#include "Brick.h"

Brick::Brick(float x, float y, float w, float h)
{
	this->x = x;
	this->y=y;
	this->w=w;
	this->h=h;
	hits=1;
    tex = new TexRect("gay", x, y, w, h);
	loadTex();
}
Brick::Brick(float x, float y, float w, float h, int hp)
{
	this->x = x;
	this->y=y;
	this->w=w;
	this->h=h;
	hits=hp;
    tex = new TexRect("fake", x, y, w, h);
	loadTex();
}

Brick::~Brick()
{
	delete tex;
}

void Brick::draw()
{
	// glBegin(GL_POLYGON);
 //    glVertex2f(x,y);
 //    glVertex2f(x,y-h);
 //    glVertex2f(x+w,y-h);
 //    glVertex2f(x+w,y);
 //    glEnd();
	tex->draw();
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

bool Brick::hit()
{
	hits--;
	return hits<=0;
}

void Brick::loadTex() 
{
	if(tex==NULL)
		return;

	delete tex;
	switch(hits)  
	{		
		case 2:
    	tex = new TexRect("Textures/blueSupreme.png", x, y, w, h);
		break;
		case 3:
    	tex = new TexRect("Textures/yellowSupreme.png", x, y, w, h);
		break;
		case 4:
	    tex = new TexRect("Textures/tealSupreme.png", x, y, w, h);
		break;
		case 5:
    	tex = new TexRect("Textures/greenSupreme.png", x, y, w, h);
		break;

		default:
    	tex = new TexRect("Textures/redSupreme.png", x, y, w, h);
		break;
	}
}
