#include "Game.h"
#include <stdio.h>


Game::Game(keyboardHandler* khandle)
{
	//this line creates a new seed for all uses of rand()
	srand(static_cast<unsigned>(time(0)));
	kh = khandle;
	p = new Paddle();
	for(int i = 0; i<col;i++)
	{
		for(int j = 0; j<row;j++)
		{
			float xFac = 2./col;
			float yFac = 1./row;
			bricks.push_back(new Brick((i*xFac)-1,j*yFac,xFac,yFac));
		}
	}

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
	for(Brick* b: bricks)
		b->draw();
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
    	for(int i = 0; i <bricks.size();i++)
    	{
    		bool a = b->collide(bricks[i]);
    		if(a)
    		{
    			delete bricks[i];
    			bricks.erase(bricks.begin()+i);
    		}
    	}
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