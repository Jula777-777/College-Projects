#include "FactoryLibrary.h"
#include "ObjectFactory.h"

FactoryLibrary::FactoryLibrary()
{
	library[Object::Type::bridge_center] = new BlockFactory();
	library[Object::Type::bridge_end] = library[Object::Type::bridge_center];
	library[Object::Type::bridge_start] = library[Object::Type::bridge_center];
	library[Object::Type::center_block] = library[Object::Type::bridge_center];
	library[Object::Type::top_block] = library[Object::Type::bridge_center];
	library[Object::Type::tree_background] = library[Object::Type::bridge_center];
	library[Object::Type::water] = library[Object::Type::bridge_center];
	library[Object::Type::water_shore] = library[Object::Type::bridge_center];
	library[Object::Type::water_top] = library[Object::Type::bridge_center];
	library[Object::Type::water_wall] = library[Object::Type::bridge_center];
	library[Object::Type::water_wall_corner] = library[Object::Type::bridge_center];

	library[Object::Type::player] = new PlayerFactory();
	library[Object::Type::enemy] = new EnemyFactory();
	library[Object::Type::bullet] = new BulletFactory();

	library[Object::Type::heart] = new HeartFactory();

	library[Object::Type::tank] = new TankFactory();
	library[Object::Type::cannonball] = library[Object::Type::bullet];

	library[Object::Type::dragon] = new DragonFactory();
	library[Object::Type::fireball] = library[Object::Type::bullet];
}

FactoryLibrary::FactoryLibrary(const FactoryLibrary& src)
{
	for (auto iter{ src.library.begin() }; iter != src.library.end(); iter++)
	{
		this->library.insert(*iter);
	}
}

FactoryLibrary::FactoryLibrary(FactoryLibrary&& src)
{
	for (auto iter{ src.library.begin() }; iter != src.library.end(); iter++)
	{
		this->library.insert(*iter);
		iter->second = nullptr;
	}
	src.library.clear();
}

FactoryLibrary& FactoryLibrary::operator=(const FactoryLibrary& src) noexcept
{
	for (auto iter{ this->library.begin() }; iter != this->library.end(); iter++)
	{
		if (iter->second != nullptr)
		{
			delete iter->second;
		}
	}
	this->library.clear();

	for (auto iter{ src.library.begin() }; iter != src.library.end(); iter++)
	{
		this->library.insert(*iter);
	}

	return *this;
}

FactoryLibrary& FactoryLibrary::operator=(FactoryLibrary&& src) noexcept
{
	for (auto iter{ this->library.begin() }; iter != this->library.end(); iter++)
	{
		if (iter->second != nullptr)
		{
			delete iter->second;
		}
	}
	this->library.clear();

	for (auto iter{ src.library.begin() }; iter != src.library.end(); iter++)
	{
		this->library.insert(*iter);
		iter->second = nullptr;
	}
	src.library.clear();

	return *this;
}

FactoryLibrary::~FactoryLibrary()
{
	for (auto iter{ library.begin() }; iter != library.end(); iter++)
	{
		delete iter->second;
	}
}
