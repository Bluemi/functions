#include "PrintNum.hpp"

#include <iostream>

PrintNum::PrintNum()
	: ElementalFunction(DataPattern() << INT, DataPattern())
{}

void PrintNum::call(Data& stack, Data* returnValues) const
{
	int i = stack.getAt<int>(0);
	std::cout << i << std::endl;
}
