#ifndef OBJECT_H
#define OBJECT_H
#include <vector>

class GUI;
class Block;
class Player;

struct Vector2D
{
	int x;
	int y;
	friend bool operator<(const Vector2D& srcL, const Vector2D& srcR)
	{
		return srcL.x < srcR.x;
	}
};

class Object
{
public:
	enum class Command { up, down, left, right, attack, jump, NA };
	enum class Type 
	{ 
		none, 
		bridge_center, 
		bridge_end, 
		bridge_start, 
		center_block, 
		top_block, 
		tree_background, 
		water, water_shore, 
		water_top, 
		water_wall, 
		water_wall_corner, 
		player = 100, 
		enemy = 200 
	};

	Object() = delete;
	Object(Vector2D position, Type name, const GUI& gui);

	Vector2D getPosition() const;
	void setPosition(Vector2D newPosition);
	Vector2D getDimensions() const;
	Type getName() const;
	virtual void update(Object::Command command, const Player& player1, const std::vector<Block>& blocks) = 0;

protected:
	const Type name{ Type::none };
	Vector2D position{ 0, 0 };
	const GUI& gui;

};

#endif // !OBJECT_H