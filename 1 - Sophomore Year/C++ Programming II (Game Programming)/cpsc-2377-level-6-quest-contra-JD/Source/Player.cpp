#include <fstream>
#include <iostream>
#include "Player.h"
#include "GUI.h"
#include "Block.h"

using namespace std;
Player::Player(std::string animationFile, Vector2D columnRow, const GUI* gui) : AnimatedObject(animationFile, position, Object::Type::player, gui)
{
}

void Player::update(Object::Command command, const std::vector<Object*>& objects)
{
	switch (command) {

	case Object::Command::right:moveRight(); break;
	case Object::Command::left:moveLeft(); break;
	case Object::Command::down:moveDown(); break;
	case Object::Command::up:moveUp(); break;
	case Object::Command::jump:moveJump(); break;
	case Object::Command::NA:noAction(); break;
	}

	for (const auto& object : objects)
	{
		if (object->getName() == Type::enemy)
		{
			if (collision(object, true))
			{
				isDead = true;
			}
		}
	}

	doPhysics(objects);
	//sprite update and height adjustment
	int tempHeight{ (int)gui->getDimensions(this).y };
	updateSprite();
	position.y -= gui->getDimensions(this).y - tempHeight;

	//border detection.
	if (position.y > gui->screenDimensions.y)
	{
		isDead = true;
	}
	if (position.x < 0)
	{
		position.x = 0;
	}
	else if (position.x > gui->screenDimensions.x / 2 && !lastBlockOnScreen(objects))
	{
		for (auto object : objects)
		{
			if (object->getName() != Type::player)
			{
				object->setPosition({ object->getPosition().x - (position.x - gui->screenDimensions.x / 2), object->getPosition().y });
			}
		}
		position.x -= walkSpeed;
	}
}

bool Player::getIsDead()
{
	return isDead;
}

Object* Player::copyMe()
{
	return new Player(*this);
}

void Player::moveRight()
{
	switch (state)
	{
	case State::stillLeft:
		state = State::stillRight;
		break;
	case State::stillRight:
		state = State::walkRight;
		break;
	case State::walkRight:
		position.x += walkSpeed;
		break;
	case State::jumpRight:
		position.x += walkSpeed;
	}
}

void Player::moveLeft()
{
	switch (state)
	{
	case State::stillRight:
		state = State::stillLeft;
		break;
	case State::stillLeft:
		state = State::walkLeft;
		break;
	case State::walkLeft:
		position.x -= walkSpeed;
		break;
	case State::jumpLeft:
		position.x -= walkSpeed;
	default:
		break;
	}
}

void Player::moveDown()
{
	switch (state)
	{
	case State::stillLeft:
		state = State::crouchLeft;
		break;
	case State::stillRight:
		state = State::crouchRight;
		break;
	}
}

void Player::moveJump()
{
	if (velocity.y == 0)
	{
		switch (state)
		{
		case State::stillRight:
			state = State::jumpRight;
			velocity.y = -jumpStrength;
			break;
		case State::stillLeft:
			state = State::jumpLeft;
			velocity.y = -jumpStrength;
			break;
		case State::jumpRight:
			break;
		case State::jumpLeft:
			break;
		case State::crouchLeft:
		case State::crouchRight:
			position.y += gravity.y + 9;
		default:
			break;
		}

	}
}

void Player::moveUp()
{
	switch (state)
	{
	case State::stillLeft:
		state = State::upLeft;
		position.x += 12;
		break;
	case State::stillRight:
		state = State::upRight;
		position.x += 6;
		break;
	}
}

void Player::noAction()
{
	switch (state)
	{
	case State::walkLeft:
	case State::crouchLeft:
		state = State::stillLeft;
		break;
	case State::walkRight:
	case State::crouchRight:
		state = State::stillRight;
		break;
	case State::upLeft:
		state = State::stillLeft;
		position.x -= 12;
		break;
	case State::upRight:
		state = State::stillRight;
		position.x -= 6;
	}
}

bool lastBlockOnScreen(const std::vector<Object*>& objects)
{
	int maxXValue{ 0 };
	for (const auto& object : objects)
	{
		if (object->getPosition().x > maxXValue && object->getName() != Object::Type::player)
		{
			maxXValue = object->getPosition().x;
		}
	}
	if (maxXValue <= GUI::screenDimensions.x - 50)
	{
		return true;
	}
	return false;
}
