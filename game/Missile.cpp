#include "Missile.h"

// Constructor
Missile::Missile(SpriteMgr *sprite, float xPos, float yPos)
{
	spriteMissile = sprite->getMissileS();

	spriteMissile.setPosition(xPos, yPos);
}

// Moves the missile up the screen
void Missile::moveMissile()
{
	spriteMissile.move(0, -RANGE);
}

// Draws the missile on the screen
void Missile::draw(RenderWindow &window)
{
	window.draw(spriteMissile);
}

// Getters for the missiles position and bounds checking 
Vector2f Missile::getPos()
{
	return spriteMissile.getPosition();
}
FloatRect Missile::getBounds()
{
	return spriteMissile.getGlobalBounds();
}