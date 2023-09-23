#include "ObjectFactory.h"
#include "Block.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "GUI.h"
#include "Heart.h"
#include "Tank.h"
#include "Dragon.h"


Object* BlockFactory::create(Initialilzers list)
{
	return new Block(list.position, list.name, list.gui);
}

Object* PlayerFactory::create(Initialilzers list)
{
	player = new Player("./Assets/data/animation.txt", list.position, list.gui);
	player->setPosition({ list.position.x, list.position.y + list.gui->columnRowDimensions.y - list.gui->getDimensions(player).y });
	return player;
}

Object* EnemyFactory::create(Initialilzers list)
{
	Enemy* enemy{ new Enemy("./Assets/data/animation.txt", list.position, list.gui, player) };
	enemy->setPosition({ list.position.x, list.position.y + list.gui->columnRowDimensions.y - list.gui->getDimensions(enemy).y });
	return enemy;
}

Object* BulletFactory::create(Initialilzers list)
{
	Vector2D position{ list.creator->getPosition() };
	Vector2D target{ position };

	if (list.name == Object::Type::bullet)
	{
		switch (((Player*)list.creator)->getState())
		{
		case AnimatedObject::State::stillLeft:
		case AnimatedObject::State::stillRight:
			position.y += 12;
			break;
		case AnimatedObject::State::crouchLeft:
		case AnimatedObject::State::crouchRight:
			position.y += 5;
			break;
		case AnimatedObject::State::upLeft:
			position.x += 4;
			break;
		case AnimatedObject::State::upRight:
			position.x += 11;
			break;
		}

		target = position;

		switch (((Player*)list.creator)->getState())
		{
		case AnimatedObject::State::stillLeft:
		case AnimatedObject::State::crouchLeft:
			position.x -= 2;
			target.x = position.x - 3;
			break;
		case AnimatedObject::State::stillRight:
		case AnimatedObject::State::crouchRight:
			position.x += list.gui->getDimensions(list.creator).x;
			target.x = position.x + 3;
			break;
		case AnimatedObject::State::upLeft:
		case AnimatedObject::State::upRight:
			position.y -= 2;
			target.y = position.y - 3;
			break;
		}
	}

	else if (list.name == Object::Type::cannonball)
	{
		position.x -= 25;
		position.y += 11;
		target = { position.x - 3, position.y };
	}

	else
	{
		position.x += 80;
		position.y += 30;
		target = { position.x - 3, position.y - 1 };
	}

	return new Bullet(position, list.creator, target, list.gui, list.name);
	
}

Object* HeartFactory::create(Initialilzers list)
{
	return new Heart(list.position, list.name, list.gui);
}

Object* TankFactory::create(Initialilzers list)
{
	Tank* tank{ new Tank(list.position, list.name, list.gui) };
	tank->setPosition({ list.position.x, list.position.y - list.gui->getDimensions(tank).y });
	return tank;
}

Object* DragonFactory::create(Initialilzers list)
{
	Dragon* dragon{ new Dragon(list.position, list.name, list.gui) };
	dragon->setPosition({ list.position.x, list.position.y - list.gui->getDimensions(dragon).y + 50 });
	return dragon;
}
