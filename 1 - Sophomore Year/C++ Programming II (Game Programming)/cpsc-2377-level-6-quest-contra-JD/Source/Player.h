#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>

#include "AnimatedObject.h"

class GUI;
class Block;
class Player: public AnimatedObject
{
public:
	Player() = delete;
	Player(std::string animationFile, Vector2D columnRow, const GUI* gui);


	void update(Object::Command command, const std::vector<Object*>& objects) override;
	bool getIsDead();

	Object* copyMe() override;
private:
		//Helper functions
	void moveDown();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveJump();
	void noAction();

	bool isDead{ false };

	
};

bool lastBlockOnScreen(const std::vector<Object*>& objects);

#endif // !PLAYER_H
