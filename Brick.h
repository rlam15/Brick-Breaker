#ifndef BRICK_H
#define BRICK_H
#include "GlutApp.h"

class Brick
{
	float x,y,w,h;
	int hits;
public:
	Brick(float x, float y, float w, float h);
	Brick(float x, float y, float w, float h, int hp);
	void draw();
	int inside(float i, float j);
	float getX() const;
	float getY() const;
	float getW() const;
	float getH() const;

};

#endif