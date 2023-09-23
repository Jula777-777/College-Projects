#include <cstdlib> 
#include <ctime> 
#include <string>
#include <iostream>
#include <fstream>


#include "GUI.h"
#include "Timer.h"

#include "engine.h"
#include "Object.h"
#include "Block.h"
#include "Enemy.h"
#include "Player.h"

using namespace std;

Engine::Engine(
	GUI* gui,
	const std::string& levelFile,
	const std::string& playerAnimationFile,
	const std::string& EnemyAnimationFile):gui(gui)
{
	
	ifstream fin;
	fin.open(levelFile);
	int numRows;
	int numColumns;
	fin >> numRows >> numColumns;
	Player* player1{ nullptr };
	for (int row{ 0 }; row < numRows; row++)
	{
		for (int column{ 0 }; column < numColumns; column++)
		{
			int tempType;
			fin >> tempType;
			Vector2D tempPosition{ column * gui->columnRowDimensions.x,row * gui->columnRowDimensions.y };
			if (Object::Type blockType = (Object::Type)(tempType % 100); blockType != Object::Type::none)
			{
				objects.push_back(new Block(tempPosition, blockType, gui));
			}

			switch ((Object::Type)(tempType - (tempType % 100)))
			{
			case Object::Type::enemy:
				objects.push_back(new Enemy(EnemyAnimationFile, tempPosition, gui));
				tempPosition.y -= gui->getDimensions(objects.back()).y - gui->columnRowDimensions.y;
				objects.back()->setPosition(tempPosition);
				break;
			case Object::Type::player:
			{
				player1 = (new Player(playerAnimationFile, { 0,0 }, gui));
				tempPosition.y -= gui->getDimensions(player1).y - gui->columnRowDimensions.y;
				player1->setPosition(tempPosition);
				break;

			}
			}

		}
		
	}
	objects.push_back(player1);
	
	fin.close();
}
Engine::Engine(const Engine& src)
{
	this->gui = new GUI();
	for (const auto& object : src.objects)
	{
		this->objects.push_back(object->copyMe());
	}

	this->gameOver = src.gameOver;
	this->gameWon = src.gameWon;
}
Engine::Engine(Engine&& src)
{
	this->gui = src.gui;
	src.gui = nullptr;
	for (auto& object : src.objects)
	{
		this->objects.push_back(object->copyMe());
		object = nullptr;
	}

	this->gameOver = src.gameOver;
	this->gameWon = src.gameWon;
}
Engine& Engine::operator=(const Engine& src) noexcept
{
	if (this->gui != nullptr)
	{
		delete gui;
	}
	for (auto& object : this->objects)
	{
		if (object != nullptr)
		{
			delete object;
		}
	}

	this->gui = new GUI();
	for (const auto& object : src.objects)
	{
		this->objects.push_back(object->copyMe());
	}

	this->gameOver = src.gameOver;
	this->gameWon = src.gameWon;

	return *this;
}
Engine& Engine::operator=(Engine&& src) noexcept
{
	if (this->gui != nullptr)
	{
		delete gui;
	}
	for (auto& object : this->objects)
	{
		if (object != nullptr)
		{
			delete object;
		}
	}

	this->gui = src.gui;
	src.gui = nullptr;
	for (auto& object : src.objects)
	{
		this->objects.push_back(object->copyMe());
		object = nullptr;
	}

	this->gameOver = src.gameOver;
	this->gameWon = src.gameWon;

	return *this;
}
Engine::~Engine()
{
	delete gui;
	for (auto& object : objects)
	{
		delete object;
	}
}
bool Engine::getGameOver() const
{
	return gameOver;
}
bool Engine::getGameWon() const
{
	return gameWon;
}

void Engine::changeGameState(Object::Command command)
{
	//This is from my solution to the Level 5 Quest. You need to update this for this quest.
	if (!gameOver && !gameWon)
	{
		for (auto object : objects)
		{
			object->update(command, objects);
		}
	}

	for (const auto& object : objects)
	{
		if (object->getName() == Object::Type::player)
		{
			if (((Player*)object)->getIsDead() || object->getPosition().x >= gui->screenDimensions.x - gui->getDimensions(object).x)
			{
				gameOver = true;
			}
			if (object->getPosition().x >= gui->screenDimensions.x - gui->getDimensions(object).x)
			{
				gameWon = true;
			}
		}
	}
}

std::vector<Object*> Engine::getObjects() const
{
	return objects;
}









