#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Missile.h"
#include "UI.h"
#include "SpriteMgr.h"

class Ship
{
private:
	Sprite spriteShip;
	Sprite *wallpaper;
	list<Missile> missiles;
	SpriteMgr *spriteMgr;

public:
	Ship(SpriteMgr &spriteMgr, Sprite wall, Vector2f newPos, RenderWindow &window);
	void draw(RenderWindow &window);
	void moveShip();
	void shootMissile();
	void spawnShip();
	bool missileHitAlien(FloatRect bounds);
	Vector2f getPos();
	FloatRect getBounds();
	

};