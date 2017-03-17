#include "MutableFunction.hpp"

#include <misc/Debug.hpp>
#include <misc/Converter.hpp>

MutableFunction::MutableFunction(const DataPattern& parameterPattern)
	: parameterPattern_(parameterPattern)
{
	stackSize_ = getStackPattern().getSize();
}

MutableFunction::~MutableFunction()
{
	for (Caller* c : caller_)
	{
		delete c;
	}
	caller_.clear();
}

void MutableFunction::call(Data& d) const
{
	for (unsigned int i = 0; i < caller_.size(); i++)
	{
		caller_[i]->call(d);
	}
}

AddErrorCode MutableFunction::addFunction(Function* func, const DataMask& funcMask)
{
	AddErrorCode errorCode = checkAddFunction(func, funcMask);
	if (errorCode)
	{
		return errorCode;
	}
	caller_.push_back(new FunctionCaller(func, funcMask));
	return AddErrorCode::NONE;
}

bool MutableFunction::validFunctionIndex(unsigned int index)
{
	return (index >= 0) && (index < caller_.size());
}

bool MutableFunction::removeFunction(unsigned int index)
{
	if (!validFunctionIndex(index))
	{
		return false;
	}

	std::vector<Caller*>::iterator c = caller_.begin()+index;
	caller_.erase(c);
	delete *c;
	return true;
}

void MutableFunction::addLocal(const DataType& type)
{
	localsPattern_ << type;
}

DataPattern MutableFunction::getParameterPattern() const
{
	return parameterPattern_;
}

DataPattern MutableFunction::getStackPattern() const
{
	return parameterPattern_ + localsPattern_;
}

AddErrorCode MutableFunction::checkAddFunction(Function* func, const DataMask& funcMask) const
{
	// check valid mask
	if (funcMask.getSize() != func->getParameterPattern().getSize())
	{
		return AddErrorCode::WRONG_PARAMETER_SIZE;
	}
	for (unsigned int i = 0; i < funcMask.getSize(); i++)
	{
		DataType stackType = getStackPattern().getTypeAt(funcMask[i]);
		DataType paramType = func->getParameterPattern()[i];
		if (!matches(stackType, paramType))
		{
			return AddErrorCode::TYPE_MISMATCH;
		}
	}
	return AddErrorCode::NONE;
}
