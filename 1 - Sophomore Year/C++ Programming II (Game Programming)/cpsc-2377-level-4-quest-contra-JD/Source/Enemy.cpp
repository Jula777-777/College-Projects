#include <cstdlib>
#include "Enemy.h"
#include "GUI.h"
#include "Player.h"
using namespace std;

Enemy::Enemy(Vector2D position, std::string animationFile, const GUI& gui): animation(animationFile)
{
	objectPart.position.x = position.x;
	objectPart.position.y = position.y + gui.getDimensions(Object::ObjectType::block).y - gui.getDimensions(*this).y;
}

void Enemy::update(const Player& player1, const GUI& gui)
{
	if (player1.getState() == Animation::State::crouchLeft || player1.getState() == Animation::State::crouchRight)
	{
		noAction();
		moveDown();
	}

	//This else-if statement makes the enemies stop moving if they get very close to the player.
	else if (abs(player1.getPosition().x - objectPart.position.x) < gui.getDimensions(player1).x / 4)
	{
		noAction();
	}

	else if (player1.getPosition() < objectPart.position)
	{
		noAction();
		moveLeft();
	}

	else
	{
		noAction();
		moveRight();
	}

	int tempHeight{ gui.getDimensions(*this).y };

	animation.updateSprite();

	objectPart.position.y -= (gui.getDimensions(*this).y - tempHeight);

	//This if statment forces the enemy on the higher platform to stay on its platform. 513 is the enemy's y-position. 850 is the x-position of the left side of the platform.
	if (objectPart.position.y == 513)
	{
		if (objectPart.position.x < 850)
		{
			objectPart.position.x = 850;
			noAction();
			animation.updateSprite();
		}
		else if (objectPart.position.x > gui.screenDimensions.x - gui.getDimensions(*this).x)
		{
			objectPart.position.x = gui.screenDimensions.x - gui.getDimensions(*this).x;
		}
	}

	//This else-if statment forces the enemy on the lower platform to stay on its platform. 563 is the enemy's y-position. 700 is the x-position of the left side of the platform.
	else if (objectPart.position.y == 563)
	{
		if (objectPart.position.x < 700)
		{
			objectPart.position.x = 700;
			noAction();
			animation.updateSprite();
		}
		else if (objectPart.position.x > gui.screenDimensions.x - gui.getDimensions(*this).x)
		{
			objectPart.position.x = gui.screenDimensions.x - gui.getDimensions(*this).x;
		}
	}
}

Vector2D Enemy::getPosition() const
{
	return objectPart.position;
}

int Enemy::getSprite() const
{
	return animation.getSprite();
}

void Enemy::moveDown()
{
	switch (animation.getState())
	{
	case Animation::State::stillLeft:
		animation.setState(Animation::State::crouchLeft);
		break;
	case Animation::State::stillRight:
		animation.setState(Animation::State::crouchRight);
		break;
	}
}

void Enemy::moveLeft()
{
	switch (animation.getState())
	{
	case Animation::State::stillLeft:
		animation.setState(Animation::State::walkLeft);
		objectPart.position.x -= animation.enemyWalkSpeed;
		break;
	case Animation::State::stillRight:
		animation.setState(Animation::State::stillLeft);
		break;
	case Animation::State::walkLeft:
		objectPart.position.x -= animation.enemyWalkSpeed;
		break;
	}
}

void Enemy::moveRight()
{
	switch (animation.getState())
	{
	case Animation::State::stillLeft:
		animation.setState(Animation::State::stillRight);
		break;
	case Animation::State::stillRight:
		animation.setState(Animation::State::walkRight);
		objectPart.position.x += animation.enemyWalkSpeed;
		break;
	case Animation::State::walkRight:
		objectPart.position.x += animation.enemyWalkSpeed;
		break;
	}
}

void Enemy::noAction()
{
	switch (animation.getState())
	{
	case Animation::State::walkLeft:
		animation.setState(Animation::State::stillLeft);
		break;
	case Animation::State::walkRight:
		animation.setState(Animation::State::stillRight);
		break;
	case Animation::State::crouchLeft:
		animation.setState(Animation::State::stillLeft);
		break;
	case Animation::State::crouchRight:
		animation.setState(Animation::State::stillRight);
		break;
	}
}
