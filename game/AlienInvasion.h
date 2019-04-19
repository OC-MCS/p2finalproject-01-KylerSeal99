#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;
#include "spriteMgr.h"
#include "Bomb.h"
#include "Alien.h"
#include "Ship.h"
#include "UI.h"

class AlienInvasion
{
private:
	list<Alien> aliens;  // linked list that keeps track of all the aliens
	list<Bomb> bombs;    // linked list that keeps track of all the bombs
	Ship *ship;			 // pointer to the ship 
	SpriteMgr spriteMgr; // holds the spriteManager for creating new aliens and bombs
	Sprite wallpaper;    // holds the wallpaper for bounds checking on bombs and aliens 
	UIMgr *uiMgr;		 // holds the UI manager to get the levels and lives 
	float alienLine;	 // checks the bounds of the aliens to see if they reached the bottom
	int timer;			 //
	const int RESET_TIMER = 3;
	int bombTimer;
	int bombReset = 55;
public:
	AlienInvasion(SpriteMgr &spriteMgr, Sprite &wallpaper, UIMgr &uiMgr, Ship &theShip);
	void dropAliens(RenderWindow &window);
	void draw(RenderWindow &window);
	void restartAliens();
	void checkHit();
	void moveBombs(RenderWindow &window); 
	void drawBombs(RenderWindow &window); 
	void dropBombs();
};