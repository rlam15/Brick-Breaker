#ifndef GAME_H
#define GAME_H
#include "App.h"
#include "keyboardHandler.h"
#include "Ball.h"
#include <vector>

class Game
{
	keyboardHandler *kh;
	std::vector<Ball*> balls;
	//vector<vector<Brick*>> bricks;
	//Paddle plat;
public:
	Game(keyboardHandler* khandle);
	~Game();//this should not delete the handler pointer, as this is handled by the App, which shares the pointer
	void start();
	void draw();
};


#endif