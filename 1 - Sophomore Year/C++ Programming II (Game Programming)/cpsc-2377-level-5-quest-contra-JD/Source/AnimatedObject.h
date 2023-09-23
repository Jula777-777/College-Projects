#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H
#include <map>
#include <string>
#include "Object.h"

class AnimatedObject : public Object
{
public:
	enum class State 
	{ 
		stillLeft, 
		stillRight, 
		walkLeft, 
		walkRight, 
		crouchLeft, 
		crouchRight, 
		upLeft, 
		upRight, 
		jumpLeft, 
		jumpRight 
	};

	AnimatedObject() = delete;
	AnimatedObject(std::string animationFile, Vector2D position, Type name, const GUI& gui);

	int getCurrentSprite() const;

protected:
	const int walkSpeed{ 12 };
	const int jumpStrength{ 35 };
	Vector2D velocity{ 0,0 };
	static const float deltaT;//initialized to 0.5f
	static const Vector2D gravity;//initialized to {0.0f, 10.0f}
	int currentSprite{ 0 };
	int currentAnimation{ 0 };
	State state{ State::stillRight };
	std::map<State, std::vector<int>> sprites;

	void doPhysics(const std::vector<Block>& blocks);
	void applyGravity();
	bool collision(const Object& object);
	void updateSprite();

};

#endif // !ANIMATEDOBJECT_H
