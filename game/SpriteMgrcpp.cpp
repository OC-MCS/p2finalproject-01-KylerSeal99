#include "SpriteMgr.h"


SpriteMgr::SpriteMgr()
{
	// Load in ship texture and sprite
	if (!shipTxtr.loadFromFile("spshipsprite.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	spriteShip.setTexture(shipTxtr);
	spriteShip.setScale(0.5, 0.5);
	

	// Load in wallpaper texture and sprite
	if (!wallpaperTxtr.loadFromFile("wallpaper.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	spriteWallpaper.setTexture(wallpaperTxtr);

	// Load in missile texture and sprite
	if (!missileTxtr.loadFromFile("Missile04N.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}
	spriteMissile.setTexture(missileTxtr);
	spriteMissile.setScale(.05, .05);

	// Load in alien 1 texture and sprite
	if (!alien1Txtr.loadFromFile("alien.png"))
	{
		cout << "Unable to load alien 1 texture!" << endl;
		exit(EXIT_FAILURE);
	}
	spriteAlien1.setTexture(alien1Txtr);
	spriteAlien1.setScale(.12, .12);

	// Load in alien 2 texture and sprite
	if (!alien2Txtr.loadFromFile("alien2.png"))
	{
		cout << "Unable to load alien 2 texture!" << endl;
		exit(EXIT_FAILURE);
	}
	spriteAlien2.setTexture(alien2Txtr);
	spriteAlien2.setScale(.35, .35);

	// Load in alien 1 bomb texture and sprite
	if (!bomb1Txtr.loadFromFile("bomb100.png"))
	{
		cout << "Unable to load alien 1 bomb texture!" << endl;
		exit(EXIT_FAILURE);
	}
	spriteBomb1.setTexture(bomb1Txtr);
	spriteBomb1.setScale(0.5, 0.5);

	 //Load in alien 2 bomb texture and sprite
	if (!bomb2Txtr.loadFromFile("alienBomb1.png"))
	{
		cout << "Unable to load alien 2 bomb texture!" << endl;
		exit(EXIT_FAILURE);
	}
	spriteBomb2.setTexture(bomb2Txtr);
	spriteBomb2.setScale(0.05, 0.05);

}

// Getter for the ship sprite
Sprite SpriteMgr::getShipS()
{
	return spriteShip;
}

// Getter for the missile sprite
Sprite SpriteMgr::getMissileS()
{
	return spriteMissile;
}

// Getter for the wallpaper sprite
Sprite SpriteMgr::getWallpaperS()
{
	return spriteWallpaper;
}

// Getter for the first alien sprite
Sprite SpriteMgr::getAlien1S()
{
	return spriteAlien1;
}

// Getter for the 2nd alien sprite
Sprite SpriteMgr::getAlien2S()
{
	return spriteAlien2;
}

// Getter for the 1st bomb sprite
Sprite SpriteMgr::getBomb1S()
{
	return spriteBomb1;
}

// Getter for the 2nd bomb sprite
Sprite SpriteMgr::getBomb2S()
{
	return spriteBomb2;
}

