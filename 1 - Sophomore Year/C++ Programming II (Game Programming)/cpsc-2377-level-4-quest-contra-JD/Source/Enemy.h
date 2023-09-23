#ifndef ENEMY_H
#define ENEMY_H
#include "Object.h"
#include "Animation.h"

class GUI;
class Player;
class Enemy
{
public:
	Enemy(Vector2D position, std::string animationFile, const GUI& gui);

	void update(const Player & player1, const GUI& gui);

	Vector2D getPosition() const;
	int getSprite() const;
private:
	//Helper Functions
	void moveDown();
	void moveLeft();
	void moveRight();
	void noAction();

	//Object
	Object objectPart{ Object::ObjectType::enemy, {0,0} };
	//animations
	Animation animation;
};
#endif // !ENEMY_H
