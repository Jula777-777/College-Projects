#include <fstream>
#include <iostream>
#include "Player.h"
#include "GUI.h"
#include "Block.h"
#include "Bullet.h"
#include "Enemy.h"
#include "FactoryLibrary.h"
#include "ObjectFactory.h"

using namespace std;
Player::Player(std::string animationFile, Vector2D position, const GUI* gui): AnimatedObject(animationFile, position, Object::Type::player,gui)
{
	life = 5;
}


bool lastBlockOnScreen(const std::vector<Object*>& objects)
{
	int maxX{ 0 };
	for (auto object : objects)
	{
		if (object->getPosition().x + object->getDimensions().x > maxX && object->getName() != Object::Type::player && object->getName() != Object::Type::bullet && object->getName() != Object::Type::heart)
		{
			maxX = object->getPosition().x + object->getDimensions().x;
		}
	}
	return maxX <= GUI::screenDimensions.x;
}

Object* Player::update(Object::Command command, const std::vector<Object*>& objects, FactoryLibrary* factories)
{
	Object* bullet{ nullptr };
	switch (command) {

	case Object::Command::right:moveRight(); break;
	case Object::Command::left:moveLeft(); break;
	case Object::Command::down:moveDown(); break;
	case Object::Command::up:moveUp(); break;
	case Object::Command::jump:moveJump(); break;
	case Object::Command::NA:noAction(); break;
	case Object::Command::shoot:
		if (moveShoot())
		{
			Initialilzers list(gui, objects);
			list.creator = this;
			list.name = Type::bullet;
			bullet = factories->library[list.name]->create(list);
			break;
		}
	}
	doPhysics(objects);
	//sprite update and height adjustment
	int tempHeight{ (int)gui->getDimensions(this).y };
	updateSprite();
	position.y -= gui->getDimensions(this).y - tempHeight;

	//border detection.
	//left side of screen.
	if (position.x < 0)position.x = 0;


	//half screen.
	else if (position.x > gui->screenDimensions.x / 2 && !lastBlockOnScreen(objects))
	{
		for (auto object : objects)
		{
			if (object->getName() != Object::Type::player && object->getName() != Object::Type::heart)
			{
				object->setPosition({ object->getPosition().x - (position.x - gui->screenDimensions.x / 2), object->getPosition().y });
			}
		}
		position.x = gui->screenDimensions.x / 2;
	}
	//at the edge.
	else if (position.x + getDimensions().x >= GUI::screenDimensions.x) position.x = GUI::screenDimensions.x - getDimensions().x;
	for (auto object : objects)
	{
		if ((object->getName() == Object::Type::enemy || object->getName() == Object::Type::tank) && collision(object, true))
		{
			kill();
		}
	}
	if (position.y > GUI::screenDimensions.y)
	{
		kill();
	}

	if (life <= 0)
	{
		kill();
	}

	notify();
	return bullet;
}

Object* Player::copyMe()
{
	return new Player(*this);
}

void Player::attach(Enemy* enemy)
{
	enemiesToNotify.push_back(enemy);
}

void Player::detach(Enemy* enemy)
{
	if (auto toDelete = find(enemiesToNotify.begin(), enemiesToNotify.end(), enemy); toDelete != enemiesToNotify.end())
	{
		enemiesToNotify.erase(toDelete);
	}
}

void Player::notify()
{
	for (auto enemy : enemiesToNotify)
	{
		if (enemy != nullptr)
		{
			enemy->notify(this);
		}
	}
}



