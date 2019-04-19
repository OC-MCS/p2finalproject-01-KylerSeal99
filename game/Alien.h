#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "UI.h"
#include "SpriteMgr.h"

class Alien
{
private:
	Sprite spriteAlien; // Holds the sprite for the alien
public:
	Alien(UIMgr *uiMgr, SpriteMgr &spriteMgr, float xPos, float yPos); // Constructor
	void move(float xPos, float yPos); 
	void draw(RenderWindow &window);
	Vector2f getPos();
	FloatRect getBounds();
};