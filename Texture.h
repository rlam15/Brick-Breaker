#ifndef Texture_h
#define Texture_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "RgbImage.h"
#include <string>
#include "Ball.h"
#include "Paddle.h"

class Texture
{
public:
	float x;
	float y;
	float w;
	float h;
	int rows;
	int cols;
	GLuint texture_id;


	Texture(const char*,int,int,float,float,float,float);

	void draw();
	
	void advance(); //used for animations

	void updateTexture(); //once object moves, we update the postition	
};

#endif