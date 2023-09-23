#include "Player.h"
#include "GUI.h"
using namespace std;

Player::Player(Vector2D position, std::string animationFile, const GUI& gui): animation(Animation(animationFile))
{
	objectPart.position.x = position.x;
	objectPart.position.y = position.y + gui.getDimensions(Object::ObjectType::block).y - gui.getDimensions(*this).y;
}

void Player::update(Animation::Command command, const GUI& gui)
{
	switch (command)
	{
	case Animation::Command::down:
		moveDown();
		break;
	case Animation::Command::left:
		moveLeft();
		break;
	case Animation::Command::right:
		moveRight();
		break;
	case Animation::Command::NA:
		noAction();
		break;
	}
	
	int tempHeight{ gui.getDimensions(*this).y };

	animation.updateSprite();

	objectPart.position.y -= (gui.getDimensions(*this).y - tempHeight);

	if (objectPart.position.x < 0)
	{
		objectPart.position.x = 0;
	}

	else if (objectPart.position.x > gui.screenDimensions.x - gui.getDimensions(*this).x)
	{
		objectPart.position.x = gui.screenDimensions.x - gui.getDimensions(*this).x;
	}
}

void Player::setPosition(Vector2D newPosition)
{
	objectPart.position = newPosition;
}

Vector2D Player::getPosition() const
{
	return objectPart.position;
}

int Player::getSprite() const
{
	return animation.getSprite();
}

Animation::State Player::getState() const
{
	return animation.getState();
}

void Player::moveDown()
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

void Player::moveLeft()
{
	switch (animation.getState())
	{
	case Animation::State::stillLeft:
		animation.setState(Animation::State::walkLeft);
		objectPart.position.x -= animation.playerWalkSpeed;
		break;
	case Animation::State::stillRight:
		animation.setState(Animation::State::stillLeft);
		break;
	case Animation::State::walkLeft:
		objectPart.position.x -= animation.playerWalkSpeed;
		break;
	}
}

void Player::moveRight()
{
	switch (animation.getState())
	{
	case Animation::State::stillLeft:
		animation.setState(Animation::State::stillRight);
		break;
	case Animation::State::stillRight:
		animation.setState(Animation::State::walkRight);
		objectPart.position.x += animation.playerWalkSpeed;
		break;
	case Animation::State::walkRight:
		objectPart.position.x += animation.playerWalkSpeed;
		break;
	}
}

void Player::noAction()
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
