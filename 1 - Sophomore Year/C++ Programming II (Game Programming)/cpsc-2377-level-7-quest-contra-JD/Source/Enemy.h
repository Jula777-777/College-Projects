#ifndef ENEMY_H
#define ENEMY_H
#include "Object.h"
#include "AnimatedObject.h"

class GUI;
class Player;
class Enemy :public AnimatedObject
{
public:
	Enemy() = delete;
	Enemy(std::string animationFile, Vector2D position, const GUI* gui, Player* player);


	Object* update(Object::Command command, const std::vector<Object*>& objects, FactoryLibrary* factories) override;
	virtual Object* copyMe() override;

	void notify(Player* player);

private:
	Player* attachedPlayer{ nullptr };
};
#endif // !ENEMY_H
