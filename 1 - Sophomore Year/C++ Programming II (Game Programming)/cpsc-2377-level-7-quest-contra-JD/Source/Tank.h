#ifndef TANK_H
#define TANK_H
#include "AnimatedObject.h"
class Tank : public AnimatedObject
{
public:
	Tank() = delete;
	Tank(Vector2D position, Type name, const GUI* gui);

	Object* update(Object::Command command, const std::vector<Object*>& objects, FactoryLibrary* factories) override;
	virtual Object* copyMe() override;
};

#endif

