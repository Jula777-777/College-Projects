#include <iostream>
#include <random>

using namespace std;

/*Game Constants*/
const int gameBoardSize{ 30 };
int gameBoardSizeBasedOnDifficulty{ 10 };
enum class gamePieces{hiddenEmpty, revealedEmpty, hiddenMine, revealedMine, flaggedEmpty, flaggedMine};

/*GUI Functions*/
void splashScreen();
void displayGameState(gamePieces gameBoard[gameBoardSize][gameBoardSize], bool revealMines = false);
void displayGameDone(gamePieces gameBoard[gameBoardSize][gameBoardSize], bool noRevealedMines, bool allMinesFlagged);


/* Engine Functions*/
void boardSetup(gamePieces gameBoard[gameBoardSize][gameBoardSize]);
void changeGameState(gamePieces gameBoard[gameBoardSize][gameBoardSize]);
bool gameIsNotDone(gamePieces gameBoard[gameBoardSize][gameBoardSize], bool & noRevealedMines, bool & unrevealedSafeSpots, bool & allMinesFlagged);

int getRandomNumber();

int main()
{
	splashScreen();

	cout << "Choose a difficulty level (e for easy, m for medium, or h for hard): ";
	char difficulty;
	cin >> difficulty;
		switch (difficulty)
		{
		case 'e':
		case 'E':
			gameBoardSizeBasedOnDifficulty = 10;
			break;
		case 'm':
		case 'M':
			gameBoardSizeBasedOnDifficulty = 20;
			break;
		case 'h':
		case 'H':
			gameBoardSizeBasedOnDifficulty = 30;
			break;
		}

	gamePieces gameBoard[gameBoardSize][gameBoardSize];
	boardSetup(gameBoard);
	bool noRevealedMines{ true };
	bool unrevealedSafeSpots{ false };
	bool allMinesFlagged{ true };

	while (gameIsNotDone(gameBoard, noRevealedMines, unrevealedSafeSpots, allMinesFlagged))
	{
		displayGameState(gameBoard);
		changeGameState(gameBoard);
	}
	displayGameDone(gameBoard, noRevealedMines, allMinesFlagged);

	cout << endl;
	system("PAUSE");
	return 0;
}

void splashScreen()
{
	cout << "Mine Sweeper!" << endl;
	cout << endl;
	cout << "Justin Dady (2019)" << endl;
	cout << "CPSC 2377, Game Programming, Quest 1" << endl;
	cout << "UALR, Computer Science Dept." << endl;
	cout << endl;
	cout << "INSTRUCTIONS:" << endl;
	cout << endl;
	cout << "Clear the minefield without hitting a mine!" << endl << endl;
	system("PAUSE");
}

