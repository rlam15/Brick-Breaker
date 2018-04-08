#include "Game.h"


Game::Game(keyboardHandler* khandle)
{
	kh = khandle;
	p = new Paddle();
}

Game::~Game()
{
	delete p;
	for(Ball* b : balls)
		delete b;
}

void Game::draw()
{
	for(Ball* b: balls)
		b->draw();
	p->draw();
}

void Game::start()
{
	balls.empty();
	balls.push_back(new Ball(0,-.8, 0));
}

void Game::idle()
{
	if(!playing)
	{
		playing = kh->getHold(' ');
		if(playing)
			balls[0]->setVel(.01);
	}
    p->update();
	for(Ball* b : balls)
	{
		b->move();
    	p->checkCollision(b);
    }
    for(char c = 'a'; c<='z';c++)
    {
        if(kh->getHold(c))
        p->update(c);
        
    }
}

void Game::getMouseMovement(float x, float y)
{
	p->update(x,y);
}