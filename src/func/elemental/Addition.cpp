#include "Addition.hpp"

Addition::Addition()
	: ElementalFunction(DataPattern() << INT << INT, DataPattern() << INT)
{}

void Addition::call(Data& stack, Data* returnValues) const
{
	const int a = stack.getAt<int>(0);
	const int b = stack.getAt<int>(4);
	returnValues->setAt(a+b, 0);
}
