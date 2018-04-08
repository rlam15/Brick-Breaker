#ifndef GAME_H
#define GAME_H
// #include "App.h"
#include "keyboardHandler.h"
#include "Ball.h"
#include "Paddle.h"
// #include "Brick.h"
#include <vector>

class Game
{
	bool playing = 0;
	keyboardHandler *kh;
	std::vector<Ball*> balls;
	// std::vector<std::vector<Brick*>> bricks;
	Paddle* p;
public:
	Game(keyboardHandler* khandle);
	~Game();//this should not delete the handler pointer, as this is handled by the App, which shares the pointer
	void start();
	void draw();
	void idle();
	void getMouseMovement(float x, float y);
};


#endif