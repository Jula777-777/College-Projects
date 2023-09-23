#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <vector>
#include <tuple>
class Player;
class Block;
class Enemy;
class GUI;

#include "Animation.h"

//Game Utilities

std::tuple<Player, std::vector<Enemy>, std::vector<Block>> 
loadGame(
	GUI& gui, 
	const std::string& levelFile, 
	const std::string& playerAnimationFile, 
	const std::string& EnemyAnimationFile);


void changeGameState(Animation::Command command, Player& player1, std::vector<Enemy> & enemies, const GUI& gui);


#endif