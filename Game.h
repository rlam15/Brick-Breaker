#ifndef GAME_H
#define GAME_H
// #include "App.h"
#include "keyboardHandler.h"
#include "displayData.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include <vector>

class Game
{
	bool playing = 0;
	bool won = 0;
	int score = 0;
	int lives = 3;
	int highScore = 0;
	keyboardHandler *kh;
	std::vector<Ball*> balls;
	std::vector<Brick*> bricks;
	int const col = 6;
	int const row = 12;
	Paddle* p;
	TexRect *background;
	TexRect *winT;
	TexRect *scoreT;
	TexRect *scoreTex;
	TexRect *lose;
	std::vector<TexRect*> liveT;
	//need to implement these
	displayData *highScoreDisplay;
	displayData *scoreDisplay;
public:
	Game(keyboardHandler* khandle);
	~Game();//this should not delete the handler pointer, as this is handled by the App, which shares the pointer
	void start();
	void draw();
	void idle();
	void getMouseMovement(float x, float y);
	void newLife();
	void lostGame();
	void restart();
	void win();
};


#endif