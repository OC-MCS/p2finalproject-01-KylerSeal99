#include <iostream>
#include <vector>
#include <list>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "SpriteMgr.h"

SpriteMgr::SpriteMgr()
{
	// Load in ship texture and sprite
	if (!shipTxtr.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	shipSprite.setTexture(shipTxtr);

	// Load in wallpaper texture and sprite
	if (!wallpaperTxtr.loadFromFile("wallpaper.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	wallpaperSprite.setTexture(wallpaperTxtr);

	// Load in missile texture and sprite
	if (!missileTxtr.loadFromFile("Missile05.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}
	missileSprite.setTexture(missileTxtr);

	// Load in alien 1 texture and sprite
	if (!alien1Txtr.loadFromFile("alien.png"))
	{
		cout << "Unable to load alien 1 texture!" << endl;
		exit(EXIT_FAILURE);
	}
	alien1Sprite.setTexture(alien1Txtr);

	// Load in alien 2 texture and sprite
	if (!alien2Txtr.loadFromFile("alien2.png"))
	{
		cout << "Unable to load alien 2 texture!" << endl;
		exit(EXIT_FAILURE);
	}
	alien2Sprite.setTexture(alien2Txtr);

	// Load in alien 1 bomb texture and sprite
	if (!alien1Txtr.loadFromFile("alienBomb1.png"))
	{
		cout << "Unable to load alien 1 bomb texture!" << endl;
		exit(EXIT_FAILURE);
	}
	alien1Sprite.setTexture(alien1Txtr);


}

Sprite SpriteMgr::getShipS()
{

}