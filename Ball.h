#ifndef BALL_H
#define BALL_H

class Ball
{
	float x, y, theta, vel;
public:
	Ball(float x, float y);
	Ball(float x, float y, float vel);
	void move();
	void draw();
	void collide(float theta,float y);
	float getX() const;
	float getY() const;
	void setVel(float vel);
};

#endif