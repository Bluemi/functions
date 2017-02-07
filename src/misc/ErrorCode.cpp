#include "ErrorCode.hpp"

#include "Debug.hpp"
#include "Converter.hpp"

std::string getString(const ErrorCode code)
{
	switch (code)
	{
		case NONE:
			return "NONE";
		case WRONG_PARAMETER_SIZE:
			return "WRONG_PARAMETER_SIZE";
		case TYPE_MISMATCH:
			return "TYPE_MISMATCH";
		default:
			Debug::warn("ErrorCode::getString(): default block");
			break;
	}
	Debug::warn("ErrorCode::getString(): invalid code");
	return "INVALID CODE";
}
