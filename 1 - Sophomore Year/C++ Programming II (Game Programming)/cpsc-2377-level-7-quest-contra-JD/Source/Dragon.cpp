#include <random>
#include "Dragon.h"
#include "FactoryLibrary.h"
#include "ObjectFactory.h"

Dragon::Dragon(Vector2D position, Type name, const GUI* gui): AnimatedObject("./Assets/data/noAnimation.txt", position, name, gui)
{
	life = 1;
}

Object* Dragon::update(Object::Command command, const std::vector<Object*>& objects, FactoryLibrary* factories)
{
	Object* fireball{ nullptr };

	if (life <= 0)
	{
		kill();
	}

	std::random_device seed;
	std::default_random_engine e(seed());
	std::bernoulli_distribution shootChance(0.1);

	if (shootChance(e) == 1)
	{
		Initialilzers list(gui, objects);
		list.creator = this;
		list.name = Type::fireball;
		fireball = factories->library[list.name]->create(list);
	}

	return fireball;
}

Object* Dragon::copyMe()
{
	return new Dragon(*this);
}
