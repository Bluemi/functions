#include "Print.hpp"

#include <iostream>
#include <misc/Debug.hpp>
#include <misc/Converter.hpp>

Print::Print()
{}

void Print::call(const Data& data)
{
	int i = 0;
	float f = 0.f;
	Date d = data.getDate(0);
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
		case ERROR:
			Debug::warn("Print::call(): Datatype: ERROR");
			break;
		default:
			Debug::warn("Print::call(): Unknown Datatype = " + Converter::intToString(d.getType()));
	}
}
