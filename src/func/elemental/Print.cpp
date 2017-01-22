#include "Print.hpp"

#include <iostream>
#include <misc/Debug.hpp>
#include <misc/Converter.hpp>

Print::Print()
{}

void Print::call(const Date& d)
{
	int i = 0;
	float f = 0.f;
	switch (d.getType())
	{
		case INT:
			d.get(i);
			std::cout << i << std::endl;
			break;
		case FLOAT:
			d.get(f);
			std::cout << f << std::endl;
			break;
		default:
			Debug::warn("Print::call(): Unknown Datatype = " + Converter::intToString(d.getType()));
	}
}
