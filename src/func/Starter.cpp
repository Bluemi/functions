#include "Starter.hpp"

#include <misc/Debug.hpp>

Starter::Starter(Function* f)
	: function(f)
{}

StartErrorCode Starter::start()
{
	if (!DataPattern::matches(function->getParameterPattern(), dataPattern))
	{
		return StartErrorCode::PARAMETER_TYPE_MISMATCH;
	}
	if (!data.allocate(function->getStackPattern().getBytesSize()))
		return StartErrorCode::DATA_ALLOC_FAIL;
	function->call(data);
	return StartErrorCode::START_NONE;
}
