#include "Caller.hpp"

Caller::Caller(Function* f, const DataMask& m)
	: func_(f), mask_(m)
{}

Caller::~Caller()
{}

void Caller::call(const Data& data)
{
	// initialize Stack
	Data newStack(func_->getStackSize());
	// fill Parameter Values
	for (unsigned int i = 0; i < func_->getParameterPattern().getSize(); i++)
	{
		newStack.copyFrom(data, mask_[i], getTypeSize(func_->getParameterPattern()[i]));
	}
	func_->call(newStack);
}
