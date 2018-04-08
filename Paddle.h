#ifndef PADDLE_H
#define PADDLE_H
// #include "App.h"
#include "Ball.h"

class Paddle
{
	float x, y, w, h, dX, dY, speed;
public:
	Paddle();
	void draw();
	bool checkCollision(Ball* b);
	void update(float x, float y);
	void update(char c);
};

#endif