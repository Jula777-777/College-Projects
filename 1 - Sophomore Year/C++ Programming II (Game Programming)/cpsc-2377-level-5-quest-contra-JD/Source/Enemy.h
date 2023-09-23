#ifndef ENEMY_H
#define ENEMY_H
#include "AnimatedObject.h"

class Enemy : public AnimatedObject
{
public:
	Enemy() = delete;
	Enemy(std::string animationFile, Vector2D position, const GUI& gui);

	void update(Object::Command command, const Player& player1, const std::vector<Block>& blocks) override;

};

#endif // !ENEMY_H
