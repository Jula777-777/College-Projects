#include <fstream>
#include <random>
#include "engine.h"

void loadBackground(const string& gameFile, int& numBlocks, Object blocks[])
{
	ifstream fin;
	fin.open(gameFile);
	
	fin >> numBlocks;
	for (int i{ 0 }; i < numBlocks; i++)
	{
		fin >> blocks[i].position.x >> blocks[i].position.y;
	}

	fin.close();

}

Object initializePlayer(const GUI& gui, const int numBlocks, const Object blocks[])
{
	Object player{ Object::Type::Player};

	random_device seed;
	default_random_engine e(seed());

	uniform_int_distribution<int> playerSprite(0, maxPlayerStates);
	player.sprite = playerSprite(e);

	uniform_int_distribution<int> xPosition(gui.getSpriteDimensions(player).x, screenDimensions.x);
	player.position.x = xPosition(e) - gui.getSpriteDimensions(player).x;

	player.position.y = getMaxYOfBlock(gui, player, numBlocks, blocks);

	return player;
}

int getMaxYOfBlock(const GUI& gui, const Object& player, const int numBlocks, const Object blocks[])
{
	int yPosition{ screenDimensions.y - gui.getSpriteDimensions(player).y};

	for (int i{ 0 }; i < numBlocks; i++)
	{
		if (player.position.x >= blocks[i].position.x && player.position.x <= blocks[i].position.x + gui.getSpriteDimensions(blocks[i]).x && blocks[i].position.y < yPosition)
		{
			yPosition = blocks[i].position.y;
		}
	}

	return yPosition - gui.getSpriteDimensions(player).y;
}
