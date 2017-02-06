#include "MutableFunction.hpp"

MutableFunction::MutableFunction(const DataPattern& p)
	: pattern(p)
{}

MutableFunction::~MutableFunction()
{
	caller.clear();
}

void MutableFunction::call(const Data& d)
{
	for (unsigned int i = 0; i < caller.size(); i++)
	{
		caller[i].call(d);
	}
}

void MutableFunction::addFunction(Function* func, const DataMask& funcMask)
{
	// check valid mask
	if (funcMask.getSize() != func->getParamPattern().getSize())
	{
		// ERROR
		return;
	}
	for (unsigned int i = 0; i < funcMask.getSize(); i++)
	{
		DataType stackType = getStackPattern().getTypeAt(funcMask.getOffset(i));
		DataType paramType = func->getParamPattern()[i];
		if (stackType == DataType::UNDEFINED || paramType == DataType::UNDEFINED)
		{
			// ERROR
			return;
		}
		if (stackType != paramType)
		{
			// ERROR
			return;
		}
	}
	caller.push_back(Caller(func, funcMask));
}

bool MutableFunction::validIndex(unsigned int index)
{
	return (index >= 0) && (index < caller.size());
}

bool MutableFunction::removeFunction(unsigned int index)
{
	if (!validIndex(index))
	{
		return false;
	}

	caller.erase(caller.begin()+index);
	return true;
}

DataPattern MutableFunction::getParamPattern() const
{
	return pattern;
}

DataPattern MutableFunction::getStackPattern() const
{
	return getParamPattern();
}
