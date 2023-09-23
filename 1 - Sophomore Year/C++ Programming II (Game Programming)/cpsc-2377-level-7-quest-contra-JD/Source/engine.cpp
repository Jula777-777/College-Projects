#include <cstdlib> 
#include <ctime> 
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>


#include "GUI.h"
#include "Timer.h"

#include "engine.h"
#include "Object.h"
#include "ObjectFactory.h"
#include "FactoryLibrary.h"
//#include "Block.h"
//#include "Enemy.h"
#include "Player.h"

using namespace std;

Engine::Engine(GUI* gui, const std::string& levelFile):gui(gui)
{
	factories = new FactoryLibrary();
	ifstream fin;
	fin.open(levelFile);
	int numRows;
	int numColumns;
	fin >> numRows >> numColumns;
	Initialilzers list(gui, objects);
	for (int row{ 0 }; row < numRows; row++)
	{
		for (int column{ 0 }; column < numColumns; column++)
		{
			int tempType;
			fin >> tempType;
			list.position = { column * gui->columnRowDimensions.x,row * gui->columnRowDimensions.y };
			if (list.name = (Object::Type)(tempType % 100); list.name != Object::Type::none)
			{				
				objects.push_back(factories->library.find(list.name)->second->create(list));
			}
			if (list.name = (Object::Type)(tempType - (tempType % 100)); list.name != Object::Type::none)
			{
				objects.push_back(factories->library.find(list.name)->second->create(list));
			}
		}
		
	}
	fin.close();
	auto playerIter{ 
		find_if(objects.begin(), 
		objects.end(), 
		[](Object* object)->bool {return object->getName() == Object::Type::player; }) 
	};
	objects.push_back(*playerIter);
	objects.erase(playerIter);
	
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
	if (!gameOver)
	{
		/*auto dead{ remove_if(objects.begin(), objects.end(), [](Object* object)->bool {
			return object->getIsDead();
			}) };
		for_each(dead, objects.end(), [](Object* object)->void {delete object; });
		objects.erase(dead, objects.end());*/
		for (auto object{ objects.begin() }; object != objects.end();)
		{
			if ((*object)->getIsDead())
			{
				delete (*object);
				object = objects.erase(object);
			}
			if ((*object)->getName() == Object::Type::heart)
			{
				delete (*object);
				objects.erase(object);
			}
			else
			{
				object++;
			}
		}
		vector<Object*> newObjects;
		for (auto object : objects)
		{
			if (object->getName() == Object::Type::player)
			{
				Initialilzers list(gui, objects);
				list.position = { 0, 0 };
				list.name = Object::Type::heart;

				for (int i{ 0 }; i < ((Player*)object)->life; i++)
				{
					objects.push_back(factories->library[Object::Type::heart]->create(list));
					list.position.x += gui->columnRowDimensions.x;
				}
			}

			if (Object* temp{ object->update(command, objects, factories) }; temp != nullptr)
			{
				newObjects.push_back(temp);

			}
			for (auto object : newObjects)
			{
				objects.push_back(object);
			}
			newObjects.clear();
			if (object->getName() == Object::Type::player)
			{

				gameOver = 
					((Player*)object)->getIsDead() 
					|| object->getPosition().x + object->getDimensions().x >=GUI::screenDimensions.x;
				gameWon = object->getPosition().y < GUI::screenDimensions.y && !((Player*)object)->getIsDead();
			}
		}
	}
	//cout << gameOver << " ";

}

std::vector<Object*> Engine::getObjects() const
{
	return objects;
}

Engine::~Engine()
{
	for (auto object : objects)
	{
		delete object;
	}

}

Engine::Engine(const Engine& src):gui(src.gui), gameOver(src.gameOver), gameWon(src.gameWon)
{
	for (auto object : src.objects)
	{
		objects.push_back(object->copyMe());
	}
}

Engine::Engine(Engine&& src):gui(src.gui), gameOver(src.gameOver), gameWon(src.gameWon)
{
	for (auto object : src.objects)
	{
		objects.push_back(object);
		object = nullptr;
	}
	src.objects.clear();
}

Engine& Engine::operator=(const Engine& src) noexcept
{
	for (auto object : objects)
	{
		delete object;
	}
	objects.clear();

	for (auto object : src.objects)
	{
		objects.push_back(object->copyMe());
	}
	gameOver = src.gameOver;
	gameWon = src.gameWon;
	return *this;
	
}

Engine& Engine::operator=(Engine&& src) noexcept
{
	for (auto object : objects)
	{
		delete object;
	}
	objects.clear();

	for (auto object : src.objects)
	{
		objects.push_back(object);
		object = nullptr;
	}
	src.objects.clear();
	gameOver = src.gameOver;
	gameWon = src.gameWon;
	return *this;
}









