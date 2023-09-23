#include "Bullet.h"

Bullet::Bullet(Vector2D position, Object* shooter, Vector2D target, const GUI* gui, Object::Type name): AnimatedObject("./Assets/data/noAnimation.txt", position, name, gui), shooter(shooter)
{
	if (name == Type::bullet)
	{
		life = 10;
	}
	else if (name == Type::cannonball)
	{
		life = 20;
	}
	else
	{
		life = 30;
	}
	velocity = position;
	velocity.target(target, speed);
}

Object* Bullet::update(Object::Command command, const std::vector<Object*>& objects, FactoryLibrary* factories)
{
	life--;
	if (life <= 0)
	{
		kill();
	}
	position += velocity;
	for (const auto& object : objects)
	{
		if (collision(object, true) && object != this && object != shooter)
		{
			switch (object->getName())
			{
			case Type::player:
				kill();
				((AnimatedObject*)object)->life--;
				break;
			case Type::enemy:
			case Type::tank:
			case Type::dragon:
				kill();
				if (shooter->getName() == Object::Type::player)
				{
					((AnimatedObject*)object)->life--;
				}
				break;
			case Type::bullet:
				kill();
				object->kill();
				break;
			case Object::Type::bridge_center:
			case Object::Type::bridge_end:
			case Object::Type::bridge_start:
			case Object::Type::water_top:
				kill();
				break;
			}
		}

	}
	return nullptr;
}

Object* Bullet::copyMe()
{
	return new Bullet(*this);
}
