#include "Block.h"

Block::Block(Vector2D position)
{
	objectPart.position = position;
}

Object::ObjectType Block::getType()
{
	return objectPart.type;
}

Vector2D Block::getPosition() const
{
	return objectPart.position;
}

void Block::setPosition(Vector2D position)
{
	objectPart.position = position;
}
