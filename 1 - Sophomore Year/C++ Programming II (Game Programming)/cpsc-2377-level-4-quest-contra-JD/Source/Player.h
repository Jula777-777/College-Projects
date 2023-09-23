#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>

#include "Object.h"
#include "Animation.h"

class GUI;
class Block;
class Player
{
public:
	Player(Vector2D position, std::string animationFile, const GUI& gui);

	void update(Animation::Command command, const GUI& gui);
	
	void setPosition(Vector2D newPosition);
	Vector2D getPosition()const;
	int getSprite() const;
	Animation::State getState() const;
private:
		//Helper functions
	void moveDown();
	void moveLeft();
	void moveRight();
	void noAction();

	//Object
	Object objectPart{ Object::ObjectType::player, {0,0} };
	//animations
	Animation animation;
	
};
#endif // !PLAYER_H
