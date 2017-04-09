#include "Print.hpp"

#include <iostream>

Print::Print()
	: ElementalFunction(DataPattern(), DataPattern())
{}

void Print::call(Data& stack, Data* returnValues) const
{
	std::cout << std::endl << "hello World" << std::endl << std::endl;
}
