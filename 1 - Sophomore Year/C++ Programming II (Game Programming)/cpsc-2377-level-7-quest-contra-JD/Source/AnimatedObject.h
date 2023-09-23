#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H
#include <map>
#include <vector>
#include <string>
#include "Object.h"

class AnimatedObject : public Object
{
public:
	AnimatedObject() = delete;
	AnimatedObject(std::string animationFile, Vector2D position, Type name, const GUI* gui);
	
	int getCurrentSprite() const;
	
	enum class State { stillLeft, stillRight, walkLeft, walkRight, crouchLeft, crouchRight, upLeft, upRight, jumpLeft, jumpRight };
	State getState() const;

	int life{ 10 };

protected:
	void doPhysics(const std::vector<Object*> objects);
	void applyGravity();
	bool collision(const Object* object, bool full = false);
	void updateSprite();

	const int walkSpeed{ 12 };
	const int jumpStrength{ 35 };
	Vector2D velocity{ 0,0 };
	
	static const float deltaT;
	static const Vector2D gravity;
	static const Vector2D terminalVelocity;

	int currentSprite{ 0 };
	int currentAnimation{ 0 };
	State state{ State::stillRight };
	std::map<State, std::vector<int>> sprites;

	void moveDown();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveJump();
	bool moveShoot();
	void noAction();

};
#endif // !ANIMATION_H
