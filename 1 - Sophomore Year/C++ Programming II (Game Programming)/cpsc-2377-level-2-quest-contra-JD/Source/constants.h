#ifndef CONSTANTS_H
#define CONSTANTS_H

struct Vector2D
{
	int x{ 0 };
	int y{ 0 };
};

struct Object
{
	enum class Type { Player, Block, numTypes };
	Type type{ Type::Block };
	Vector2D position;
	int sprite{ 0 };
	//Vector2D dimensions;
};

Vector2D const screenDimensions{ 600, 400 };

//number of blocks in the text file may be less than this!

//Player constants
const int maxPlayerStates = 10;

#endif