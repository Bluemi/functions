#include "Starter.hpp"

#include <misc/Debug.hpp>

Starter::Starter(Function* f)
	: function(f)
{}

ErrorCode Starter::start()
{
	if (!DataPattern::matches(function->getParameterPattern(), dataPattern))
	{
		return ErrorCode::TYPE_MISMATCH;
	}
	function->call(data);
	return ErrorCode::NONE;
}
