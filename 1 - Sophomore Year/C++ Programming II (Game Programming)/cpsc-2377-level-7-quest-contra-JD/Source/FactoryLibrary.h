#ifndef FACTORYLIBRARY_H



#include <map>

#include "Object.h"
class ObjectFactory;
class FactoryLibrary
{
public:
	FactoryLibrary();
	FactoryLibrary(const FactoryLibrary& src);
	FactoryLibrary(FactoryLibrary&& src);
	FactoryLibrary& operator=(const FactoryLibrary& src) noexcept;
	FactoryLibrary& operator=(FactoryLibrary&& src) noexcept;
	~FactoryLibrary();

	std::map<Object::Type, ObjectFactory*> library;
};

#endif // !FACTORYLIBRARY_H