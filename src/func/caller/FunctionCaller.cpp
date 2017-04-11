#include "FunctionCaller.hpp"

FunctionCaller::FunctionCaller(Function* f, const DataMapping& pMapping, const DataMapping& rMapping)
	: func_(f), parameterMapping_(pMapping), returnMapping_(rMapping)
{}

FunctionCaller::~FunctionCaller()
{}

void FunctionCaller::call(Data& data)
{
	// initialize Stack
	Data newStack(func_->getStackSize());
	// fill Parameter Values
	for (unsigned int i = 0; i < func_->getParameterPattern().getSize(); i++)
	{
		newStack.addDataFrom(data, parameterMapping_[i], getTypeSize(func_->getParameterPattern()[i]));
	}
	// intialize returnValues_
	Data returnValues(func_->getReturnPattern().getBytesSize());
	// call
	func_->call(newStack, &returnValues);
	// apply return Values
	unsigned int returnValuesOffset = 0;
	for (unsigned int i = 0; i < func_->getReturnPattern().getSize(); i++)
	{
		const unsigned int size = getTypeSize(func_->getReturnPattern()[i]);
		data.copyFromAt(returnMapping_[i], returnValues, returnValuesOffset, size);
		returnValuesOffset += size;
	}
}
