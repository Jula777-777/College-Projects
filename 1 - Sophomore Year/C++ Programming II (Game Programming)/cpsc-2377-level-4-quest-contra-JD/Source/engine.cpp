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




std::tuple<Player, std::vector<Enemy>, std::vector<Block>> 
loadGame(
	GUI& gui,
	const std::string& levelFile,
	const std::string& playerAnimationFile,
	const std::string& EnemyAnimationFile)
{
	vector<Block> blocks;
	vector<Enemy> enemies;
	Player player1({ 0,0 }, playerAnimationFile, gui);
	ifstream fin;
	fin.open(levelFile);

	//topCheck keeps track of whether there was a block in this column on the previous row 
	//to decide Block::top


	//while we are not past the edge of the screen.
	for (int row{ 0 }; row < GUI::numRows; row++)
	{
		for (int column{ 0 }; column < GUI::numColumns; column++)
		{
			int tempType;
			fin >> tempType;
			switch ((Object::ObjectType)tempType)
			{
			case Object::ObjectType::block:
				blocks.push_back
				(
					Block(
						{ column * gui.getDimensions(Object::ObjectType::block).x, 
						row * gui.getDimensions(Object::ObjectType::block).y }
					)
				);
				break;
			case Object::ObjectType::enemy:
				enemies.push_back(Enemy(
					{ column * gui.getDimensions(Object::ObjectType::block).x,
							row * gui.getDimensions(Object::ObjectType::block).y },
					EnemyAnimationFile, gui
				));
				break;
			case Object::ObjectType::player:
			{
				Vector2D tempPosition{ column * gui.getDimensions(Object::ObjectType::block).x,
						row * gui.getDimensions(Object::ObjectType::block).y };
				tempPosition.y -= gui.getDimensions(player1).y - gui.getDimensions(Object::ObjectType::block).y;
				player1.setPosition(tempPosition);
				break;
			}
			default:
				break;
			}

		}
	}
	fin.close();
	return{ player1, enemies, blocks };
}

void changeGameState(Animation::Command command, Player& player1, std::vector<Enemy> & enemies, const GUI& gui)
{
	player1.update(command, gui);
	for (auto& enemy : enemies)
	{
		enemy.update(player1, gui);
	}
}










