#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;
#include "spriteMgr.h"
#include "UI.h"

class Bomb
{
private:
	Sprite spriteBomb;
	const float fallSpeed = 5.0;
public:
	Bomb(SpriteMgr*spriteMgr, UIMgr *uiMgr, float xPos, float yPos);
	void move();
	void draw(RenderWindow &window);
	Vector2f getPos();
	FloatRect getBounds();
};
