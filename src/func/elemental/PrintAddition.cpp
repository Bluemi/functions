#include "PrintAddition.hpp"

#include <iostream>

PrintAddition::PrintAddition()
	: ElementalFunction(DataPattern() << INT << INT, DataPattern())
{}

void PrintAddition::call(Data& stack, Data* returnValues) const
{
	const int a = stack.getAt<int>(0);
	const int b = stack.getAt<int>(4);
	std::cout << a << "+" << b << "=" << (a+b) << std::endl;
}
