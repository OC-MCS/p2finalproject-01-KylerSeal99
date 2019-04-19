#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Missile.h"
#include "SpriteMgr.h"

class Ship
{
private:
	Sprite spriteShip; // Holds the sprite for the ship
	Sprite *wallpaper; // Points to the wallpaper for bounds check
	list<Missile> missiles; // Holds the list of missiles fired from ship
	SpriteMgr *spriteMgr; // Pointer to sprite manager to keep track of ship

public:
	Ship(SpriteMgr &spriteMgr, Sprite &wall, Vector2f newPos, RenderWindow &window);
	void draw(RenderWindow &window);
	void moveShip();
	void shootMissile();
	void checkMissiles();
	void spawnShip();
	bool missileHitAlien(FloatRect bounds);
	Vector2f getPos();
	FloatRect getBounds();
	

};