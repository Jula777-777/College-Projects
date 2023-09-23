#include <cstdlib> 
#include <ctime> 
#include <string>
#include <iostream>
#include <fstream>


#include "GUI.h"
#include "Timer.h"

#include "engine.h"
#include "Object.h"

using namespace std;

std::vector<Block> loadBlockData(const std::string& gameFile, const GUI& gui)
{
	vector<Block> blocks;

	ifstream fin;
	fin.open(gameFile);

	if (!fin.is_open())
	{
		cout << "Error opening file.\n";
		return vector<Block>();
	}

	for (int row{ 0 }; row < gui.numRows; row++)
	{
		for (int column{ 0 }; column < gui.numColumns; column++)
		{
			int valueOfSpot;
			fin >> valueOfSpot;

			Block tempBlock;

			switch (valueOfSpot)
			{
			case 2:
				tempBlock.objectPart.position.x = column * gui.getDimensions(tempBlock.objectPart.type).x;
				tempBlock.objectPart.position.y = gui.screenDimensions.y - ((gui.numRows - row ) * gui.getDimensions(tempBlock.objectPart.type).y);
				
				blocks.push_back(tempBlock);
				break;
			}
			
		}
	}
	fin.close();

	return blocks;
}

std::tuple<Player, std::vector<Block>> loadGame(GUI& gui, const std::string& backgroundFile, const std::string& animationFile)
{
	return { loadPlayerData(gui, animationFile), loadBlockData(backgroundFile, gui) };
}

Player loadAnimations(std::string animationFile)
{
	Player tempPlayer;

	ifstream fin;
	fin.open(animationFile);
	
	if (!fin.is_open())
	{
		cout << "Error opening file.\n";
		return Player();
	}

	int numOfStates;
	fin >> numOfStates;

	for (int i{ 0 }; i < numOfStates; i++)
	{
		int numOfAnimations;
		fin >> numOfAnimations;

		for (int j{ 0 }; j < numOfAnimations; j++)
		{
			int tempSprite;
			fin >> tempSprite;

			tempPlayer.animation.sprites[(Animation::State)i].push_back(tempSprite);
		}
	}
	fin.close();

	return tempPlayer;
}

Player loadPlayerData(const GUI& gui, std::string gameFile)
{
	Player player {loadAnimations(gameFile) };

	player.animation.state = Animation::State::stillRight;
	player.animation.currentSprite = 1;
	player.animation.currentAnimation = 0;

	player.objectPart.position.x = 0;
	player.objectPart.position.y = gui.screenDimensions.y - gui.getDimensions(player).y - gui.getDimensions(Object::ObjectType::block).y;

	return player;
}

void changeGameState(Animation::Command command, Player& player1, const GUI& gui)
{
	switch (command)
	{
	case Animation::Command::down:
		moveDown(player1);
		break;
	case Animation::Command::left:
		moveLeft(player1);
		break;
	case Animation::Command::right:
		moveRight(player1);
		break;
	case Animation::Command::NA:
		noAction(player1);
		break;
	}

	int tempHeight{ gui.getDimensions(player1).y };

	updateSprite(player1);

	if (gui.getDimensions(player1).y != tempHeight)
	{
		player1.objectPart.position.y -= (gui.getDimensions(player1).y - tempHeight);
	}

	if (player1.objectPart.position.x < 0)
	{
		player1.objectPart.position.x = 0;
	}

	if (player1.objectPart.position.x > gui.screenDimensions.x - gui.getDimensions(player1).x)
	{
		player1.objectPart.position.x = gui.screenDimensions.x - gui.getDimensions(player1).x;
	}
}

void updateSprite(Player& player1)
{
	player1.animation.currentAnimation++;
	player1.animation.currentAnimation %= player1.animation.sprites[player1.animation.state].size();
	player1.animation.currentSprite = player1.animation.sprites[player1.animation.state][player1.animation.currentAnimation];
}

void moveDown(Player& player1)
{
	switch (player1.animation.state)
	{
	case Animation::State::stillLeft:
		player1.animation.state = Animation::State::crouchLeft;
		break;
	case Animation::State::stillRight:
		player1.animation.state = Animation::State::crouchRight;
		break;
	}
}

void moveLeft(Player& player1)
{
	switch (player1.animation.state)
	{
	case Animation::State::stillLeft:
		player1.animation.state = Animation::State::walkLeft;
		player1.objectPart.position.x -= player1.animation.walkSpeed;
		break;
	case Animation::State::stillRight:
		player1.animation.state = Animation::State::stillLeft;
		break;
	case Animation::State::walkLeft:
		player1.objectPart.position.x -= player1.animation.walkSpeed;
		break;
	}
}

void moveRight(Player& player1)
{
	switch (player1.animation.state)
	{
	case Animation::State::stillLeft:
		player1.animation.state = Animation::State::stillRight;
		break;
	case Animation::State::stillRight:
		player1.animation.state = Animation::State::walkRight;
		player1.objectPart.position.x += player1.animation.walkSpeed;
		break;
	case Animation::State::walkRight:
		player1.objectPart.position.x += player1.animation.walkSpeed;
		break;
	}
}

void noAction(Player& player1)
{
	switch (player1.animation.state)
	{
	case Animation::State::walkLeft:
		player1.animation.state = Animation::State::stillLeft;
		break;
	case Animation::State::walkRight:
		player1.animation.state = Animation::State::stillRight;
		break;
	case Animation::State::crouchLeft:
		player1.animation.state = Animation::State::stillLeft;
		break;
	case Animation::State::crouchRight:
		player1.animation.state = Animation::State::stillRight;
		break;
	}
}
