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
	Enemy(std::string animationFile, Vector2D columnRow, const GUI* gui);


	void update(Object::Command command, const std::vector<Object*>& objects) override;

	Object* copyMe() override;

private:

};
#endif // !ENEMY_H
