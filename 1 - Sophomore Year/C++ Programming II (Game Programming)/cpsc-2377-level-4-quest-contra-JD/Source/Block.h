#ifndef BLOCK_H
#define BLOCK_H
#include "Object.h"
class Block
{
public:
	Block(Vector2D position);

	Object::ObjectType getType();
	Vector2D getPosition() const;
	void setPosition(Vector2D position);

private:
	Object objectPart{ Object::ObjectType::block, {0,0} };
};
#endif // !BLOCK_H