void displayGameState(gamePieces gameBoard[gameBoardSize][gameBoardSize], bool revealMines)
{
	if (revealMines == true)
	{
		for (int i{ 0 }; i < gameBoardSizeBasedOnDifficulty; i++)
		{
			for (int j{ 0 }; j < gameBoardSizeBasedOnDifficulty; j++)
			{
				switch (gameBoard[i][j])
				{
				case gamePieces::hiddenEmpty:
				case gamePieces::flaggedEmpty:
					gameBoard[i][j] = gamePieces::revealedEmpty;
					break;
				case gamePieces::hiddenMine:
				case gamePieces::flaggedMine:
					gameBoard[i][j] = gamePieces::revealedMine;
					break;
				}
			}
		}
	}
	cout << "   ";
	for (int i{ 0 }; i < gameBoardSizeBasedOnDifficulty; i++)
	{
		if (i < 9)
		{
			cout << i + 1 << "  ";
		}
		else
		{
			cout << i + 1 << " ";
		}
	}
	cout << endl;
	char row{ 'A' };
	for (int rowIndex{ row - 'A' }; rowIndex < gameBoardSizeBasedOnDifficulty; rowIndex++)
	{
		cout << row << "| ";
		int numberOfMines{ 0 };
		for (int column{ 0 }; column < gameBoardSizeBasedOnDifficulty; column++)
		{
			switch (gameBoard[rowIndex][column])
			{
			case gamePieces::hiddenEmpty:
			case gamePieces::hiddenMine:
				cout << "-  ";
				break;
			case gamePieces::revealedMine:
				cout << "*  ";
				break;
			case gamePieces::revealedEmpty:
				numberOfMines = 0;
				if (gameBoard[rowIndex - 1][column - 1] == gamePieces::hiddenMine || gameBoard[rowIndex - 1][column - 1] == gamePieces::revealedMine || gameBoard[rowIndex - 1][column - 1] == gamePieces::flaggedMine)
				{
					if (rowIndex >= 1 && column >= 1)
					{
						numberOfMines++;
					}
				}

				if (gameBoard[rowIndex - 1][column] == gamePieces::hiddenMine || gameBoard[rowIndex - 1][column] == gamePieces::revealedMine || gameBoard[rowIndex - 1][column] == gamePieces::flaggedMine)
				{
					if (rowIndex >= 1)
					{
						numberOfMines++;
					}
				}

				if (gameBoard[rowIndex - 1][column + 1] == gamePieces::hiddenMine || gameBoard[rowIndex - 1][column + 1] == gamePieces::revealedMine || gameBoard[rowIndex - 1][column + 1] == gamePieces::flaggedMine)
				{
					if (rowIndex >= 1 && column <= 8)
					{
						numberOfMines++;
					}
				}

				if (gameBoard[rowIndex][column - 1] == gamePieces::hiddenMine || gameBoard[rowIndex][column - 1] == gamePieces::revealedMine || gameBoard[rowIndex][column - 1] == gamePieces::flaggedMine)
				{
					if (column >= 1)
					{
						numberOfMines++;
					}
				}

				if (gameBoard[rowIndex][column + 1] == gamePieces::hiddenMine || gameBoard[rowIndex][column + 1] == gamePieces::revealedMine || gameBoard[rowIndex][column + 1] == gamePieces::flaggedMine)
				{
					if (column <= 8)
					{
						numberOfMines++;
					}
				}

				if (gameBoard[rowIndex + 1][column - 1] == gamePieces::hiddenMine || gameBoard[rowIndex + 1][column - 1] == gamePieces::revealedMine || gameBoard[rowIndex + 1][column - 1] == gamePieces::flaggedMine)
				{
					if (rowIndex <= 8 && column >= 1)
					{
						numberOfMines++;
					}
				}

				if (gameBoard[rowIndex + 1][column] == gamePieces::hiddenMine || gameBoard[rowIndex + 1][column] == gamePieces::revealedMine || gameBoard[rowIndex + 1][column] == gamePieces::flaggedMine)
				{
					if (rowIndex <= 8)
					{
						numberOfMines++;
					}
				}

				if (gameBoard[rowIndex + 1][column + 1] == gamePieces::hiddenMine || gameBoard[rowIndex + 1][column + 1] == gamePieces::revealedMine || gameBoard[rowIndex + 1][column + 1] == gamePieces::flaggedMine)
				{
					if (rowIndex <= 8 && column <= 8)
					{
						numberOfMines++;
					}
				}
				cout << numberOfMines << "  ";
				break;
			case gamePieces::flaggedEmpty:
			case gamePieces::flaggedMine:
				cout << "f  ";
				break;
			}
		}
		cout << endl;
		row++;
	}
}

void displayGameDone(gamePieces gameBoard[gameBoardSize][gameBoardSize], bool noRevealedMines, bool allMinesFlagged)
{
	displayGameState(gameBoard, true);

	if (!noRevealedMines)
	{
		cout << "The mine exploded and killed you! Better luck next time.\n";
	}
	else if (allMinesFlagged)
	{
		cout << "Congratulations, you have successfully flagged all of the mines! Everyone now knows which spots to avoid!\n";
	}
	else
	{
		cout << "Congratulations, you have cleared the mine field! You are an hero to the world! Use your power for good!\n";
	}
}

void boardSetup(gamePieces gameBoard[gameBoardSize][gameBoardSize])
{
	for (int i{ 0 }; i < gameBoardSizeBasedOnDifficulty; i++)
	{
		for (int j{ 0 }; j < gameBoardSizeBasedOnDifficulty; j++)
		{
			gameBoard[i][j] = gamePieces::hiddenEmpty;
		}
	}
	switch (gameBoardSizeBasedOnDifficulty)
	{
	case 10:
		for (int mines{ 0 }; mines < 25; mines++)
		{
			gameBoard[getRandomNumber()][getRandomNumber()] = gamePieces::hiddenMine;
		}
		break;
	case 20:
		for (int mines{ 0 }; mines < 120; mines++)
		{
			gameBoard[getRandomNumber()][getRandomNumber()] = gamePieces::hiddenMine;
		}
		break;
	case 30:
		for (int mines{ 0 }; mines < 360; mines++)
		{
			gameBoard[getRandomNumber()][getRandomNumber()] = gamePieces::hiddenMine;
		}
		break;
	}
}

int getRandomNumber()
{
	static random_device seed;
	static default_random_engine e(seed());
	static uniform_int_distribution<int> ud(0, gameBoardSizeBasedOnDifficulty -1);
	return ud(e);	
}

