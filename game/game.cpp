//=========================================================
// This is just the starting point for your final project.
// You are expected to modify and add classes/files as needed.
// The code below is the original code for our first graphics
// project (moving the little green ship). 
//========================================================
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf; 
#include "Missile.h"
#include "Alien.h"
#include "AlienInvasion.h"
#include "Bomb.h"
#include "Ship.h"
#include "UI.h"
#include "SpriteMgr.h"

//============================================================
// Kyler Seal 
//============================================================

// note: a Sprite represents an image on screen. A sprite knows and remembers its own position
// ship.move(offsetX, offsetY) adds offsetX, offsetY to 
// the current position of the ship. 
// x is horizontal, y is vertical. 
// 0,0 is in the UPPER LEFT of the screen, y increases DOWN the screen




int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.
	

	SpriteMgr spriteMgr;
	UIMgr uiMgr;

	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like
	Sprite wallpaper;
	wallpaper = spriteMgr.getWallpaperS();
	wallpaper.setScale(1.5, 1.5);

	// initial position of the ship will be approx middle of screen
	Vector2f pos(window.getSize().x / 2.0f, window.getSize().y / 1.1f);
	Ship ship(spriteMgr, wallpaper, pos, window);

	AlienInvasion alienInvasion(spriteMgr, wallpaper, uiMgr, ship);

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				 // Checks if missile needs to be shot
				if (event.key.code == Keyboard::Space)
				{
					ship.shootMissile();
				}
				// Checks if start button is clicked
				if (event.type == Event::MouseButtonReleased) 
				{
					cout << "Calling start button check function \n";
					uiMgr.isStartButtonClicked(window.mapPixelToCoords(Mouse::getPosition(window)));
				}
			}
		}

		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================
		window.clear();

		// For the main Game 
		if (!uiMgr.gameOn()) // If You change this to if (!uiMgr.gameOn() 
							 // It will display menu but button does not work
		{
			cout << "Running Menu \n";
			window.draw(wallpaper);
			uiMgr.startGame();
			uiMgr.drawMenu(window);
			uiMgr.display(window);
		}
		else
		{
			if (uiMgr.restartLevel())
			{
				alienInvasion.restartAliens();
				ship.spawnShip();
			}
			// Draw the background
			window.draw(wallpaper);

			// Handle & Draw ship assets
			ship.moveShip();
			ship.checkMissiles();
			ship.draw(window);

			// Handle & Draw alien assets
			alienInvasion.dropAliens(window);
			alienInvasion.draw(window);
			alienInvasion.dropBombs();
			alienInvasion.moveBombs(window);
			alienInvasion.drawBombs(window);
			alienInvasion.checkHit();

			// Dispaly current info
			uiMgr.display(window);
		}

		window.display();
	} // end body of animation loop

	return 0;
}

