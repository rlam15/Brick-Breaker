#ifndef BRICK_H
#define BRICK_H
#include "GlutApp.h"
#include "TexRect.h"

class Brick
{
	float x,y,w,h;
	int hits;
	TexRect *tex;
public:
	Brick(float x, float y, float w, float h);
	Brick(float x, float y, float w, float h, int hp);
	~Brick();
	void draw();
	int inside(float i, float j);
	float getX() const;
	float getY() const;
	float getW() const;
	float getH() const;
	bool hit();
	void loadTex();

};

#endif