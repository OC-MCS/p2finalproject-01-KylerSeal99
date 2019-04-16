#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "SpriteMgr.h"

class Missile
{
private:
	Sprite spriteMissile;
	const float RANGE = 10.0;
public:
	Missile(SpriteMgr *text, Vector2f missilePos);
	void moveMissile();
	void draw(RenderWindow &window, Vector2f pos);
	Vector2f getPos();
	FloatRect getBounds();
}