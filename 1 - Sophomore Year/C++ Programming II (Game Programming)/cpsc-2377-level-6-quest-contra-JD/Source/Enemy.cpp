#include "Enemy.h"
#include "Player.h"

using namespace std;

Enemy::Enemy(std::string animationFile, Vector2D columnRow, const GUI* gui) : AnimatedObject(animationFile, position, Type::enemy, gui) {}

void Enemy::update(Object::Command command, const std::vector<Object*>& objects)
{
	for (const auto& object : objects)
	{
		if (object->getName() == Object::Type::player)
		{
			if (object->getPosition() < position)
			{
				state = State::stillLeft;
			}
			else
			{
				state = State::stillRight;
			}
		}
	}

	updateSprite();
}

Object* Enemy::copyMe()
{
	return new Enemy(*this);
}
