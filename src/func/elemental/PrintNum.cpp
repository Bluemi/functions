#include "PrintNum.hpp"

#include <iostream>

PrintNum::PrintNum()
{}

void PrintNum::call(const Data& data)
{
	int i = data.getAt<int>(0);
	std::cout << i << std::endl;
}

DataPattern PrintNum::getParameterPattern() const
{
	DataPattern p;
	p << DataType::INT;
	return p;
}

DataPattern PrintNum::getStackPattern() const
{
	return DataPattern();
}
