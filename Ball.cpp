#include "Ball.h"
#include <cmath>
#include <stdio.h>
#include "App.h"

Ball::Ball(float x, float y)
{
	this->x = x;
	this->y = y;
	vel = .01;
	tex = new TexRect("Textures/jesus.png", x-0.015, y+0.015, 0.03, 0.03);
	theta = (M_PI/3)+static_cast<float>(rand()/static_cast<float>(RAND_MAX));//probably change to random 1-pi
}


Ball::Ball(float x, float y, float vel)
{
	this->x = x;
	this->y = y;
	this->vel = vel;
	theta= (M_PI/3)+static_cast<float>(rand()/static_cast<float>(RAND_MAX));

	tex = new TexRect("Textures/jesus.png", x-0.015, y+0.015, 0.03, 0.03);
	// std::cout<<theta<<std::endl;
}

Ball::~Ball() {
	delete tex;
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
	tex->idle(x-.015,y+.015);
}

void Ball::draw()
{
	// glBegin(GL_POINTS);
 //    glVertex2f(x, y);
 //    glEnd();
	tex -> draw();
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

bool Ball::collide(Brick* b)
{
	float bX = b->getX();
	float bY = b->getY();
	float bW = b->getW();
	float bH = b->getH();
	if(x>=bX&&x<=bX+bW&&y<=bY&&y>=bY-bH)
	{
		theta = -theta;
		// vel = -vel;
		return 1;
	}
	return 0;
}

float Ball::getX() const
{
	return x;
}

float Ball::getY() const
{
	return y;
}

float Ball::getTheta() const
{
	return theta;
}

void Ball::setVel(float vel)
{
	this->vel = vel;
}