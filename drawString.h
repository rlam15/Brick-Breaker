#ifndef DRAWSTRING_H
#define DRAWSTRING_H
#include "App.h"

// const void* font =GLUT_BITMAP_TIMES_ROMAN_10;
//this file is a test, seems to not work as i thought
void drawString(char s, float x, float y)
{
	glRasterPos2f(x,y);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,s);
}

#endif