#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;


class SpriteMgr
{
private:
	// Holds textures and sprites for all the assests
	Texture wallpaperTxtr;
	Sprite spriteWallpaper;

	Texture shipTxtr;
	Sprite spriteShip;

	Texture missileTxtr;
	Sprite spriteMissile;

	Texture alien1Txtr;
	Sprite spriteAlien1;

	Texture alien2Txtr;
	Sprite spriteAlien2;

	Texture bomb1Txtr;
	Sprite spriteBomb1;

	Texture bomb2Txtr;
	Sprite spriteBomb2;
public:
	SpriteMgr(); // constructors

	// Getters for the sprites
	Sprite getShipS();
	Sprite getMissileS();
	Sprite getWallpaperS();
	Sprite getAlien1S();
	Sprite getAlien2S();
	Sprite getBomb1S();
	Sprite getBomb2S();
};
