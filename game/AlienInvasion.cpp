#include "AlienInvasion.h"

// Constructor
AlienInvasion::AlienInvasion(SpriteMgr &spriteManager, Sprite &wall, UIMgr &uiManager, Ship &theShip)
{
	for (int i = 0; i < 14; i++) 
	{
		Alien newAlien(&uiManager, spriteManager, 50.0f + (i * 50.0f), 100.0f);
		aliens.push_back(newAlien);
	}
	alienLine = 100;

	spriteMgr = spriteManager;
	wallpaper = wall;
	uiMgr = &uiManager;
	ship = &theShip;
}

// Drops the aliens down the screen
void AlienInvasion::dropAliens(RenderWindow &window)
{
	if (alienLine <= window.getSize().y / 1.15f)
	{
		if (timer == 0)
		{
			list<Alien>::iterator iter;
			for (iter = aliens.begin(); iter != aliens.end(); iter++)
			{
				iter->move(0, 1);
				alienLine = iter->getPos().y; // keep track of the y position in a variable
			}
			timer = RESET_TIMER; // reset timer 
		}
		else 
		{ 
			timer--;
		}
	}
	else
	{ // if the aliens have reached the bottom of the screen
		uiMgr->lost();
	}
}

// draw all the aliens in the list
void AlienInvasion::draw(RenderWindow &window)
{
	list<Alien>::iterator iter;
	for (iter = aliens.begin(); iter != aliens.end(); iter++)
	{
		iter->draw(window);
	}
}

// Starts the aliens back at the beginning
void AlienInvasion::restartAliens()
{
	aliens.clear(); // delete everything from the alien list
	bombs.clear();  // delete all the bombs

	// respawns aliens
	for (int i = 0; i < 14; i++)
	{
		Alien newAlien(uiMgr, spriteMgr, 50.0f + (i * 50.0f), 100.0f);
		aliens.push_back(newAlien);
	}
	alienLine = 100;
}

// Sees if a missile hit an alien
void AlienInvasion::checkHit()
{
	if (aliens.size() == 0)
	{     // if all of the aliens are killed
		uiMgr->advanceLevel(); // go to level 2
	}
	else 
	{
		list<Alien>::iterator iter;
		iter = aliens.begin();
		while (iter != aliens.end()) {
			if (ship->missileHitAlien(iter->getBounds()))
			{
				iter = aliens.erase(iter);  // delete hit alien
				uiMgr->alienBlasted(); // increase alien death count
			}
			else 
			{
				iter++;
			}
		}

		// Check if a bomb hit the ship
		list<Bomb>::iterator bombIter;
		bombIter = bombs.begin();
		while (bombIter != bombs.end()) 
		{
			if (ship->getBounds().contains(bombIter->getPos())) 
			{
				// delete the bomb and take a life
				bombIter = bombs.erase(bombIter);
				uiMgr->takeLife();		  
			}
			else 
			{
				bombIter++;
			}
		}
	}
}

// Moves the bombs down the screen
void AlienInvasion::moveBombs(RenderWindow &window)
{
	list<Bomb>::iterator iter;
	iter = bombs.begin();
	while (iter != bombs.end())
	{
		iter->move();
		if (iter->getPos().y > window.getSize().y)
		{
			iter = bombs.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

// Draws the bombs on the screen
void AlienInvasion::drawBombs(RenderWindow &window)
{
	list<Bomb>::iterator iter;
	for (iter = bombs.begin(); iter != bombs.end(); iter++)
	{
		iter->draw(window);
	}
}

// Randomly selects aliens to drop bomb
void AlienInvasion::dropBombs()
{
	if (bombTimer == 0)
	{ // if the timer has finished counting down
		// select a random alien to drop a bomb 
		int randomAlien = rand() % aliens.size();

		list<Alien>::iterator iter;
		iter = aliens.begin();
		for (int i = 0; i < randomAlien; i++)
			iter++;

		// drop a bomb 
		Bomb newBomb(&spriteMgr, uiMgr, iter->getPos().x + 10, iter->getPos().y + 20);
		bombs.push_back(newBomb);

		// reset the timer - if the game is on level two make it a shorter interval 
		int temp = rand() % 20;
		bombTimer = static_cast<int>((bombReset + temp) / ((uiMgr->getCurLevel() * 0.3) + 1));
	}
	else
	{
		bombTimer--;
	}
}