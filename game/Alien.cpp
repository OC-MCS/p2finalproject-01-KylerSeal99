#include "Alien.h"

//Constructor
Alien::Alien(UIMgr *uiMgr, SpriteMgr &spriteMgr, float xPos, float yPos)
{
	if (uiMgr->getCurLevel() == 1)
	{
		spriteAlien = spriteMgr.getAlien1S();
	}
	else
	{
		spriteAlien = spriteMgr.getAlien2S();
	}

	spriteAlien.setPosition(xPos, yPos);
}

// Moves the alien down the scrren
void Alien::move(float xPos, float yPos)
{
	spriteAlien.move(xPos, yPos);
}

// Draws the alien on the screen
void Alien::draw(RenderWindow &window)
{
	window.draw(spriteAlien);
}

// Getter for the position of the alien
Vector2f Alien::getPos()
{
	return spriteAlien.getPosition();
}

// Getter to check the bounds of the alien
FloatRect Alien::getBounds()
{
	return spriteAlien.getGlobalBounds();
}