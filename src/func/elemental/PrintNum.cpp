#include "PrintNum.hpp"

#include <iostream>

PrintNum::PrintNum()
{}

void PrintNum::call(const Data& data)
{
	int i = data.getIntAt(0);
	std::cout << std::endl << i << std::endl << std::endl;
}

DataPattern PrintNum::getParamPattern() const
{
	DataPattern p;
	p.addType(DataType::INT);
	return p;
}

DataPattern PrintNum::getStackPattern() const
{
	return DataPattern();
}
