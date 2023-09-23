#include <iostream>
#include <fstream>
#include "AnimatedObject.h"
#include "Block.h"
#include "GUI.h"

using namespace std;

const float AnimatedObject::deltaT{ 0.5f };
const Vector2D AnimatedObject::gravity{ 0.0f, 10.0f };


AnimatedObject::AnimatedObject(std::string animationFile, Vector2D position, Type name, const GUI& gui): Object(position, name, gui)
{
	fstream fin;
	fin.open(animationFile);
	if (!fin.is_open()) cout << "File does not exist!";


	int numStates;

	fin >> numStates;
	for (int i{ 0 }; i < numStates; i++)
	{
		int numAnimations;
		fin >> numAnimations;
		for (int j{ 0 }; j < numAnimations; j++)
		{
			int spriteSequence;
			fin >> spriteSequence;
			sprites[(State)i].push_back(spriteSequence);
		}
	}
	updateSprite();
}

int AnimatedObject::getCurrentSprite() const
{
	return currentSprite;
}

void AnimatedObject::doPhysics(const std::vector<Block>& blocks)
{
	applyGravity();

	for (int i{ 0 }; i < blocks.size(); i++)
	{
		switch (blocks.at(i).getName())
		{
		case Type::bridge_center:
		case Type::bridge_end:
		case Type::bridge_start:
		case Type::top_block:
		case Type::water_top:

			if (collision(blocks.at(i)))
			{
				position.y = blocks.at(i).getPosition().y - getDimensions().y;
				switch (state)
				{
				case State::jumpLeft:
					state = State::stillLeft;
					velocity.y = 0;
					break;
				case State::jumpRight:
					state = State::stillRight;
					velocity.y = 0;
					break;
				}
			}
			break;
		}
	}
}

void AnimatedObject::applyGravity()
{
	if (state == State::jumpLeft || state == State::jumpRight || position.x < 50)
	{
		position.y += (velocity.y * deltaT);
		velocity.y += (gravity.y * deltaT);
	}
}

bool AnimatedObject::collision(const Object& object)
{
	bool leftSideCollides{ position.x > object.getPosition().x && position.x < object.getPosition().x + object.getDimensions().x };
	bool rightSideCollides{ position.x + getDimensions().x > object.getPosition().x && position.x + getDimensions().x < object.getPosition().x + object.getDimensions().x };
	bool topCollides{ position.y > object.getPosition().y && position.y < object.getPosition().y + object.getDimensions().y };
	bool bottomCollides{ position.y + getDimensions().y > object.getPosition().y && position.y + getDimensions().y < object.getPosition().y + object.getDimensions().y };
	bool blockCollides{ (object.getPosition().y > position.y && object.getPosition().y < position.y + getDimensions().y) || (object.getPosition().y + object.getDimensions().y > position.y && object.getPosition().y + object.getDimensions().y < position.y + getDimensions().y) };

	bool sameColumn{ leftSideCollides || rightSideCollides };
	bool sameRow{ topCollides || bottomCollides || blockCollides };

	return (sameColumn && sameRow);
}

void AnimatedObject::updateSprite()
{
	currentAnimation++;
	currentAnimation %= sprites[state].size();
	currentSprite = sprites[state][currentAnimation];
}
