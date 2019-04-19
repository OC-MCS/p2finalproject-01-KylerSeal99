#include "UI.h"

// Constructor
UIMgr::UIMgr()
{
	if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
	{
		cout << "Error! Couldn't load font! " << endl;
		exit(EXIT_FAILURE);
	}
}

// Sets up game for when start button pressed
void UIMgr::startGame()
{
	if (startBtn)
	{
		startBtn = false;
		numLives = 3;
		level = 1;
		aliensBlasted = 0;
		gameLost = false;
		gameWon = false;
		restartLvl = true;
	}
}

// Draws the menu
void UIMgr::drawMenu(RenderWindow &window)
{
	text.setFont(font);
	if (gameWon) // Displays the Game is won
	{
		text.setFillColor(Color::Blue);
		text.setString("Aliens Defeated!");
		text.setCharacterSize(70);
		text.setPosition(150, 270);
		window.draw(text);

	}	
	else if(gameLost)// Displays the Game is lost
	{
		text.setFillColor(Color::Red);
		text.setString("The Aliens have invaded!");
		text.setCharacterSize(70);
		text.setPosition(10, 150);
		window.draw(text);

		start.setFont(font);
		start.setFillColor(Color::Magenta);
		start.setString("Play Again!");
		start.setCharacterSize(50);
		start.setPosition(300, 275);
		window.draw(start);
	}
	else // Displays the main menu
	{
		cout << "Trying to display menu \n";
		text.setFillColor(Color::Green);
		text.setString("Space Invaders");
		text.setCharacterSize(100);
		text.setPosition(90, 100);
		window.draw(text);

		start.setFont(font);
		start.setFillColor(Color::Magenta);
		start.setString("Start Game");
		start.setCharacterSize(40);
		start.setPosition(300, 250);
		window.draw(start);

	}
}

void UIMgr::display(RenderWindow &window)
{
	text.setFont(font);
	text.setFillColor(Color::White);
	text.setString("Lives " + to_string(numLives)
		+ ": Level " + to_string(level) + 
		": Aliens Blasted " + to_string(aliensBlasted));
	text.setCharacterSize(25);
	text.setPosition(10, 0);
	window.draw(text);
}


bool UIMgr::gameOn()
{
	bool result = true;
	if (gameWon || gameLost)
	{
		result = false;
	}
	return result;
}

void UIMgr::advanceLevel()
{
	if (level != 2)
	{
		level = 2;
		restartLvl = true;
	}
	else
	{
		gameWon = true;
	}
}

// Restarts the current level (resets all aliens at top)
bool UIMgr::restartLevel()
{
	bool result = restartLvl;
	if (restartLvl)
		restartLvl = false;
	return result;
}

// Decrements a life from the player
void UIMgr::takeLife()
{
	numLives--;
	if (numLives <= 0) 
	{
		gameLost = true;
	}
	restartLvl = true;
}

// Checks if the start button is clicked
void UIMgr::isStartButtonClicked(Vector2f pos)
{
	cout << "Checking to see if start button clicked \n";
	if (start.getGlobalBounds().contains(pos))
	{
		startBtn = true;
	}
}