#ifndef BULLET_H
#include "AnimatedObject.h"
class Bullet : public AnimatedObject
{
public:
	Bullet() = delete;
	Bullet(Vector2D position, Object* shooter, Vector2D target, const GUI* gui, Object::Type name);
	Object* update(Object::Command command, const std::vector<Object*>& objects, FactoryLibrary* factories) override;
	virtual Object* copyMe() override;
	const Object* shooter{ nullptr };
private:
	const int speed{ 20 };
	

};
#endif // !BULLET_H
