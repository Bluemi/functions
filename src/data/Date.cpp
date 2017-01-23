#include "Date.hpp"

#include <misc/Debug.hpp>
#include <misc/Converter.hpp>

Date::Date(float f)
	: d(FLOAT)
{
	p.f = f;
}

Date::Date(int i)
	: d(INT)
{
	p.i = i;
}

Date::Date()
	: d(ERROR)
{
	p.i = 0;
}

Datatype Date::getType() const
{
	return d;
}

bool Date::get(int& i) const
{
	if (getType() == INT)
	{
		i = p.i;
		return true;
	}
	Debug::warn("Date::get(int): tries to get Datatype " + Converter::intToString(INT) + " but current Datatype is " + Converter::intToString(getType()));
	return false;
}

bool Date::get(float& f) const
{
	if (getType() == FLOAT)
	{
		f = p.f;
		return true;
	}
	Debug::warn("Date::get(int): tries to get Datatype " + Converter::intToString(FLOAT) + " but current Datatype is " + Converter::intToString(getType()));
	return false;
}
