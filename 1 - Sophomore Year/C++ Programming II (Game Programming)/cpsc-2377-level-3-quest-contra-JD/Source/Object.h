#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <map>

struct Vector2D
{
	int x;
	int y;
};

struct Animation
{
	enum class State { stillLeft, stillRight, walkLeft, walkRight, crouchLeft, crouchRight};
	enum class Command { up, down, left, right, attack, NA };
	int currentSprite{ 0 };
	int currentAnimation{ 0 };
	State state{ State::stillRight };

	//Find correct vector using state, use currentAnimation to find currentSprite in vector.
	//When accessing, can be treated like a two dimensional array.
	std::map<State, std::vector<int>> sprites;

	const int walkSpeed{ 12 };
};

struct Object
{
	enum class ObjectType { none, player, block };
	ObjectType type;
	Vector2D position{ 0,0 };
};
struct Player
{
	//Object
	Object objectPart{ Object::ObjectType::player, {0,0} };

	//animations
	Animation animation;
};
struct Block
{
	Object objectPart{ Object::ObjectType::block, {0,0} };
};

#endif