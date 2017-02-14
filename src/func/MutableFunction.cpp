#include "MutableFunction.hpp"

#include <misc/Debug.hpp>
#include <misc/Converter.hpp>

MutableFunction::MutableFunction(const DataPattern& p)
	: parameterPattern_(p), stackSize_(getStackPattern().getBytesSize())
{}

MutableFunction::~MutableFunction()
{
	caller_.clear();
}

void MutableFunction::call(const Data& d)
{
	for (unsigned int i = 0; i < caller_.size(); i++)
	{
		caller_[i].call(d);
	}
}

ErrorCode MutableFunction::addFunction(Function* func, const DataMask& funcMask)
{
	ErrorCode errorCode = checkAddFunction(func, funcMask);
	if (errorCode)
	{
		return errorCode;
	}
	caller_.push_back(Caller(func, funcMask));
	return ErrorCode::NONE;
}

bool MutableFunction::validIndex(unsigned int index)
{
	return (index >= 0) && (index < caller_.size());
}

bool MutableFunction::removeFunction(unsigned int index)
{
	if (!validIndex(index))
	{
		return false;
	}

	caller_.erase(caller_.begin()+index);
	return true;
}

DataPattern MutableFunction::getParameterPattern() const
{
	return parameterPattern_;
}

DataPattern MutableFunction::getStackPattern() const
{
	return getParameterPattern();
}

ErrorCode MutableFunction::checkAddFunction(Function* func, const DataMask& funcMask) const
{
	// check valid mask
	if (funcMask.getSize() != func->getParameterPattern().getSize())
	{
		return ErrorCode::WRONG_PARAMETER_SIZE;
	}
	for (unsigned int i = 0; i < funcMask.getSize(); i++)
	{
		DataType stackType = getStackPattern().getTypeAt(funcMask.getOffset(i));
		DataType paramType = func->getParameterPattern()[i];
		if (!matches(stackType, paramType))
		{
			return ErrorCode::TYPE_MISMATCH;
		}
	}
	return ErrorCode::NONE;
}
