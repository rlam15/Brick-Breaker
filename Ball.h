#ifndef BALL_H
#define BALL_H

class Ball
{
	float x, y, theta, vel;
public:
	Ball(int x, int y);
	void move();
	void draw();
	void collide(float theta,float y);
	float getX() const;
	float getY() const;
};

#endif