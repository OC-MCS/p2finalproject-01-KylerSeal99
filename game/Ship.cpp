#include "Ship.h"
#include <iostream>
#include <vector>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "SpriteMgr.h"

Ship::Ship(SpriteMgr &spriteManager, Sprite wall, Vector2f newPos, RenderWindow &window)
{
	float shipX = window.getSize().x / 2.0f;
	float shipY = window.getSize().y / 1.1f;
	spriteShip = spriteManager.getShipS();
	spriteShip.setPosition(newPos);

	wallpaper = &wall;

	spriteMgr = &spriteManager;
}

void Ship::moveShip()
{
	const float DISTANCE = 5.0;

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		// left arrow is pressed: move our ship left 5 pixels
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		spriteShip.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		// right arrow is pressed: move our ship right 5 pixels
		spriteShip.move(DISTANCE, 0);
	}
}

void Ship::draw(RenderWindow &window)
{
	window.draw(spriteShip);
	list<Missile>::iterator iter;

	for (iter = missiles.begin(); iter != missiles.end(); iter++)
	{
		iter->draw(window);
	}
}

void Ship::shootMissile()
{
	Missile newMissile(spriteManager, spriteShip.getPosition().x + 15, spriteShip.getPosition().y - 5);
	missiles.push_back(newMissile);
}

void Ship::spawnShip()
{

}