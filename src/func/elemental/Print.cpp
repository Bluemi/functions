#include "Print.hpp"

#include <iostream>

Print::Print()
	: ElementalFunction(DataPattern())
{}

void Print::call(Data& data) const
{
	std::cout << std::endl << "hello World" << std::endl << std::endl;
}
