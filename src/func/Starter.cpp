#include "Starter.hpp"

#include <misc/Debug.hpp>

Starter::Starter(Function* f)
	: function_(f)
{}

StartErrorCode Starter::start()
{
	if (!DataPattern::matches(function_->getParameterPattern(), dataPattern_))
	{
		return StartErrorCode::PARAMETER_TYPE_MISMATCH;
	}
	if (!data_.allocate(function_->getStackPattern().getBytesSize()))
		return StartErrorCode::DATA_ALLOC_FAIL;
	function_->call(data_);
	return StartErrorCode::START_NONE;
}
