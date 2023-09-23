#include <fstream>
#include <iostream>
#include "Animation.h"
using namespace std;

Animation::Animation(std::string animationFile)
{
	ifstream fin;
	fin.open(animationFile);

	if (!fin.is_open())
	{
		cout << "Error opening file.\n";
	}

	int numOfStates;
	fin >> numOfStates;

	for (int i{ 0 }; i < numOfStates; i++)
	{
		int numOfAnimations;
		fin >> numOfAnimations;

		for (int j{ 0 }; j < numOfAnimations; j++)
		{
			int tempSprite;
			fin >> tempSprite;

			sprites[(Animation::State)i].push_back(tempSprite);
		}
	}
	fin.close();
}

void Animation::updateSprite()
{
	currentAnimation++;
	currentAnimation %= sprites[state].size();
	currentSprite = sprites[state][currentAnimation];
}

Animation::State Animation::getState() const
{
	return state;
}

void Animation::setState(State newState)
{
	state = newState;
}

int Animation::getSprite() const
{
	return currentSprite;
}
