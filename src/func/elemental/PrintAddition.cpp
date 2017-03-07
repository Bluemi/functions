#include "PrintAddition.hpp"

#include <iostream>

PrintAddition::PrintAddition()
	: ElementalFunction(DataPattern() << INT << INT)
{}

void PrintAddition::call(const Data& data) const
{
	const int a = data.getAt<int>(0);
	const int b = data.getAt<int>(4);
	std::cout << a << "+" << b << "=" << (a+b) << std::endl;
}
