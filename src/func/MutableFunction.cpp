#include "MutableFunction.hpp"

#include <misc/Debug.hpp>
#include <misc/Converter.hpp>
#include <func/caller/FunctionCaller.hpp>

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

void MutableFunction::call(Data& stack, Data* returnValues) const
{
	for (unsigned int i = 0; i < caller_.size(); i++)
	{
		caller_[i]->call(stack);
	}

	// print Stack TEST
	whatIs(stack.getAt<int>(0));
	whatIs(stack.getAt<int>(4));
	whatIs(stack.getAt<int>(8));
}

AddErrorCode MutableFunction::addFunction(Function* func, const DataMapping& pMapping)
{
	AddErrorCode errorCode = checkAddFunction(func, pMapping);
	if (errorCode)
	{
		return errorCode;
	}
	caller_.push_back(new FunctionCaller(func, pMapping, DataMapping()));
	return AddErrorCode::NONE;
}

AddErrorCode MutableFunction::addFunction(Function* func, const DataMapping& pMapping, const DataMapping& rMapping)
{
	AddErrorCode errorCode = checkAddFunction(func, pMapping, rMapping);
	if (errorCode)
	{
		return errorCode;
	}
	caller_.push_back(new FunctionCaller(func, pMapping, rMapping));
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

DataPattern MutableFunction::getReturnDataPattern() const
{
	return returnDataPattern_;
}

AddErrorCode MutableFunction::checkAddFunction(Function* func, const DataMapping& pMapping) const
{
	// check valid mapping
	if (pMapping.getSize() != func->getParameterPattern().getSize())
	{
		return AddErrorCode::WRONG_PARAMETER_SIZE;
	}
	for (unsigned int i = 0; i < pMapping.getSize(); i++)
	{
		const DataType stackType = getStackPattern().getTypeAt(pMapping[i]);
		const DataType paramType = func->getParameterPattern()[i];
		if (!matches(stackType, paramType))
		{
			return AddErrorCode::TYPE_MISMATCH;
		}
	}
	return AddErrorCode::NONE;
}

AddErrorCode MutableFunction::checkAddFunction(Function* func, const DataMapping& pMapping, const DataMapping& rMapping) const
{
	AddErrorCode errorCode = checkAddFunction(func, pMapping);
	if (errorCode)
	{
		return errorCode;
	}

	if (rMapping.getSize() != func->getReturnDataPattern().getSize())
	{
		return AddErrorCode::WRONG_PARAMETER_SIZE;
	}
	for (unsigned int i = 0; i < rMapping.getSize(); i++)
	{
		const DataType stackType = getStackPattern().getTypeAt(rMapping[i]);
		const DataType returnType = func->getReturnDataPattern()[i];
		if (!matches(stackType, returnType))
		{
			return AddErrorCode::TYPE_MISMATCH;
		}
	}
	return AddErrorCode::NONE;
}
