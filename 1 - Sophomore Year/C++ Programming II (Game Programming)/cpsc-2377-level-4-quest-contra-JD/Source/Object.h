#ifndef OBJECT_H
#define OBJECT_H
#include <vector>
#include <map>


struct Vector2D
{
	int x;
	int y;
	friend bool operator<(const Vector2D & srcL, const Vector2D & srcR)
	{
		return srcL.x < srcR.x;
	}
};

struct Object
{
	enum class ObjectType { none, player, block, enemy };
	ObjectType type;
	Vector2D position{ 0,0 };
};



#endif