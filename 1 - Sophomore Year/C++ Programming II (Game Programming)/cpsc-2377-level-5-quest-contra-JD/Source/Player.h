#ifndef PLAYER_H
#define PLAYER_H
#include "AnimatedObject.h"

class Player : public AnimatedObject
{
public:
	Player() = delete;
	Player(std::string animationFile, Vector2D position, const GUI& gui);

	void update(Object::Command command, const Player& player1, const std::vector<Block>& blocks) override;

private:
	void moveDown();
	void moveLeft();
	void moveRight();
	void noAction();
	void moveUp();
	void moveJump();

};

#endif // !PLAYER_H
