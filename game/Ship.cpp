#include "Ship.h"

// Constructor
Ship::Ship(SpriteMgr &spriteManager, Sprite &wall, Vector2f newPos, RenderWindow &window)
{
	// Ships position
	float shipX = window.getSize().x / 2.0f;
	float shipY = window.getSize().y / 1.1f;
	spriteShip = spriteManager.getShipS();
	spriteShip.setPosition(newPos);

	wallpaper = &wall;

	spriteMgr = &spriteManager;
}

// Moves the ship left and right when arrows are pressed respectivley
void Ship::moveShip()
{
	const float DISTANCE = 5.0;

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		// left arrow is pressed: move our ship left 5 pixels
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		if (spriteShip.getPosition().x > -5)
		{
			spriteShip.move(-DISTANCE, 0);
		}
	}
		
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		// right arrow is pressed: move our ship right 5 pixels
		if (spriteShip.getPosition().x < 760)
		{
			spriteShip.move(DISTANCE, 0);
		}
	}
}

// Draws the ship
void Ship::draw(RenderWindow &window)
{
	window.draw(spriteShip);
	list<Missile>::iterator iter;

	for (iter = missiles.begin(); iter != missiles.end(); iter++)
	{
		iter->draw(window);
	}
}

// Shoots a missile from the ships current position
void Ship::shootMissile()
{
	Missile newMissile(spriteMgr, spriteShip.getPosition().x + 18, spriteShip.getPosition().y);
	missiles.push_back(newMissile);
}

// Checks if a missile is off screen 
void Ship::checkMissiles()
{
	list<Missile>::iterator iter;

	for (iter = missiles.begin(); iter != missiles.end(); iter++ )
	{
		iter->moveMissile();
	}

	for (iter = missiles.begin(); iter != missiles.end(); )
	{
		if (!wallpaper->getGlobalBounds().contains(iter->getPos())) {
			iter = missiles.erase(iter);
		}
		else
			iter++;
	}
}

// Clears all missiles on screen after ship is hit by bomb and reset
void Ship::spawnShip()
{
	missiles.clear();
}

// Checks if missile hit an alien
bool Ship::missileHitAlien(FloatRect bounds)
{
	bool result = false;
	list<Missile>::iterator iter;
	iter = missiles.begin();
	while (iter != missiles.end()) {
		if (bounds.contains(iter->getPos())) {
			iter = missiles.erase(iter); // delete the missile
			result = true;
		}
		else {
			iter++;
		}
	}
	return result;
}

// Getters for the ships position and bounds checking 
Vector2f Ship::getPos()
{
	return spriteShip.getPosition();
}
FloatRect Ship::getBounds()
{
	return spriteShip.getGlobalBounds();
}