void changeGameState(gamePieces gameBoard[gameBoardSize][gameBoardSize])
{
	cout << "Press r to select a spot to reveal or press f to select a spot to flag or unflag: ";
	char userInput;
	cin >> userInput;
	char row{ ' ' };
	int rowIndex{ 0 };
	int column{ 0 };
	switch (userInput)
	{
	
	case 'f':
	case 'F':
		cout << "Choose a row to flag or unflag (A-";
		if (gameBoardSizeBasedOnDifficulty <= 25)
		{
			cout << char(gameBoardSizeBasedOnDifficulty + 'A' - 1) << "): ";
		}
		else
		{
			cout << "Z, [, \\, ], or ^): ";
		}
		cin >> row;
		while (row < 'A' || row >= gameBoardSizeBasedOnDifficulty + 'A')
		{
			cout << "Choose a row to flag or unflag (A-";
			if (gameBoardSizeBasedOnDifficulty <= 25)
			{
				cout << char(gameBoardSizeBasedOnDifficulty + 'A' - 1) << "): ";
			}
			else
			{
				cout << "Z, [, \\, ], or ^): ";
			}
			cin >> row;
		}
		rowIndex = row - 'A';

		cout << "Choose a column to flag or unflag (1-" << gameBoardSizeBasedOnDifficulty << "): ";
		cin >> column;
		while (column < 1 || column > gameBoardSizeBasedOnDifficulty)
		{
			cout << "Choose a column to flag or unflag (1-" << gameBoardSizeBasedOnDifficulty << "): ";
			cin >> column;
		}

		switch (gameBoard[rowIndex][column - 1])
		{
		case gamePieces::hiddenEmpty:
			gameBoard[rowIndex][column - 1] = gamePieces::flaggedEmpty;
			break;
		case gamePieces::hiddenMine:
			gameBoard[rowIndex][column - 1] = gamePieces::flaggedMine;
			break;
		case gamePieces::flaggedEmpty:
			gameBoard[rowIndex][column - 1] = gamePieces::hiddenEmpty;
			break;
		case gamePieces::flaggedMine:
			gameBoard[rowIndex][column - 1] = gamePieces::hiddenMine;
			break;
		case gamePieces::revealedEmpty:
			cout << "You cannot flag a revealed spot.\n";
			break;
		}
		break;
	case 'r':
	case 'R':
	default:
		cout << "Choose a row to reveal (A-";
		if (gameBoardSizeBasedOnDifficulty <= 25)
		{
			cout << char(gameBoardSizeBasedOnDifficulty + 'A' - 1) << "): ";
		}
		else 
		{
			cout << "Z, [, \\, ], or ^): ";
		}
		cin >> row;
		while (row < 'A' || row >= gameBoardSizeBasedOnDifficulty + 'A')
		{
			cout << "Choose a row to reveal (A-";
			if (gameBoardSizeBasedOnDifficulty <= 25)
			{
				cout << char(gameBoardSizeBasedOnDifficulty + 'A' - 1) << "): ";
			}
			else
			{
				cout << "Z, [, \\, ], or ^): ";
			}
			cin >> row;
		}
		rowIndex = row - 'A';

		cout << "Choose a column to reveal (1-" << gameBoardSizeBasedOnDifficulty << "): ";
		cin >> column;
		while (column < 1 || column > gameBoardSizeBasedOnDifficulty)
		{
			cout << "Choose a column to reveal (1-" << gameBoardSizeBasedOnDifficulty << "): ";
			cin >> column;
		}

		switch (gameBoard[rowIndex][column - 1])
		{
		case gamePieces::hiddenEmpty:
			gameBoard[rowIndex][column - 1] = gamePieces::revealedEmpty;
			break;
		case gamePieces::hiddenMine:
			gameBoard[rowIndex][column - 1] = gamePieces::revealedMine;
			break;
		case gamePieces::flaggedEmpty:
		case gamePieces::flaggedMine:
		case gamePieces::revealedEmpty:
			cout << "You cannot reveal a flagged or already revealed spot.\n";
			break;
		}
		break;
	}
	cout << endl;
	system("PAUSE");
	system("CLS");
}

bool gameIsNotDone(gamePieces gameBoard[gameBoardSize][gameBoardSize], bool & noRevealedMines, bool & unrevealedSafeSpots, bool & allMinesFlagged)
{
	noRevealedMines = true;
	unrevealedSafeSpots = false;
	allMinesFlagged = true;

	for (int i{ 0 }; i < gameBoardSizeBasedOnDifficulty; i++)
	{
		for (int j{ 0 }; j < gameBoardSizeBasedOnDifficulty; j++)
		{
			if (gameBoard[i][j] == gamePieces::hiddenEmpty)
			{
				unrevealedSafeSpots = true;
			}
			if (gameBoard[i][j] == gamePieces::revealedMine)
			{
				noRevealedMines = false;
			}
			if (gameBoard[i][j] == gamePieces::hiddenMine || gameBoard[i][j] == gamePieces::revealedMine)
			{
				allMinesFlagged = false;
			}
			if (!noRevealedMines)
			{
				return false;
			}
		}
	}
	if (noRevealedMines && unrevealedSafeSpots && !allMinesFlagged)
	{
		return true;
	}
	return false;
}
