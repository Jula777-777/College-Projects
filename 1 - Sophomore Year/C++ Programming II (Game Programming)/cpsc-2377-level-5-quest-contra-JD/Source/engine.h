#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <vector>
#include <tuple>

class Block;
class Enemy;
class GUI;

#include "Object.h"
#include "Player.h"

//Game Utilities
class Engine
{
public:
	Engine(
		GUI& gui,
		const std::string& levelFile,
		const std::string& playerAnimationFile,
		const std::string& EnemyAnimationFile);


	void changeGameState(Object::Command command);
	std::tuple < const Player&, const std::vector<Enemy>&, const std::vector<Block>&> getObjects() const;
private:
	std::vector<Block> blocks;
	std::vector<Enemy> enemies;
	Player player1;
	const GUI& gui;
};

#endif