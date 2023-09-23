#include "Enemy.h"
#include "Player.h"

using namespace std;

Enemy::Enemy(std::string animationFile, Vector2D position, const GUI& gui): AnimatedObject(animationFile, position, Type::enemy, gui) {}

void Enemy::update(Object::Command command, const Player& player1, const std::vector<Block>& blocks)
{
	if (player1.getPosition() < position)
	{
		state = State::stillLeft;
	}
	else
	{
		state = State::stillRight;
	}
	updateSprite();
}
