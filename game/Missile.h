#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "SpriteMgr.h"
#include "Alien.h"

class Missile
{
private:
	Sprite spriteMissile; // Holds sprite for the missile
	const float RANGE = 10.0; // Distance the missile shoots
public:
	Missile(SpriteMgr *sprite, float xPos, float yPos);
	void moveMissile();
	void draw(RenderWindow &window);
	Vector2f getPos();
	FloatRect getBounds();
};