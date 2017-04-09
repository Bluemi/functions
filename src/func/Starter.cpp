#include "Starter.hpp"

#include <misc/Debug.hpp>

Starter::Starter(Function* f)
	: function_(f)
{}

StartErrorCode Starter::start()
{
	// Check Parameter Types
	if (!DataPattern::matches(function_->getParameterPattern(), dataPattern_))
	{
		return StartErrorCode::PARAMETER_TYPE_MISMATCH;
	}
	// allocate Stack
	if (!data_.allocate(function_->getStackPattern().getBytesSize()))
		return StartErrorCode::DATA_ALLOC_FAIL;
	// initiate returnValues
	returnValues_.allocate(function_->getReturnDataPattern().getBytesSize());
	// call
	function_->call(data_, &returnValues_);
	return StartErrorCode::START_NONE;
}

const Data& Starter::getReturnValues() const
{
	return returnValues_;
}
