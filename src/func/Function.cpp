#include "Function.hpp"

Function::Function()
{}

Function::~Function()
{}

unsigned int Function::getStackSize() const
{
	return getStackPattern().getBytesSize();
}
