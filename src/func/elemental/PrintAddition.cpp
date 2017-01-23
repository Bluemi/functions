#include "PrintAddition.hpp"

#include <iostream>

#include <misc/Debug.hpp>
#include <misc/Converter.hpp>

PrintAddition::PrintAddition()
{}

void PrintAddition::call(const Data& d)
{
	Date a = d.getDate(0);
	Date b = d.getDate(1);

	if (a.getType() != b.getType())
	{
		Debug::warn("PrintAddition::call(): a.getType() != b.getType()");
	}

	int aInt = 0;
	int bInt = 0;
	float aFloat = 0.f;
	float bFloat = 0.f;

	switch (a.getType())
	{
		case INT:
			a.get(aInt);
			b.get(bInt);
			std::cout << (aInt + bInt) << std::endl;
			break;
		case FLOAT:
			a.get(aFloat);
			b.get(bFloat);
			std::cout << (aFloat + bFloat) << std::endl;
			break;
		case ERROR:
			Debug::warn("PrintAddition::call(): a.getType() = ERROR");
			break;
		default:
			Debug::warn("PrintAddition::call(): a.getType(): Unknown DataType = " + Converter::intToString(a.getType()));
			break;
	}
}
