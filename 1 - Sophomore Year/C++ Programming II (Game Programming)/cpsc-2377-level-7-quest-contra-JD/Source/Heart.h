#ifndef HEART_H
#define HEART_H
#include "Object.h"
class Heart : public Object
{
public:
	Heart() = delete;
	Heart(Vector2D position, Type name, const GUI* gui);

	Object* update(Object::Command command, const std::vector<Object*>& objects, FactoryLibrary* factories) override { return nullptr; }
	Object* copyMe() override;

};

#endif