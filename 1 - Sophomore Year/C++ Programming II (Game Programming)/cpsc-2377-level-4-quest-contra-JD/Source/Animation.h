#ifndef ANIMATION_H
#define ANIMATION_H
#include <map>
#include <vector>
#include <string>

class Animation
{
public:
	Animation(std::string animationFile);
	void updateSprite();
	
	enum class State { stillLeft, stillRight, walkLeft, walkRight, crouchLeft, crouchRight };
	enum class Command { up, down, left, right, attack, NA };
	
	const int playerWalkSpeed{ 12 };
	const int enemyWalkSpeed{ 5 };
	State getState() const;
	void setState(State newState);
	int getSprite() const;
private:
	int currentSprite{ 0 };
	int currentAnimation{ 0 };
	State state{ State::stillRight };
	//Find correct vector using state, use currentAnimation to find currentSprite in vector.
	//When accessing, can be treated like a two dimensional array.
	std::map<State, std::vector<int>> sprites;

	
};
#endif // !ANIMATION_H
