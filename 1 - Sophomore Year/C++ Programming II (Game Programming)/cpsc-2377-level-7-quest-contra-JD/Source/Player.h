#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>

#include "AnimatedObject.h"

class GUI;
class Block;
class Enemy;
class Player: public AnimatedObject
{
public:
	Player() = delete;
	Player(std::string animationFile, Vector2D position, const GUI* gui);


	Object* update(Object::Command command, const std::vector<Object*>& objects, FactoryLibrary* factories) override;
	virtual Object* copyMe() override;

	void attach(Enemy* enemy);
	void detach(Enemy* enemy);
	void notify();
	
private:
	std::vector<Enemy*> enemiesToNotify;


	
};
#endif // !PLAYER_H
