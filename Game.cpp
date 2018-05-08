#include "Game.h"
#include <stdio.h>


Game::Game(keyboardHandler* khandle)
{
	//this line creates a new seed for all uses of rand()
	srand(static_cast<unsigned>(time(0)));
	kh = khandle;
	p = new Paddle();
	// tex = new TexRect("Textures/thelegend.png", x, y, 1, 1);
	for(int i = 0; i<col;i++)
	{
		for(int j = 0; j<row;j++)
		{
			float xFac = 2./col;
			float yFac = 1./row;
			bricks.push_back(new Brick((i*xFac)-1,j*yFac,xFac,yFac, (j/3)+1));
		}
	}

}

Game::~Game()
{
	delete p;
	for(Ball* b : balls)
		delete b;
	for(Brick* b : bricks)
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
	balls.clear();
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
		if(b->getY()<-1)
		{
			if(balls.size()==1)
			{
				lives--;
				if(lives>0)
				{
					newLife();
					break;
				}
				else
				{
					lostGame();
					break;
				}

			}
			else if(balls.size()>1)
			{
				delete b;
				break;
			}
		}
    	p->checkCollision(b);
    	for(int i = 0; i <bricks.size();i++)
    	{
    		bool a = b->collide(bricks[i]);
    		if(a)
    		{
    			score++;
    			if(bricks[i]->hit())
    			{
    				delete bricks[i];
    				bricks.erase(bricks.begin()+i);
    			}
    			if(bricks.size()==0)
    				win();
    		}
    	}
    }
    for(char c = 'a'; c<='z';c++)
    {
        if(kh->getHold(c))
        {
        	p->update(c);
        }
        
    }
    if(kh->getHold('r')&&(lives==0||won))
    {
    	restart();
    }
}

void Game::getMouseMovement(float x, float y)
{
	p->update(x,y);
	for(Ball* b:balls)
	{

		// b->cheatXY(x,y); //uncomment this line to move balls to cursor position
	}
}

void Game::newLife()
{
	for(Ball* b : balls)
		delete b;
	balls.clear();
	balls.push_back(new Ball(0,-.8, 0));
	score -= 30;
	playing = 0;
}

void Game::lostGame()
{
	//display a loss screen
	for(Ball* b : balls)
		delete b;
	balls.clear();
}

void Game::restart()
{
	for(Brick* b : bricks)
		delete b;
	bricks.clear();
	for(int i = 0; i<col;i++)
	{
		for(int j = 0; j<row;j++)
		{
			float xFac = 2./col;
			float yFac = 1./row;
			bricks.push_back(new Brick((i*xFac)-1,j*yFac,xFac,yFac, (j/3)+1));
		}
	}

    lives = 3;
    won = 0;
    score = 0;
    newLife();
}

void Game::win()
{
	won = 1;
	std::cout<<score<<std::endl;
}