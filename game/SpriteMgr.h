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
	Texture wallpaperTxtr;
	Sprite wallpaperSprite;

	Texture shipTxtr;
	Sprite shipSprite;

	Texture missileTxtr;
	Sprite missileSprite;

	Texture alien1Txtr;
	Sprite alien1Sprite;

	Texture alien2Txtr;
	Sprite alien2Sprite;

	Texture bomb1Txtr;
	Texture bomb2Sprite;
public:
	SpriteMgr();

	Sprite getShipS();
	Sprite getMissileS();
	Sprite getWallpaperS();
	Sprite getAlien1S();
	Sprite getAlien2S();
	Sprite getBomb1S();
	Sprite getBomb2S();
};
