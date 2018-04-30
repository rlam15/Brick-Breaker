#ifndef BALL_H
#define BALL_H
#include "Brick.h"

class Ball
{
	float x, y, theta, vel;
public:
	Ball(float x, float y);
	Ball(float x, float y, float vel);
	void move();
	void draw();
	void collide(float theta,float y);
	bool collide(Brick *b);
	float getX() const;
	float getY() const;
	float getTheta() const;
	void setVel(float vel);
};

#endif