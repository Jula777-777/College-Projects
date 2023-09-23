#include <random>
#include "Tank.h"
#include "FactoryLibrary.h"
#include "ObjectFactory.h"

Tank::Tank(Vector2D position, Type name, const GUI* gui): AnimatedObject("./Assets/data/noAnimation.txt", position, name, gui)
{
	life = 1;
}

Object* Tank::update(Object::Command command, const std::vector<Object*>& objects, FactoryLibrary* factories)
{
	Object* cannonball{ nullptr };

	if (life <= 0)
	{
		kill();
	}

	std::random_device seed;
	std::default_random_engine e(seed());
	std::bernoulli_distribution shootChance(0.05);

	if (shootChance(e) == 1)
	{
		Initialilzers list(gui, objects);
		list.creator = this;
		list.name = Type::cannonball;
		cannonball = factories->library[list.name]->create(list);
	}

	return cannonball;
}

Object* Tank::copyMe()
{
	return new Tank(*this);
}
