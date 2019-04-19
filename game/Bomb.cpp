#include "Bomb.h"

Bomb::Bomb(SpriteMgr *spriteMgr, UIMgr *uiMgr, float xPos, float yPos)
{
	if (uiMgr->getCurLevel() == 1) 
	{
		spriteBomb = spriteMgr->getBomb1S();
	}
	else
	{
		spriteBomb = spriteMgr->getBomb2S();
	}

	// setup initial bomb position
	spriteBomb.setPosition(xPos, yPos);
}


void Bomb::move()
{
	spriteBomb.move(0, fallSpeed);
}


void Bomb::draw(RenderWindow &window)
{
	window.draw(spriteBomb);
}



Vector2f Bomb::getPos()
{
	return spriteBomb.getPosition();
}


FloatRect Bomb::getBounds()
{
	return spriteBomb.getGlobalBounds();
}