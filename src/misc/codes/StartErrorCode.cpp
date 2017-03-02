#include "StartErrorCode.hpp"

#include <misc/Debug.hpp>
#include <misc/Converter.hpp>

std::string getString(const StartErrorCode code)
{
	switch (code)
	{
		case START_NONE:
			return "START_NONE";
		case PARAMETER_TYPE_MISMATCH:
			return "PARAMETER_TYPE_MISMATCH";
		case DATA_ALLOC_FAIL:
			return "DATA_ALLOC_FAIL";
		default:
			Debug::warn("StartErrorCode::getString(): default block");
			break;
	}
	Debug::warn("StartErrorCode::getString(): invalid code");
	return "INVALID CODE";
}
