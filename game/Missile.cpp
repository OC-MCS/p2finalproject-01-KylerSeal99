#include <iostream>
#include <vector>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Missile.h"

Missile::Missile(SpriteMgr *sprite, Vector2f missilePos)
{
	spriteMissile = sprite->getMissileS();

	spriteMissile.setPosition(missilePos);
}

void Missile::moveMissile()
{
	spriteMissile.move(0, -RANGE);
}

void Missile::draw(RenderWindow &window, Vector2f pos)
{
	window.draw(spriteMissile);
	spriteMissile.setPosition(pos);
}

//void Missile::shootMissile(Sprite enemy,RenderWindow &window )
//{
//	FloatRect missileBounds = spriteMissile.getGlobalBounds();
//	FloatRect enemyBounds = enemy.getGlobalBounds();
//	int count;
//
//	if (missileBounds.intersects(enemyBounds))
//	{
//		missile.setPosition(0, 10);
//		count++;
//		cout << "Total hits: " << count << endl;
//	}
//
//	if (isMissileInFlight)
//	{
//		// ***code goes here to handle a missile in flight
//		window.draw(missile);
//		missile.move(0, -6);
//
//	}
//}


Vector2f Missile::getPos()
{
	return spriteMissile.getPosition();
}

FloatRect Missile::getBounds()
{
	return spriteMissile.getGlobalBounds();
}