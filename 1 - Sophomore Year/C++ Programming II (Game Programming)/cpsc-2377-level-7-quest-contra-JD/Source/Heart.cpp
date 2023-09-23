#include "Heart.h"

Heart::Heart(Vector2D position, Type name, const GUI* gui): Object(position, name, gui)
{

}


Object* Heart::copyMe()
{
	return new Heart(*this);
}
