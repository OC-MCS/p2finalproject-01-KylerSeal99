#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;


class UIMgr
{
private:
	int numLives = 3; // Current Number of lives remaining for player
	int level = 1; // Current level (1 or 2)
	int aliensBlasted = 0; // Current amount of aliens killed

	// Used for holding the main menu font
	Font font;
	Text text;
	Text start; // font for the start button
	bool gameWon = false; // Determines whether to display player won
	bool gameLost = false; // Determines whether to display player lost
	bool startBtn = false; // True when button is pressed
	bool restartLvl = false; // If player runs out of lives or game is started, 
							 // it restartsthe game
public:
	UIMgr(); // constructor
	void startGame(); 
	void drawMenu(RenderWindow &window);
	void display(RenderWindow &window);
	bool gameOn();
	void advanceLevel();
	bool restartLevel();
	void takeLife();
	void isStartButtonClicked(Vector2f pos);
	void alienBlasted() // Increments the amount of aliens killed
	{
		aliensBlasted++;
	}
	void won() // Sets true if the game is won
	{
		gameWon = true;
	}
	void lost() // sets true if game is lost
	{
		gameLost = true;
	}
	int getCurLives() //returns the number of lives for the player
	{ 
		return numLives;
	};
	int getCurLevel() // returns the current level
	{
		return level;
	}
	



};