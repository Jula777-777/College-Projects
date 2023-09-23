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
	GUI& gui,
	const std::string& levelFile,
	const std::string& playerAnimationFile,
	const std::string& EnemyAnimationFile):player1(playerAnimationFile, { 0,0 }, gui), gui(gui)
{
	
	ifstream fin;
	fin.open(levelFile);
	
	for (int row{ 0 }; row < GUI::numColumnsRows.y; row++)
	{
		for (int column{ 0 }; column < GUI::numColumnsRows.x; column++)
		{
			int tempType;
			fin >> tempType;
			Vector2D tempPosition{ column * gui.columnRowDimensions.x,row * gui.columnRowDimensions.y };
			if (Object::Type blockType = (Object::Type)(tempType % 100); blockType != Object::Type::none)
			{
				blocks.push_back(Block(tempPosition, blockType, gui));
			}

			switch ((Object::Type)(tempType - (tempType % 100)))
			{
			case Object::Type::enemy:
				enemies.push_back(Enemy(EnemyAnimationFile, tempPosition, gui));
				tempPosition.y -= gui.getDimensions(enemies.back()).y - gui.columnRowDimensions.y;
				enemies.back().setPosition(tempPosition);
				break;
			case Object::Type::player:
			{
				tempPosition.y -= gui.getDimensions(player1).y - gui.columnRowDimensions.y;
				player1.setPosition(tempPosition);
				break;
			}
			}

		}
	}
	fin.close();
}

void Engine::changeGameState(Object::Command command)
{
	player1.update(command,player1, blocks);
	for (auto& enemy : enemies)
	{
		enemy.update(command, player1, blocks);
	}
	for (auto block : blocks)
	{
		block.update(command, player1, blocks);
	}
}

std::tuple < const Player&, const std::vector<Enemy>&, const std::vector<Block>&> Engine::getObjects() const
{
	return { player1, enemies, blocks };
}









