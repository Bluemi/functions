#include "Print.hpp"

#include <iostream>

Print::Print()
{}

void Print::call(const Data& data)
{
	std::cout << std::endl << "hello World" << std::endl << std::endl;
}

DataPattern Print::getParamPattern() const
{
	return DataPattern();
}

DataPattern Print::getStackPattern() const
{
	return DataPattern();
}
