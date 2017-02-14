#include "Caller.hpp"

Caller::Caller(Function* f, const DataMask& m)
	: func_(f), mask_(m)
{}

Caller::~Caller()
{}

void Caller::call(const Data& data)
{
	// Stack initialisieren
	Data newStack(func_->getStackSize());
	for (unsigned int i = 0; i < func_->getParameterPattern().getSize(); i++)
	{
		newStack.copyFrom(data, mask_.getOffset(i), getTypeSize(func_->getParameterPattern()[i]));
	}
	func_->call(newStack);
}
