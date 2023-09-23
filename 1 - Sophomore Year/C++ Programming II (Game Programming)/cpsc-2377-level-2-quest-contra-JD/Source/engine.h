#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include "constants.h"
#include "GUI.h"

using namespace std;

void loadBackground(const string& gameFile, int& numBlocks, Object blocks[]);
Object initializePlayer(const GUI& gui, const int numBlocks, const Object blocks[]);
int getMaxYOfBlock(const GUI& gui, const Object& player, const int numBlocks, const Object blocks[]);

#endif