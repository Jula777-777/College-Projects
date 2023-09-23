#ifndef BLOCK_H
#define BLOCK_H
#include "Object.h"

class Block : public Object
{
public:
	Block() = delete;
	Block(Vector2D position, Object::Type name, const GUI& gui);

	void update(Object::Command command, const Player& player1, const std::vector<Block>& blocks) override {};

};

#endif // !BLOCK_H

