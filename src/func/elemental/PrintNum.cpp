#include "PrintNum.hpp"

#include <iostream>

PrintNum::PrintNum()
	: ElementalFunction(DataPattern() << INT)
{}

void PrintNum::call(const Data& data) const
{
	int i = data.getAt<int>(0);
	std::cout << i << std::endl;
}
