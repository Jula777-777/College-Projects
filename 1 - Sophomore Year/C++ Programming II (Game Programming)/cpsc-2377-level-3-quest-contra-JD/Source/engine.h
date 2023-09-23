#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <vector>
#include <tuple>
struct Player;
struct Block;
class GUI;


//Game Utilities
std::vector<Block> loadBlockData(const std::string& gameFile, const GUI& gui);
std::tuple<Player, std::vector<Block>> loadGame(GUI& gui, const std::string& backgroundFile, const std::string& animationFile);
Player loadAnimations(std::string animationFile);
Player loadPlayerData(const GUI& gui, std::string gameFile);

void changeGameState(Animation::Command command, Player& player1, const GUI& gui);

//Helper functions
void updateSprite(Player& player1);
void moveDown(Player& player1);
void moveLeft(Player& player1);
void moveRight(Player& player1);
void noAction(Player& player1);
#endif