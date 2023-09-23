#include "Player.h"
#include "GUI.h"

using namespace std;

Player::Player(std::string animationFile, Vector2D position, const GUI& gui): AnimatedObject(animationFile, position, Type::player, gui) {}

void Player::update(Object::Command command, const Player& player1, const std::vector<Block>& blocks)
{
	switch (command) {

	case Command::right:
		moveRight();
		break;
	case Command::left:
		moveLeft();
		break;
	case Command::down:
		moveDown();
		break;
	case Command::NA:
		noAction();
		break;
	case Command::up:
		moveUp();
		break;
	case Command::jump:
		moveJump();
		break;
	}

	//sprite update and height adjustment
	int tempHeight{ getDimensions().y };
	doPhysics(blocks);
	updateSprite();
	position.y -= getDimensions().y - tempHeight;

	//border detection.
	if (position.x < 0)
	{
		position.x = 0;
	}
	else if (position.x > gui.screenDimensions.x - getDimensions().x)
		position.x = gui.screenDimensions.x - getDimensions().x;
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
	}
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

void Player::moveJump()
{
	switch (state)
	{
	case State::stillLeft:
		state = State::jumpLeft;
		velocity.y -= jumpStrength;
		break;
	case State::stillRight:
		state = State::jumpRight;
		velocity.y -= jumpStrength;
		break;
	}
}
