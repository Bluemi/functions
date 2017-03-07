#include "PrintAddition.hpp"

#include <iostream>

PrintAddition::PrintAddition()
{}

void PrintAddition::call(const Data& data) const
{
	const int a = data.getAt<int>(0);
	const int b = data.getAt<int>(4);
	std::cout << a << "+" << b << "=" << (a+b) << std::endl;
}

DataPattern PrintAddition::getParameterPattern() const
{
	DataPattern p;
	p << DataType::INT << DataType::INT;
	return p;
}

DataPattern PrintAddition::getStackPattern() const
{
	return DataPattern();
}
