#include <fstream>
#include <iostream>
#include "AnimatedObject.h"
#include "Block.h"
#include "GUI.h"
using namespace std;
const Vector2D AnimatedObject::gravity{ 0.0f, 10.0f };
const float AnimatedObject::deltaT{ 0.5f };
const Vector2D AnimatedObject::terminalVelocity{ 0.0f, 50.0f };
AnimatedObject::AnimatedObject(std::string animationFile, Vector2D columnRow, Type name, const GUI* gui) : Object(position, name, gui)
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
void AnimatedObject::updateSprite()
{
	currentAnimation++;
	currentAnimation %= sprites[state].size();

	currentSprite = sprites[state][currentAnimation];
}
void AnimatedObject::doPhysics(const std::vector<Object*> objects)
{
	applyGravity();

	for (const auto& object : objects)
	{
		switch (object->getName())
		{
		case Object::Type::bridge_center:
		case Object::Type::bridge_end:
		case Object::Type::bridge_start:
		case Object::Type::top_block:
		case Object::Type::water_top:
			if (collision(object))
			{
				position.y = object->getPosition().y - gui->getDimensions(this).y;
				velocity.y = 0;
				if (state == AnimatedObject::State::jumpLeft)
				{
					state = AnimatedObject::State::stillLeft;
				}
				else if (state == AnimatedObject::State::jumpRight)
				{
					state = AnimatedObject::State::stillRight;
				}
			}
			break;
		}

	}
}

void AnimatedObject::applyGravity()
{
	position.y += deltaT * velocity.y;
	if (velocity.y <= terminalVelocity.y)
	{
		velocity.y += deltaT * gravity.y;
	}
}

bool AnimatedObject::collision(const Object* object, bool full)
{
	bool leftInColumn{ (position.x >= object->getPosition().x
				&& position.x <= object->getPosition().x + object->getDimensions().x) };
	bool rightInColumn{ (position.x + getDimensions().x >= object->getPosition().x
		&& position.x + getDimensions().x <= object->getPosition().x + object->getDimensions().x) };


	if (!full)
	{
		bool bottomInRow{ (position.y + getDimensions().y >= object->getPosition().y) && (position.y + getDimensions().y <= object->getPosition().y + gravity.y + 8) };

		bool sameColumn{ leftInColumn || rightInColumn };

		return sameColumn && bottomInRow && velocity.y >= 0;
	}

	bool topInRow{ (position.y >= object->getPosition().y
		&& position.y < object->getPosition().y + object->getDimensions().y) };
	bool bottomInRow{ (position.y + getDimensions().y > object->getPosition().y
		&& position.y + getDimensions().y <= object->getPosition().y + object->getDimensions().y) };
	bool objectTopInThis{ (object->getPosition().y > position.y
		&& object->getPosition().y < position.y + getDimensions().y) };

	bool sameColumn{ leftInColumn || rightInColumn };

	bool sameRow{ topInRow || bottomInRow || objectTopInThis };

	return sameRow && sameColumn;
}