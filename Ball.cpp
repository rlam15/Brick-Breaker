#include "Ball.h"
#include <cmath>
#include "App.h"

Ball::Ball(float x, float y)
{
	this->x = x;
	this->y = y;
	vel = .01;
	theta = M_PI/3;//probably change to random 1-pi
}


Ball::Ball(float x, float y, float vel)
{
	this->x = x;
	this->y = y;
	this->vel = vel;
	theta= M_PI/3;
}

void Ball::move()
{
	x += vel*cos(theta);
	y += vel*sin(theta);
	if(x>1||x<-1)
	{
		theta = theta *-1;
		vel = vel * -1;
		if(x>1)
			x=1;
		else
			x=-1;
	}
	// std::cout<<y<<std::endl;
	if(y>1/*||y<-1*/)
	{

		theta = theta * -1;
		if(y>1)
			y=1;
		// else
		// 	y=-1;
	}
}

void Ball::draw()
{
	glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}


void Ball::collide(float theta, float y)
{
	if(theta>=0&&theta<=M_PI)
	{
		this->theta = theta;
		vel = fabs(vel);
		this->y = y;
	}
	else
		theta = -theta;
}

// void Ball::collide(Brick* b)
// {

// }

float Ball::getX() const
{
	return x;
}

float Ball::getY() const
{
	return y;
}

void Ball::setVel(float vel)
{
	this->vel = vel;
}