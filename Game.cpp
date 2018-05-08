#include "Game.h"
#include <stdio.h>


Game::Game(keyboardHandler* khandle)
{
	//this line creates a new seed for all uses of rand()
	background = new TexRect("Textures/background.png", -1,1,2,2.5);
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
    winT = new TexRect("Textures/win.png", -1,.66,2,1);
    lose = new TexRect("Textures/lose.png", -1,.66,2,1);
    scoreT = new TexRect("Textures/currentHighScore.png", 0.2,1,.4,.08);
    scoreTex = new TexRect("Textures/score.png", -1,1,.4,.08);
    highScoreDisplay = new displayData(.6,1.,.4,.08);
    scoreDisplay = new displayData(-.6,1.,.4,.08);
    liveT.push_back(new TexRect("Textures/ball.png", -.11, .98, 0.05, 0.05));
    liveT.push_back(new TexRect("Textures/ball.png",-.01, .98, 0.05, 0.05));
    liveT.push_back(new TexRect("Textures/ball.png", .09, .98, 0.05, 0.05));
    

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
	if(lives<=0)
		lose->draw();


	p->draw();
	for(Brick* b: bricks)
		b->draw();
	for(Ball* b: balls)
		b->draw();
	for(int i = 1; i<=lives;i++)
		liveT[i-1]->draw();

	if(won)
		winT->draw();

	highScoreDisplay->draw();
	scoreDisplay->draw();	
	scoreT->draw();	
	scoreTex->draw();
	// background->draw();
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
    			if(i<bricks.size())
    				bricks[i]->loadTex();
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
    if (highScore < score) 
    {
    	highScore = score;
    	highScoreDisplay->setData(highScore);
    }
    if(kh->getHold('='))
    {

		p->changeSize(.03);
    }

    if(kh->getHold('-'))
    {

		p->changeSize(-.03);
    }
    if(kh->getHold('1'))
	{

		mode = 1;
	}
	if(kh->getHold('2'))
	{

		mode = 2;
	}
	if(kh->getHold('3'))
	{
		mode = 3;
	}
    scoreDisplay->setData(score);
}

void Game::getMouseMovement(float x, float y)
{
	p->update(x,y);
	for(Ball* b:balls)
	{
		if(kh->getHold('p'))
			b->cheatXY(x,y); //uncomment this line  to move balls to cursor position
	}
}

void Game::newLife()
{
	for(Ball* b : balls)
		delete b;
	balls.clear();
	balls.push_back(new Ball(0,-.8, 0));
	score -= 30;
	if(score<0)
		score=0;
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
	if(mode==2)
	{
		for(int i = 0; i<col;i++)
		{
			for(int j = 0; j<row;j++)
			{
				float xFac = 2./col;
				float yFac = 1./row;
				bricks.push_back(new Brick((i*xFac)-1,j*yFac,xFac,yFac));
			}
		}
		// if(lives==0)
		// 	p->changeSize(.05);
	}
	else if(mode==3)
	{
		for(int i = 0; i<col;i++)
		{
			for(int j = 0; j<row;j++)
			{
				float xFac = 2./col;
				float yFac = 1./row;
				bricks.push_back(new Brick((i*xFac)-1,j*yFac,xFac,yFac, rand()%5));
			}
		}
		// if(lives==0)
		// 	p->changeSize(.05);
	}
	else
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
    scoreDisplay->setData(score);
    newLife();
}

void Game::win()
{
	won = 1;
		if(lives==3)
			score+=20;
		// std::cout<<sco"re<<std::endl;
}