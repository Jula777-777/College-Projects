#ifndef DRAGON_H
#define DRAGON_H
#include "AnimatedObject.h"
class Dragon : public AnimatedObject
{
public:
	Dragon() = delete;
	Dragon(Vector2D position, Type name, const GUI* gui);

	Object* update(Object::Command command, const std::vector<Object*>& objects, FactoryLibrary* factories) override;
	virtual Object* copyMe() override;
};

#endif

