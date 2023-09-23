#ifndef OBJECTFACTORY_H

#include "Object.h"
class GUI;
class Player;

static Player* player{ nullptr };

struct Initialilzers
{
	Initialilzers(const GUI* gui, std::vector<Object*> objects) :gui(gui), objects(objects){}
	Vector2D position{ 0,0 };
	Object::Type name{ Object::Type::none };
	const GUI* gui;
	std::vector<Object*> objects;
	Object* creator{ nullptr };
};
class ObjectFactory
{
public:
	virtual Object* create(Initialilzers list) = 0;
};

class BlockFactory :
	public ObjectFactory
{
public:
	Object* create(Initialilzers list) override;
};

class PlayerFactory :
	public ObjectFactory
{
public:
	Object* create(Initialilzers list) override;
};

class EnemyFactory :
	public ObjectFactory
{
public:
	Object* create(Initialilzers list) override;
};

class BulletFactory :
	public ObjectFactory
{
public:
	Object* create(Initialilzers list) override;
};

class HeartFactory :
	public ObjectFactory
{
public:
	Object* create(Initialilzers list) override;
};

class TankFactory :
	public ObjectFactory
{
public:
	Object* create(Initialilzers list) override;
};

class DragonFactory :
	public ObjectFactory
{
public:
	Object* create(Initialilzers list) override;
};

#endif // !OBJECTFACTORY_H