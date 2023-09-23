#include <random>
#include "Enemy.h"
#include "GUI.h"
#include "Player.h"
#include "Bullet.h"
#include "FactoryLibrary.h"
#include "ObjectFactory.h"

Enemy::Enemy(std::string animationFile, Vector2D position, const GUI* gui, Player* player): AnimatedObject(animationFile, position, Object::Type::enemy, gui), attachedPlayer(player)
{
	life = 1;
}

Object* Enemy::update(Object::Command command, const std::vector<Object*>& objects, FactoryLibrary* factories)
{
	Object* bullet{ nullptr };

	if (life <= 0)
	{
		kill();
	}

	if (position.x <= gui->screenDimensions.x && position.x + gui->getDimensions(this).x >= 0 && !getIsDead())
	{
		attachedPlayer->attach(this);
	}
	else if (position.x > gui->screenDimensions.x || position.x + gui->getDimensions(this).x < 0 || getIsDead())
	{
		attachedPlayer->detach(this);
	}
	
	std::random_device seed;
	std::default_random_engine e(seed());
	std::bernoulli_distribution shootChance(0.2);

	if (attachedPlayer != nullptr && attachedPlayer->getPosition().y == position.y && shootChance(e) == 1)
	{
		Initialilzers list(gui, objects);
		list.creator = this;
		list.name = Type::bullet;
		bullet = factories->library[list.name]->create(list);
	}

	return bullet;
}

Object* Enemy::copyMe()
{
	return new Enemy(*this);
}

void Enemy::notify(Player* player)
{
	if (player != nullptr)
	{
		if (position < player->getPosition())
		{
			state = State::stillRight;
		}
		else
		{
			state = State::stillLeft;
		}
	}

	updateSprite();
	
}
