#include "AddErrorCode.hpp"

#include <misc/Debug.hpp>
#include <misc/Converter.hpp>

std::string getString(const AddErrorCode code)
{
	switch (code)
	{
		case NONE:
			return "NONE";
		case WRONG_PARAMETER_SIZE:
			return "WRONG_PARAMETER_SIZE";
		case TYPE_MISMATCH:
			return "TYPE_MISMATCH";
		case MUTATE_WHILE_RUNNING:
			return "MUTATE_WHILE_RUNNING";
		default:
			Debug::warn("ErrorCode::getString(): default block");
			break;
	}
	Debug::warn("ErrorCode::getString(): invalid code");
	return "INVALID CODE";
}
