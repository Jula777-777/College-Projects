#include "Object.h"
#include "GUI.h"

using namespace std;

Object::Object(Vector2D position, Type name, const GUI* gui) : position(position), name(name), gui(gui) {}

Vector2D Object::getPosition() const
{
	return position;
}

void Object::setPosition(Vector2D newPosition)
{
	position = newPosition;
}

Vector2D Object::getDimensions() const
{
	return gui->getDimensions(this);
}

Object::Type Object::getName() const
{
	return name;
}
